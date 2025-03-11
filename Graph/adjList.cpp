#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
// undirected
    class Graph{
        int V;
        list<int>*l;
    public:
        Graph(int V){
            this->V = V;
            l =new list<int>[V];
        }
        void addEdge(int u, int v){ //u---v
            l[u].push_back(v);
            l[v].push_back(u);
        }    
        void print(){
            for(int u=0;u<V;u++){
                list<int>neighbors = l[u];
                cout<<u<<" : ";
                for(int v : neighbors){
                    cout<<v<<" ";
                }
                cout<<endl;
            }
        }
        void bfs(){ // O(V + E)
            queue<int>q;
            vector<bool>vis(V, false); //vis(size,true/false) kyoki bool vector hai
            q.push(0);
            vis[0] = true;
            while(q.size()>0){
             int u = q.front();
             q.pop();
             cout<<u<<" ";
     
             list<int>neighbors = l[u];
             for(int v : neighbors){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                    }
                }
            } 
         }

         void dfshalper(int u, vector<bool>&vis){
            vis[u] = true;
            cout<<u<<" ";
            list<int>neighbors = l[u];
            for(int v : neighbors){
                if(vis[v] != true){
                    dfshalper(v,vis);
                }
            }
         }

         void dfs(){
            vector<bool>vis(7,false); //size is 7 and all value is false by defalt
            dfshalper(0,vis);
         }
         bool Hasexisthealper(int src,int dest, vector<bool>&vis){
            if(src == dest){
                return true;
            }
            vis[src] = true;
            list<int>neighbors = l[src];
            for(int v : neighbors){
                if(vis[v] != true){
                    if( Hasexisthealper(v,dest,vis)){
                        return true;
                    }
                }
            }
            return false;
         }

         bool Hasexist(int src,int dest){
            vector<bool>vis(7,false); //size is 7 and all value is false by defalt
            return Hasexisthealper(src, dest, vis);
         }
    };
// Direacted
    // class Graph{
    //     int V;
    //     int weight;
    //     list<pair<int,int>>*l;
    // public:
    //     Graph(int V){
    //         this->V = V;
    //         l = new list<pair<int,int>>[V];
    //     }
    //     void addEdge(int u, int v, int weight) {
    //         l[u].push_back(make_pair(v, weight));
    //         l[v].push_back(make_pair(u, weight));
    //     }
    //     // void print() {
    //     //     for (int u = 0; u < V; u++) {
    //     //         list<pair<int, int>> neighbours = l[u];
    //     //         cout << u << " : ";
    //     //         for (pair<int, int> v : neighbours) {
    //     //             cout << "(" << v.first << "," << v.second << ") ";
    //     //         }
    //     //         cout << endl;
    //     //     }
    //     // }
    //     void print(){
    //         for(int u=0;u<V;u++){
    //             list<pair<int,int>>neighbour = l[u];
    //             cout<<u<<" : ";
    //             for(pair<int,int> v : neighbour){
    //                 cout<< v.first <<","<< v.second <<" ";
    //             }
    //             cout<<endl;
    //         }
    //     }
    // };

    
int main(){
    Graph graph(7);
    // graph.addEdge(0, 1, 5);
    // graph.addEdge(2, 3, 1);
    // graph.addEdge(1, 3, 1);
    // graph.addEdge(4, 2, 2);
        graph.addEdge(0,1);
        graph.addEdge(0,2);
        graph.addEdge(1,3);
        graph.addEdge(2,4);
        graph.addEdge(3,4);
        graph.addEdge(3,5);
        graph.addEdge(4,5);
        graph.addEdge(5,6);
        cout<< graph.Hasexist(0,5);

    // graph.print();
}