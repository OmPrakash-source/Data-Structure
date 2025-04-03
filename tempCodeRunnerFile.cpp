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
        bool bfs(int src,int dest){ // O(V + E)
            queue<int>q;
            vector<bool>vis(V, false); //vis(size,true/false) kyoki bool vector hai
            q.push(src);
            vis[src] = true;
            while(q.size()>0){
             src = q.front();
             q.pop();
        
             list<int>neighbors = l[src];
             for(int v : neighbors){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                    if(src == dest) return true;
                    }
                }
            } 
            return false;
         }
        };
        int main(){
            Graph graph(7);
                graph.addEdge(0,1);
                graph.addEdge(0,2);
                graph.addEdge(1,3);
                graph.addEdge(2,4);
                graph.addEdge(3,4);
                graph.addEdge(3,5);
                graph.addEdge(4,5);
                graph.addEdge(5,6);
                cout<< graph.bfs(0,2);
        }