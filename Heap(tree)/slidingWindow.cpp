#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void SlidingWin(vector<int>arr, int k){
    priority_queue<pair<int,int>>pq;

    //1st sliding wondow
    for(int i=0;i<k;i++){
        pq.push(make_pair(arr[i],i));   
    }
    cout<<"output : "<<pq.top().first<<" ";

    for(int i=k;i<arr.size();i++){
        while(!pq.empty() && pq.top().second <= (i-k)){ // outside window index
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        cout<<pq.top().first<<" "; // max of window
    }
    cout<<endl;
}

int main(){
    vector<int>arr = {1, 3, -1, -1, 5, 3, 6, 7};
    int k = 3;
    SlidingWin(arr,k);
    return 0;
}
// minor style fix
