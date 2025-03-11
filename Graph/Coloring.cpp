#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int>*l;
    bool isTrue ;
public:
    Graph(int V,bool isTrue= true){
        this->V = V;
        this->isTrue = isTrue;
        l = new list<int>[V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isTrue){
            l[v].push_back(u);
        }
    }
// .................... Coloring ....................

    bool isBipartite(int src, vector<bool>&vis, vector<int>&color){
        queue<int>q;
        vis[src] = true;
        q.push(src);
        color[src] = 0;
        while(q.size()>0){
            src = q.front();
            q.pop();
            list<int>neighbors = l[src];
            for(int v: neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    color[v] != color[src];
                    q.push(v);
                }else{
                    if(color[v]==color[src]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool Coloring(){
        vector<bool>vis(V,false);
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(!vis[i]){                
                if(!isBipartite(i,vis,color)){
                    return false;
                }
            }
        }
        return true;
    }
// .................... All path ....................
    void pathHalper(int src, int dest, vector<bool>&vis, string &path ){
        if(src == dest){
            cout<< path<<dest;
            cout<<endl;
            return;
        }
        vis[src] = true;
        path+= to_string(src); 
        list<int>neighbors = l[src];
        for(int v : neighbors){
            if(!vis[v]){
                pathHalper(v,dest,vis,path);
            }
        }
        path = path.substr(0,path.size()-1);
        vis[src] = false;   //create a multiple level
        // agar or koi path bhi vohi node se ho to vis = false hoga tab hi wo again uspe jayga
    }
    void printAllPath(int src,int dest){
        vector<bool>vis(V,false);
        string path = " ";
        pathHalper(src,dest,vis,path);
    }
};

int main(){
    Graph graph(10,false); 
    // graph.addEdge(0,1);
    // graph.addEdge(0,2);
    // graph.addEdge(1,3);
    // graph.addEdge(2,3);
    // graph.addEdge(0,3);
       graph.addEdge(0,3);
       graph.addEdge(2,3);
       graph.addEdge(3,1);
       graph.addEdge(4,0);
       graph.addEdge(4,1);
       graph.addEdge(5,0);
       graph.addEdge(5,2);

       graph.printAllPath(5,1);

    // cout<<graph.Coloring();

}