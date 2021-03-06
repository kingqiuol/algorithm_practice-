//
// Created by jinqiu on 2019/3/13.
//

#ifndef TESK_GRAPH_H
#define TESK_GRAPH_H

#include <vector>
#include <algorithm>
#include <stdexcept>

#include "utils.h"
#include "queue.h"
#include "stack.h"

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
    virtual vector<int> bfs(int v)
    {
        vector<int> reach;
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
    virtual vector<int> dfs(int v)
    {
        vector<int> reach;
        rdfs(v,reach);

        return reach;
    }

private:
    //递归深度优先遍历
    void rdfs(int v,vector<int> &reach)
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

public:
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
                delete iw;
                iw= nullptr;
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
        if(iw){
            delete iw;
            iw= nullptr;
        }

        for(auto it=path.begin();it!=path.end();++it){
            for(auto &c:*it){
                cout<<c<<"->"<<" ";
            }
            cout<<endl;
        }

        return distance;
    }

    //Bellman-Ford算法
    virtual vector<T> bellman_ford(int v)
    {
        VertexIterator<T> *iw=iterator(v);
        int top_size=iw->get_vertex_size(); //获取图中顶点的个数

        bool flag=true;                     //定义是否存在负环
        T *dist=new T[top_size];            //定义存储最小距离
        //初始化距离数组
        for(int i=0;i<top_size;++i){
            if(i==v) {
                dist[i] = 0;
            }else{
                dist[i]=INF;
            }
        }

        //遍历每一个顶点
        for(int i=1;i<top_size-1;++i){
            //遍历每一条边，并对每一条边进行松弛
            for(int j=0;j<top_size;++j){
                for(int k=0;k<top_size;++k){
                    if(j!=k && exits_edge(j,k)){
                        delete iw;
                        iw= nullptr;
                        iw=iterator(j);
                        vector<T> theRow=iw->get_adjacent_vertex();
                        if(dist[j]+theRow[k]<dist[k]){
                            dist[k]=dist[j]+theRow[k];
                        }
                    }
                }
            }
        }

        //检测图中是否有负权边形成了环
        for(int j=0;j<top_size;++j){
            for(int k=0;k<top_size;++k){
                if(j!=k && exits_edge(j,k)){
                    delete iw;
                    iw= nullptr;
                    iw=iterator(j);
                    vector<T> theRow=iw->get_adjacent_vertex();
                    if(dist[j]+theRow[k]<dist[k]){
                        flag= false;
                    }
                }
            }
        }

        vector<T> distance;
        if(flag){
            distance.resize(top_size);
            copy(dist,dist+top_size,distance.begin());
        }

        if(dist){
            delete []dist;
            dist= nullptr;
        }
        if(iw){
            delete iw;
            iw= nullptr;
        }

        return distance;
    }

    //SPFA算法
    virtual  vector<T> spfa(int v)
    {
        VertexIterator<T> *iw=iterator(v);
        int top_size=iw->get_vertex_size();     //获取图中顶点的个数

        bool *flag=new bool[top_size];          //定义当前顶点是否存在队列中
        int *in_queue_times=new int[top_size];  //记录每个顶点进入队列的次数
        T *dist=new T[top_size];                //定义存储最小距离
        vector<vector<int>> path;               //定义存储最小路径
        ListQueue<int> queue;                   //记录待松弛的顶点

        //初始化
        path.resize(top_size);
        for(int i=0;i<top_size;++i){
            flag[i]= false;
            in_queue_times[i]=0;
            if(i==v){
                dist[i]=0;
            } else{
                dist[i]=INF;
            }
        }
        int u;
        while((u=iw->next())!=0){
            path[u].push_back(v);
            path[u].push_back(u);
        }

        //从起点开始入队
        queue.push(v);
        flag[v]= true;
        ++in_queue_times[v];
        //进入队列
        while(!queue.empty()){
            //获取当前顶点的下一个顶点
            int cur=queue.pop();//将当前节点出队
            flag[cur]= false;
            delete iw;
            iw= nullptr;
            iw=iterator(cur);

            int next;
            while((next=iw->next())!=0){
                //松弛当前节点
                T weight=iw->get_weight(next);
                if(dist[cur]+weight<dist[next]) {
                    dist[next] = dist[cur] + weight;

                    //保存路径
                    if(cur!=v){
                        path[next].resize(path[cur].size());
                        copy(path[cur].begin(),path[cur].end(),path[next].begin());
                        path[next].push_back(next);
                    }

                    //如果下一个节点不在队列中,入队
                    if(!flag[next]) {
                        flag[next] = true;
                        ++in_queue_times[next];
                        queue.push(next);

                        //如果某个入队列的次数大于顶点数，那么说明这个图有环，
                        if (in_queue_times[next] > top_size) {
                            return vector<T>();
                        }
                    }
                }
            }
        }

        vector<T> distance(dist,dist+top_size);

        if(iw){
            delete iw;
            iw= nullptr;
        }
        if(flag){
            delete[] flag;
            flag = nullptr;
        }
        if(in_queue_times){
            delete[] in_queue_times;
            in_queue_times= nullptr;
        }
        if(dist){
            delete[] dist;
            dist= nullptr;
        }

        for(auto it=path.begin();it!=path.end();++it){
            for(auto &c:*it){
                cout<<c<<" -> ";
            }
            cout<<endl;
        }

        return distance;
    }

    //Floyd-Warshall算法
    virtual vector<T> floyd()
    {
        //创建初始邻接矩阵
        int top_size=number_of_vertices();
        vector<T> adj(top_size*top_size);

        //初始化最短路径的矩阵
        VertexIterator<T> *iw= nullptr;
        vector<T> theRow;
        for(int i=0;i<top_size;++i){
            iw=iterator(i);
            theRow=iw->get_adjacent_vertex();
            copy(theRow.begin(),theRow.end(),adj.begin()+i*top_size);
            delete iw;
            iw= nullptr;
        }
        //将不存在的边置为INF
        for(auto &c:adj){
            if(c==0){
                c=INF;
            }
        }

        // 计算最短路径
        for(int k=0;k<top_size;k++){
            for(int i=0;i<top_size;++i){
                for(int j=0;j<top_size;j++){
                    // 如果经过下标为k顶点路径比原两点间路径更短，则更新dist[i][j]
                    if(adj[i*top_size+k]+adj[k*top_size+j]<adj[i*top_size+j]){
                        adj[i*top_size+j]=adj[i*top_size+k]+adj[k*top_size+j];
                    }
                }
            }
        }

        return adj;
    }

public:
    /*******************************************
    *                  最小生成树                *
    /*******************************************/
    //克鲁斯卡尔（Kruskal）算法
    virtual void kruskal()
    {
        //构建边集数组
        vector<Edge<T>> edges;//边的集合
        VertexIterator<T> *iw;
        int top_size=number_of_vertices();
        for(int i=0;i<top_size;++i){
            iw=iterator(i);
            int next;
            while((next=iw->next())!=0){
                T weight=iw->get_weight(next);
                Edge<T> tmp(i,next,weight);
                edges.push_back(tmp);
            }

            delete iw;
            iw= nullptr;
        }
        //对边集进行排序
        sort(edges.begin(),edges.end(),
             [](Edge<T> a,Edge<T> b){return a.weight()<b.weight();});

        //创建并查集
        vector<int> parents(top_size,-1);

        //遍历边集
        T min_weight=0;
        int cnt=0;
        for(int i=0;i<edges.size();++i){
            Edge<T> edge=edges[i];

            //判断当前两个顶点是否在同一个树中
            int u=edge.index1_;
            int v=edge.index2_;
            int father1=find_root(parents,u);
            int father2=find_root(parents,v);
            //不在同一棵树中
            if( father1 != father2){
                min_weight+=edge.weight_;
                ++cnt;
                //将两棵树进行合并（按秩合并）
                //每次合并树时，总是将矮的树挂到高的树下，这种方式称为按秩合并
                parents[father1]=father2;
                cout<<edge.index1_<<"->"<<edge.index2_<<" ";
            }
        }
        cout<<endl;
        if(cnt<top_size-1) min_weight=0;
        cout<<"number of edges:"<<cnt<<endl;
        cout<<"min weights:"<<min_weight<<endl;
    }

    //普里姆(Prim)算法
    virtual void prim(int v)
    {
        int top_size=number_of_vertices();
        vector<T> low_weight(top_size,INF); //定义以i为终点的最小权重
        vector<int> parents(top_size,v);   //定义以i为终点边的父节点（起点）

        //初始化
        VertexIterator<T> *iw=iterator(v);
        int next;
        while((next=iw->next())!=0){
            low_weight[next]=iw->get_weight(next);//将v顶点与其他边的权值存入vector
        }
        low_weight[v]=0;    //初始化起点为终点的权重
        parents[v]=-1;       //初始化起点的父节点为-1

        T min_weights=0;
        int cnt=0;
        for(int i=1;i<top_size;++i){

            T min_weight=INF;
            int min_index=0;
            //获取当前节点最小边和指向的顶点
            for(int k=0;k<top_size;k++){
                if(low_weight[k]!=0 && low_weight[k]<min_weight){
                    min_weight=low_weight[k];
                    min_index=k;
                }
            }
            //将最小权重顶点加入最小生成树
            low_weight[min_index]=0;
            min_weights+=min_weight;
            ++cnt;

            //查找当前顶点边的下一个顶点，并更新权重
            for(int j=0;j<top_size;++j){
                delete iw;
                iw= nullptr;
                iw=iterator(min_index);
                T cur_weight=iw->get_weight(j);
                if(low_weight[j]!=0 && cur_weight!=0 && cur_weight<low_weight[j]){
                    low_weight[j]=iw->get_weight(j);
                    parents[j]=min_index;
                }
            }
        }

        for(auto &c:parents){
            cout<<c<<" ";
        }
        cout<<endl;
        if(cnt<top_size-1) min_weights=0;
        cout<<"number of edges:"<<cnt<<endl;
        cout<<"min weights:"<<min_weights<<endl;
    }

private:
    //查找树的根节点,判断两个节点是否属于同一棵树
    //优化：路径压缩,例：0->1->5 => 0->5;1->5
    int find_root(vector<int> &parents,int v)
    {
        //查找根节点
        int vTmp=v;
        while(parents[v]>=0){
            v=parents[v];
        }

        //路径压缩
        while(v!=vTmp){
            int tmp=parents[vTmp];
            parents[vTmp]=v;
            vTmp=tmp;
        }

        return v;
    }

public:
    /*******************************************
    *                   拓扑排序                 *
    /*******************************************/
    //Kahn 算法
    virtual vector<int> Kahn()
    {
        if(!directed()) {
            cout<<"Topological Sort Graph must be directed graph(In function Kahn())!!! "<<endl;
            exit(0);
        }

        int top_size=number_of_vertices();      //当前图中顶点的个数
        int edge_size=number_of_Edge();         //当前图中边的个数
        vector<int> indegrees(top_size,-1);     //定义存储每个顶点的入度
        ListQueue<T> zeros_indegrees;           //定义存储入度为0顶点的队列
        vector<int> result;                     //存储排序结果

        //初始化变量
        for(int i=0;i<top_size;++i){
            int tmp=in_degree(i);
            //将入度为0的顶点入队
            //初始化所有顶点的入度
            if(tmp==0){
                zeros_indegrees.push(i);
            }else{
                indegrees[i]=in_degree(i);
            }

        }

        while(!zeros_indegrees.empty()){
            //从入度为0的队列中取出顶点
            int top=zeros_indegrees.pop();
            //存储到结果中
            result.push_back(top);

            //遍历所有与top相关的边并删除
            for(int j=0;j<top_size;++j){
                //将该边从图中移除
                if(exits_edge(top,j)){
                    --edge_size;
                    --indegrees[j];
                }
                //如果入度为0，那么加入入度为0的队列
                if(indegrees[j]==0){
                    zeros_indegrees.push(j);
                    indegrees[j]=-1;
                }
            }
        }

        //判断图中是否存在环
        if(0!=edge_size){
            cout<<"The Graph exit cycle!!!"<<endl;
            exit(0);
        }

        return result;
    }

    //DFS算法
    virtual void Dfs()
    {
        if(!directed()) {
            cout<<"Topological Sort Graph must be directed graph(In function Kahn())!!! "<<endl;
            exit(0);
        }

        int top_size=number_of_vertices();
        vector<bool> visit(top_size, false); //定义当前顶点的访问状态
        ListStack<int> stack;                //存储排序结果

        for(int i=0;i<top_size;++i){
            if(!visit[i]){
                rDfs(i,visit,stack);
            }
        }
    }

private:
    void rDfs(int i,vector<bool> &visit,ListStack<int> &stack)
    {
        visit[i]= true;
        int top_size=number_of_vertices();

        for(int j=0;j<top_size;++j){
            if(exits_edge(i,j) && !visit[j]){
                rDfs(j,visit,stack);
            }
        }

        stack.push(i);
    }
};

#endif //TESK_GRAPH_H
