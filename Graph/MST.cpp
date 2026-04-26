#include<iostream>
#include<queue>
#include<list>
#include<vector>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>>*l;
    bool Undir;
public:
    Graph(int V,bool Undir = true) {
        this->V = V;
        l = new list<pair<int,int>>[V];
        this->Undir = Undir;
    }
    ~Graph() {
        delete[] l;  // Frees the array of lists
    }
    void addadge(int u,int v,int wt){
        l[u].push_back(make_pair(v, wt));
        if(Undir){
            l[v].push_back(make_pair(u, wt));
        }
    }
    void Prim_s (int src){
        priority_queue<pair<int, int> ,  vector<pair<int, int>>, greater<pair<int, int>>>pq;   // sort min wt first
        //____ priority_queue _______|, |_____ vector pair ___|, |_____ min p.queue _____|

        vector<bool>mst(V,false);
        int ans = 0;
        pq.push(make_pair(0, src)); // (wt , vertice)

        while(pq.size()>0){
            int  u = pq.top().second;   // vertice
            int  cost = pq.top().first; // wt
            pq.pop();
            if(!mst[u]){                // if vertices is not store in set
                mst[u] = true;          // then vertices stored in set 
                ans += cost;            // add wt to ans 
                list<pair<int,int>>neighbors = l[u];
                // then uske neighbors ki call lagana hai
                for(pair<int,int> n : neighbors){

                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt,v));
                }
            }
        }
    cout<< "Final cost of MST = "<<ans;
    }

};
int main(){
    Graph graph(4);
    graph.addadge(0,1,15);
    graph.addadge(0,2,10);
    graph.addadge(0,3,30);
    graph.addadge(1,3,40);
    graph.addadge(2,3,50);

    graph.Prim_s(0);
}
// minor style fix
