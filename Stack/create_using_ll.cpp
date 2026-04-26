#include<iostream>
using namespace std;
template<class T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T val){
        data = val;
        next = NULL;
    }
};
template<class T>
class Stack{
    Node<T>* head;
public:
    Stack(){
        head = NULL;
    }
    void push(int val){
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL){
            head = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void pop(){
        if(head == NULL){
            cout<<"Stack is underflow \n";
            return;
        }else{
         
            Node<T>* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    T top(){
        if(head == NULL){
            return -1;
        }
        return head->data;
    }
    bool empty(){
        return head == NULL;
    }
};
int main(){
    Stack<char>st;
    st.push('5');
    st.push('4');
    st.push('3');
    st.push('2');
    st.push('1');
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
     cout<<st.top()<<" ";
    return 0;
}