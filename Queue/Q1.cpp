#include<iostream>
#include<queue>

using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class queue{
    Node* head;
    Node* tail;
    public:
        queue(){
            head = tail = NULL;
        }
    void push(int data){
        Node* newnode =new Node(data);
        if(head == nullptr){
            head = tail = newnode;
        }
        else{
            tail ->next = newnode;
            tail = newnode;
        }
    }
    void pop(){
        if(head == nullptr){
            cout<<" Queue is empty \n";
        }
        else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    int front (){
       return head->data;
    }
};
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.pop();
    cout<<q.front();
}