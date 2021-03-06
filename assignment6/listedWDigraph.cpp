//
// Created by jinqiu on 19-3-14.
//

#include "listedWDigraph.h"

int main()
{
//    cout<<"========>listedWDigraph："<<endl;
//    listedWDigraph<float> lwdg(4);
//    lwdg.insert_edge(Edge<float >(0,1,2.5));
//    lwdg.insert_edge(Edge<float >(0,2,1.5));
//    lwdg.insert_edge(Edge<float>(1,2,1.15));
//    lwdg.insert_edge(Edge<float>(2,3,2.5));
//    lwdg.insert_edge(Edge<float>(3,0,2.5));
//    lwdg.insert_edge(Edge<float>(3,1,2.5));
//    lwdg.print();
//    cout<<"edge size:"<<lwdg.number_of_Edge()<<endl;
//    cout<<"top size:"<<lwdg.number_of_vertices()<<endl;
////    lwdg.erase_edge(0,1);
////    lwdg.print();
//    //lwdg.degree(1);
//    cout<<"in_degree:"<<lwdg.in_degree(1)<<endl;
//    cout<<"out_degree:"<<lwdg.out_degree(1)<<endl;
//    vector<int > bfs=lwdg.bfs(0);
//    for(auto &c:bfs){
//        cout<<c<<" ";
//    }
//    cout<<endl;
//    vector<int > dfs=lwdg.dfs(0);
//    for(auto &c:dfs){
//        cout<<c<<" ";
//    }
//    cout<<endl;
//    vector<float > distance=lwdg.dijkstra(0);
//    for(auto &c:distance){
//        cout<<c<<" ";
//    }
//    cout<<endl;
//
//    cout<<"========>listedWGraph："<<endl;
//    listedWGraph<float> lwg(4);
//    lwg.insert_edge(Edge<float >(0,1,2.5));
//    lwg.insert_edge(Edge<float >(0,2,1.5));
//    lwg.insert_edge(Edge<float>(1,2,1.15));
//    lwg.insert_edge(Edge<float>(2,3,2.5));
//    lwg.insert_edge(Edge<float>(3,0,2.5));
//    lwg.insert_edge(Edge<float>(3,1,2.5));
//    lwg.print();
//    cout<<"edge size:"<<lwg.number_of_Edge()<<endl;
//    cout<<"top size:"<<lwg.number_of_vertices()<<endl;
//    lwg.erase_edge(0,1);
//    lwg.print();
//    lwg.degree(1);
//    cout<<"in_degree:"<<lwg.in_degree(1)<<endl;
//    cout<<"out_degree:"<<lwg.out_degree(1)<<endl;
//    vector<int > bfs1=lwg.bfs(0);
//    for(auto &c:bfs1){
//        cout<<c<<" ";
//    }
//    cout<<endl;
//    vector<int > dfs1=lwg.dfs(0);
//    for(auto &c:dfs1){
//        cout<<c<<" ";
//    }
//    cout<<endl;


    listedWDigraph<int> lwdg(6);
    lwdg.insert_edge(Edge<int >(0,1,7));
    lwdg.insert_edge(Edge<int >(0,2,9));
    lwdg.insert_edge(Edge<int >(0,5,11));

    lwdg.insert_edge(Edge<int>(1,2,10));
    lwdg.insert_edge(Edge<int>(1,3,15));

    lwdg.insert_edge(Edge<int>(2,5,2));
    lwdg.insert_edge(Edge<int>(2,3,11));

    lwdg.insert_edge(Edge<int>(3,4,6));
    lwdg.insert_edge(Edge<int>(4,5,9));
    lwdg.print();

    vector<int > distance=lwdg.dijkstra(0);
    for(auto &c:distance){
        cout<<c<<" ";
    }
    cout<<endl;

    lwdg.kruskal();

    return 0;
}