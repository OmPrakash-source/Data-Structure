#include<iostream>
#include<queue>
#include<deque>
using namespace std;

class Stack{
public:
queue<int>q1;
queue<int>q2;
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop(){
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    int top(){
        return q1.front();
    }
    bool empty(){
        return q1.empty();
    }
};

class DequeStack{
public:
    deque<int>q;
    void push(int x){
        q.push_front(x); // push front me hoga last me old val 
    }
    int pop(){
        int temp = q.front(); // front pe newest val 
        q.pop_front(); // new val ko pop
        return temp;
    }
    int top(){
        return q.front(); 
    }
    bool empty(){
        return q.empty();
    }
};

class queStack{
public:
    queue<int>q;
    void push(int x){
        q.push(x); // push front me hoga last me old val 
    }
    int pop(){
        int temp = q.front(); // front pe newest val 
        q.pop(); // new val ko pop
        return temp;
    }
    int top(){
        return q.front(); 
    }
    bool empty(){
        return q.empty();
    }
};
int main(){
    DequeStack s;
    s.push(12);
    s.push(11);
    s.push(10);
    s.push(9);
    cout<<s.top()<<" \n";
    cout<<"Delete value "<<s.pop()<<" \n";
    cout<<s.top()<<" \n";
}
// minor style fix
