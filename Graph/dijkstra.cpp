#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include <algorithm>
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

    //using priority queue 
    vector<int>dijkstra_pq(vector<vector<pair<int,int>>>adj, int E, int S){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // denote datatype ,storage ,ordreing 
        vector<int>dist(E,INT16_MAX);
        dist[S] = 0; //mark source as 0 weight
        pq.push({0,S});
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;
                if(wt + adjwt < dist[adjnode]){
                    dist[adjnode] = wt + adjwt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
    vector<int>dijkstra_set(vector<vector<pair<int,int>>>adj, int E, int S){
        set<pair<int,int>>st;
        // denote datatype ,storage ,ordreing 
        vector<int>dist(E,INT16_MAX);
        dist[S] = 0; //mark source as 0 weight
        st.insert({0,S});
        vector<int> parent(E, -1);
        
        while(!st.empty()){
            int wt = (*st.begin()).first; // * give a value
            int node = (*st.begin()).second;
            st.erase({wt,node});
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;
                if(wt + adjwt < dist[adjnode]){
                    if(dist[adjnode] != INT16_MAX){ // agar set me exist karta hai or non max hai to hata do 
                        st.erase({dist[adjnode],adjnode});
                    }
                    parent[adjnode] = node; // track a path
                    dist[adjnode] = wt + adjwt;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        vector<int> path;
        int curr = E;
        while(curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        return path;
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

    // graph[0].push_back(Edge(1, 2));
    // graph[0].push_back(Edge(2, 4));

    // graph[1].push_back(Edge(2, -4));

     
    // graph[2].push_back(Edge(3, 2));  

    // graph[3].push_back(Edge(4, 4));

    // graph[4].push_back(Edge(1, -1)); 
    // BellmenFord(4,graph,5);
    // // dijkstra(4,graph,5);


    int E = 5; // number of vertices
    int S = 0; // source vertex

    // adjacency list: {node, weight}
    vector<vector<pair<int,int>>> adj(E);


    // 0 -> 1 (2), 0 -> 2 (4)
    adj[0].push_back({1,2});
    adj[0].push_back({2,4});

    // 1 -> 2 (1), 1 -> 3 (7)
    adj[1].push_back({2,1});
    adj[1].push_back({3,7});

    // 2 -> 4 (3)
    adj[2].push_back({4,3});

    // 3 -> 4 (1)
    adj[3].push_back({4,1});

    vector<int> dist = dijkstra_set(adj, E, S);
    for(int i : dist){
        cout  << i << "-> ";  
    }
    return 0;
}