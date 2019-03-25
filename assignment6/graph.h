//
// Created by jinqiu on 2019/3/13.
//

#ifndef TESK_GRAPH_H
#define TESK_GRAPH_H

#include <vector>
#include <algorithm>

#include "utils.h"
#include "queue.h"

#define INF (~(0x1<<31))

template <class T>
class Graph
{
public:
    virtual ~Graph(){}

    //返回图的顶点数
    virtual int number_of_vertices() =0;
    //返回图的边数
    virtual int number_of_Edge()=0;
    //判断边（i,j）是否存在
    virtual bool exits_edge(int i,int j)=0;
    //插入边（i,j）
    virtual void insert_edge(const Edge<T> &edge)=0;
    //删除边
    virtual void erase_edge(int i, int j)=0;
    //返回顶点的度（只适用于无向图）
    virtual int degree(const int &top)=0;
    //返回顶点的入度
    virtual int in_degree(const int &top)=0;
    //返回顶点的出度
    virtual int out_degree(const int &top)=0;

    //有向图时返回true
    virtual bool directed()=0;
    //加权图时返回true
    virtual bool weighted()=0;
    //访问指定顶点的相邻顶点
    virtual VertexIterator<T> *iterator(int)=0;

public:
    /*******************************************
    *                  图的遍历                  *
    /*******************************************/
    //广度优先遍历
    virtual vector<T> bfs(int v)
    {
        vector<T> reach;
        ArrayQueue<int> q(10);
        reach.push_back(v);

        q.push(v);
        while(!q.empty()){
            //从队列中删除一个顶点
            int w=q.front();
            q.pop();

            //标记所有没有到达的邻接于顶点w的顶点
            VertexIterator<T> *iw=iterator(w);
            int u;
            //访问顶点w相邻顶点
            while ((u=iw->next())!=0){
                //u为没有到达过的顶点
                if(find(reach.begin(),reach.end(),u)==reach.end()){
                    q.push(u);
                    reach.push_back(u);
                }
            }
            delete iw;
        }

        return reach;
    }
    
    //深度优先遍历
    virtual vector<T> dfs(int v)
    {
        vector<T> reach;
        rdfs(v,reach);

        return reach;
    }

    //递归深度优先遍历
    void rdfs(int v,vector<T> &reach)
    {
        reach.push_back(v);
        VertexIterator<T> *iw=iterator(v);
        int u=0;
        //访问v的相邻顶点
        while((u=iw->next())!=0){
            //如果U是一个未遍历的顶点
            if(find(reach.begin(),reach.end(),u)==reach.end()){
                rdfs(u,reach);
            }
        }
        delete iw;
    }

    /*******************************************
    *                  最优路径                  *
    /*******************************************/
    //Dijkstra算法
    virtual vector<T> dijkstra(int v)
    {
        VertexIterator<T> *iw=iterator(v);
        int top_size=iw->get_vertex_size(); //获取图中顶点的个数

        bool *flag=new bool[top_size];      //定义当前顶点的访问状态
        T *dist=new T[top_size];            //定义存储最小距离
        vector<vector<int>> path;           //定义存储最小路径

        //初始化状态数组
        fill(flag,flag+top_size, false);
        flag[v]= true;
        //初始化最小路径
        path.resize(top_size);
        //初始化距离数组
        vector<T> theRow=iw->get_adjacent_vertex();
        for(int i=0;i<top_size;++i){
            if(theRow[i]!=0){
                dist[i]=theRow[i];

                path[i].push_back(v);
                path[i].push_back(i);
            } else{
                dist[i]=INF;
            }
        }
        dist[v]=0;

        for(int i=0;i<top_size;++i){
            //寻找当前节点最小的边
            T min=INF;
            int index=0;
            for(int j=0;j<top_size;++j){
                if(!flag[j] && dist[j]<min){
                    min=dist[j];
                    index=j;
                }
            }

            //标记最小边对应的顶点
            flag[index]= true;

            //更新dist中各个顶点到起点s的距离
            for(int k=0;k<top_size;++k){
                //获取与当前最小顶点相连接边
                iw=iterator(index);
                theRow=iw->get_adjacent_vertex();

                //更新起始点到各个顶点的距离
                if(!flag[k] && theRow[k]!=0 && theRow[k]+min<dist[k]){
                    dist[k]=min+theRow[k];

                    path[k].resize(path[index].size());
                    copy(path[index].begin(),path[index].end(),path[k].begin());
                    path[k].push_back(k);
                }
            }
        }

        vector<T> distance(dist,dist+top_size);

        if(flag){
            delete []flag;
            flag= nullptr;
        }
        if(dist){
            delete []dist;
            dist= nullptr;
        }

        for(auto it=path.begin();it!=path.end();++it){
            for(auto &c:*it){
                cout<<c<<"->"<<" ";
            }
            cout<<endl;
        }

        return distance;
    }
};

#endif //TESK_GRAPH_H
