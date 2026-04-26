#include<iostream>
using namespace std;
// class Node{
//     public:
//     Node* next;
//     int data;
//     // Node (){
//     //     this-> next = NULL;
//     // }
//     Node ( int data ){
//         this->data = data;
//         this-> next= NULL;
//     }
// };
class Node{
    public:
    int data;
    Node* next;
    // Node(){};
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
//  void insert(Node* &head , int data){
//     Node* newNode = new Node(data);
//     if( head == NULL){
//         head = newNode;
//     }
//     else{
//         newNode->next = head;
//         head = newNode;
//     }
//  }
void insert(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
    } else{
        newNode->next = head;
        head = newNode;
    }
}
// _____________________________________________________  REVERSE linked list ___________________________________
void reverse (Node* &head){
    Node* prev =NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* nodeNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nodeNext;
    }
    head = prev;
}

void reverse2(Node* &head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}
 void print( Node* & head){
    Node* temp = head;           // ye galti ab mat karna
    while(temp != NULL){
        cout<< temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null\n";
 }

 int main(){
    Node*head = NULL;
    insert(head , 40);
    insert(head , 30);
    insert(head , 20);
    insert(head , 10);
    cout<< "befour reverse ";
     print(head);
    reverse2(head);
    cout<< "after reverse ";
     print(head);
 }
// minor style fix
