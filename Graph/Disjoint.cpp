#include<iostream>
#include<vector>
using namespace std;
class DisjoinSet{
public:
    int n;
    vector<int>par;
    vector<int>rank;

    DisjoinSet(int n){
        this->n = n;

        for(int i=0;i<n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return find(par[x]);
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        } else{
            par[parA] = parB; 
        }
    }
   void extraInfo(){
    for(int i=0;i<n;i++){
        cout<< i <<"'"<< par[i]<<"'"<<rank[i]<<" ; ";
    }
    cout<<endl;
   }
};

int main(){
    DisjoinSet dj(6);
    dj.unionByRank(0,2);
    cout<<dj.find(2)<<endl;
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    cout<<dj.find(5)<<endl;
    dj.unionByRank(0,3);
    cout<<dj.find(2)<<endl;
    dj.unionByRank(0,4);

    dj.extraInfo();
}