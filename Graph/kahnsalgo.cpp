#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
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
    ~Graph() {
        delete[] l;  // Frees the array of lists
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isTrue){
            l[v].push_back(u);
        }
    }
    void calInDegree(vector<int> &indeg){
        for(int u=0;u<V;u++){
            list<int>neighbors = l[u];
            for(int v : neighbors){ //u-->v
                indeg[v]++;
            }
        }
    }
    bool topoSort2helper(){ //kahn's algo
        vector<int>indeg(V,0);
        calInDegree(indeg);
        queue<int>q;
        for(int i=0;i<V;i++){
            // 0 indegree first me push hoga
            if(indeg[i] == 0){
                q.push(i);
            }
        }
    
        while (q.size()>0){
            int curr = q.front();
            q.pop();
            cout<< curr<<" ";
            list<int>neighbors = l[curr];
            for(int v : neighbors){
                // neighbor ki indegree deceress karge
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        } 
        
    }
};

int main(){
    Graph graph(6,false);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,2);
    graph.addEdge(5,0);
    graph.addEdge(5,2);
    graph.topoSort2helper();
}