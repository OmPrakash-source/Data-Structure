#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<list>
using namespace std;

class Edge{
public:
    int V;
    int wt;
    Edge(int V, int wt){
        this->V = V;
        this->wt = wt;

    }  
};
    void dijkstra(int src, vector<vector<Edge>>graph, int V){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // min heap pair(dist[v],v) in STL by defualt sort by first value

        vector<int>dist(V,INT8_MAX);// dist Initialize with Infinite
        pq.push(make_pair(0,src));
        dist[src] = 0;
        while(pq.size()>0){
            int u = pq.top().second; // all v's
            pq.pop();
           vector<Edge>edge = graph[u];
           for(Edge e : edge){ // e.v = V , e.wt = wt
                if(dist[e.V] > dist[u]+e.wt){
                    dist[e.V] = dist[u]+e.wt;
                    pq.push(make_pair(dist[e.V],e.V));
                }
           }
        }
        for(int i = 0;i<V;i++){
            cout<<dist[i] <<" ";
        }
    }

    void BellmenFord(int src, vector<vector<Edge>>graph, int size){
        vector<int>dist(size,INT32_MAX);
        dist[src]=0;
        for(int i=0;i<size-1;i++){
            for(int u=0;u<size;u++){
                for(Edge e : graph[u]){
                    if(dist[e.V]>dist[u]+e.wt){
                        dist[e.V] = dist[u] + e.wt;
                    }
                }
            }
        }
        // print 
        for(int i = 0;i<size;i++){
            cout<<dist[i]<<" ";
        }
    }

int main(){
    vector<vector<Edge>>graph(5);
  //index[].vectorpush(vertices,weight)  
    // graph[0].push_back(Edge(1,2));
    // graph[0].push_back(Edge(2,4));
    // graph[1].push_back(Edge(2,1));
    // graph[1].push_back(Edge(3,7));
    // graph[2].push_back(Edge(4,3));
    // graph[3].push_back(Edge(5,1));  
    // graph[4].push_back(Edge(3,2));  
    // graph[4].push_back(Edge(2,5)); 
    // dijkstra(0,graph,6);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));

     
    graph[2].push_back(Edge(3, 2));  

    graph[3].push_back(Edge(4, 4));

    graph[4].push_back(Edge(1, -1)); 
    BellmenFord(4,graph,5);
    // dijkstra(4,graph,5);
    return 0;
}