#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int main(){
    priority_queue<string,vector<string>,greater_equal<string>>pq;
    pq.push("hello");
    pq.push("empty");
    pq.push("me");
    pq.push(" ");

    while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
    }
}
 
// minor style fix
