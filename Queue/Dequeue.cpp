#include<iostream>
using namespace std;
class Deque{
public:
    int front, rear, size;
    int *arr;
    Deque(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    void pushrear(int data){
        if((front == 0 && rear == size-1)|| front == rear+1){
            cout<<"Queue is full\n";
            return;
        }else if(front == -1 && rear == -1){
            front = rear = 0;
            arr[rear] = data;
        }else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }else{
            rear++;
            arr[rear] = data;
        }
    }
    void pushfront(int data){
        if((front == 0 && rear == size-1)|| front == rear+1){
            cout<<"Queue is full\n";
            return;
        }
        // single value
        else if(front == -1 && rear == -1){
            front = rear = 0;
            arr[front] = data;
        }
        // ciculer 
        else if(rear != size-1 && front == 0){
            front = size-1;
            arr[front] = data;
        }
        // normal
        else{
            front--;
            arr[front] = data;
        }
    }
    void popfront(){
        if(front == -1){
            cout<<"Queue is empty\n";
            return;
        }else if(front == rear){
            front = rear = -1;
        }else if(front == size-1){
            front = 0;
        }else{
            arr[front] = -1;
            front++;
        }
    }
    void poprear(){
        if(front == -1){
            cout<<"Queue is empty\n";
            return;
        }else if(front == rear){
            front = rear = -1;
        }else if(rear == 0){
            rear = size-1;;
        }else{
            arr[rear] = -1;
            rear--;
        }
    }
    int getfront(){
        return arr[front];
    }
    int getrear(){
        return arr[rear];
    }
    bool isEmpty(){
        return rear == -1 && front == -1;
    }
};
int main(){
    Deque de(4);
    de.pushfront(20);
    de.pushrear(40);
    cout<<de.getfront() <<" "<<de.getrear()<<endl;
}

// minor style fix
