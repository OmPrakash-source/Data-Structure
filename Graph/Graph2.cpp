#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
// undirected
    class Graph{
        int V;
        list<int>*l;
        bool isUndir;
    public:
        Graph(int V, bool isUndir = true){
            this->V = V;
            this->isUndir = isUndir;
            l =new list<int>[V];
        }
        void addEdge(int u, int v){ // u-->v
            l[u].push_back(v);
            //agar graph undir hai to reverce push karege //u---v
            if(isUndir){ // false
                l[v].push_back(u);
            } 
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
        void bfshalper(int st,vector<bool>&vis){
            queue<int>q;
            q.push(st);  
            vis[st] = true;
            while(q.size() > 0){
                int u = q.front();
                q.pop();
                cout<<u <<" ";
                list<int>neighbors = l[u];
                for(int v : neighbors){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        void bfs(){
            vector<bool>vis(V,false);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    bfshalper(i , vis);
                    cout<<endl;
                }
            }
           

        }
        void dfshalper(int src,vector<bool>&vis){
            vis[src] = true;
            cout<<src <<" ";
            list<int>neighbors = l[src];
            for(int v : neighbors){
                if(!vis[v]){
                    dfshalper(v,vis);
                }
            }
        }
        void dfs(){
            vector<bool>vis(V,false);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    dfshalper(i,vis); // now starting point is our i
                    cout<<endl;
                }
            }
        }
        //NOTE : backedge is a Edge which create a loop 

        //.................... for undirected  .......................

        bool halperCycle(int src,int par,vector<bool>&vis){
            vis[src] = true;
            list<int>neighbors = l[src];
            for(int v : neighbors){
                if(vis[v]!=true){
                    if(halperCycle(v,src,vis)){  // v is child, src jaha se node aai hai 
                        return true;  // agar parent ko cycle mil gayi
                    }
                }else{
                    if(v != par){
                        return true;   //agar hamko cycle mill gai
                    }
                }
            }
            return false;   // agar cycle nahi mile
        }
        bool isCycleUndircted(){
            vector<bool>vis(V,false);
            for(int i=0;i<V;i++){
                if (!vis[i]){
                 if(halperCycle(i,-1,vis)){ 
                     return true;
                 }
                }
             }
             return false;

        }
        //.................... for Directed  .......................
        bool halperCycleDir(int src,vector<bool>&vis,vector<bool>&recpath){
            vis[src] = true;
            recpath[src] = true;
            list<int>neighbors = l[src];
            for(int v:neighbors){
                if(!vis[v]){
                    if(halperCycleDir(v,vis,recpath)){
                        return true;
                    }
                }else{
                    if(recpath[v]){ //vis[v],recpath[v] == true
                        return true;
                    }
                }
            }
            recpath[src] = false;
            return false;
        }
        bool isCycleDirected(){
            vector<bool>vis(V,false);
            vector<bool>recPath(V,false);
            for(int i=0;i<V;i++){
               if (!vis[i]){
                if(halperCycleDir(i,vis,recPath)){ 
                    return true;
                }
               }
            }
            return false;
        }
    };

    int main(){
        Graph graph(10,false); //false for directed graph

                // graph.addEdge(0,1);
                // graph.addEdge(0,2);
                // graph.addEdge(1,3);
                // graph.addEdge(2,4);
                // graph.addEdge(3,4);
                // graph.addEdge(3,5);
                // graph.addEdge(4,5);
                // graph.addEdge(5,6);

                // // graph.addEdge(7,8);
                // // graph.addEdge(8,9);
                // // graph.addEdge(7,9);
                 graph.addEdge(1,0);
                 graph.addEdge(0,2);
                 graph.addEdge(2,3);
                 graph.addEdge(3,0);
                

                cout <<graph.isCycleDirected();
        return 0;
    }