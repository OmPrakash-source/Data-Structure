#include<iostream>
#include<string>
#include<queue>
using namespace std;
// class Student{
//     public:
//     int marks;
//     string name;
   

//     Student(string name,int marks){
//         this->name = name;
//         this->marks = marks;
//     }
//     bool operator < (const Student &obj) const {
//         return this->marks < obj.marks;
//     }
// };

struct object{
    bool operator ()(pair<string, int>&p1, pair<string, int>&p2){
        return p1.second > p2.second;
    }
};

int main(){
    // priority_queue<pair<string,int>>pq; //by default - maxHeap"first"

    priority_queue<pair<string,int>, vector<pair<string,int>>, object>pq; // basic of second value
    pq.push(make_pair("Hardik",95));
    pq.push(make_pair("Akash",97));
    pq.push(make_pair("Ram",100));

    while(!pq.empty()){
        cout<<"top : "<<pq.top().first<<", "<<pq.top().second << endl;
        // cout<<"top : "<<pq.top().name<<", "<<pq.top().marks << endl;
        
        pq.pop();
    }
    
    return 0;
}