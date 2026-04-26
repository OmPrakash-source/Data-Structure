#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
     // Default constructor
     Node() {
         this->prev = NULL;
         this->next = NULL;
     }

     // Parametrized constructor
     Node(int data) {
         this->data = data;
         this->prev = NULL;
         this->next = NULL;
     }
 };
// __________________________________ print _________________________________
    void print(Node* &head) {
     Node* temp = head;
     while (temp != NULL) {
         cout << temp->data << "-> ";
         temp = temp->next;
     }
     cout << "null\n"; // Missing semicolon
 }
// __________________________________ insert at the head _________________________________
   void insertatHead(Node* &head, Node* &tail, int data) {
       Node* newNode = new Node(data);  // daynamic new node alocet 
       if (head == NULL) {
           head = tail = newNode;
       } else {
           newNode->next = head;
           head->prev = newNode;
           head = newNode;  // Update head pointer correctly
       }
   }
// __________________________________ insert at the tail ___________________________________________
   void insertatTail(Node* &head , Node* &tail,int data){
    Node*newNode = new Node(data);
    if(head==NULL){
        head = tail =newNode; 
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }
   }
// __________________________________ find length ___________________________________________
       int getlength(Node* &head){
        Node* temp = head;
        int length = 0;
        while(temp != NULL){
            temp = temp->next;
            length ++ ;
        }
        return length;
    }
// __________________________________ insert at the any possition ___________________________________________

    void insertAnyPosi(Node* &head , Node* &tail ,int position , int data){
        Node* newNode = new Node(data);
        int len = getlength(head);
        if(position==1){
            insertatHead(head ,tail ,data);
            return;
        }
        else if(position > len){
            insertatTail(head , tail , data);
            return;
        }
        else{
            Node* newNode = new Node(data);
            Node* curr = head;
            Node* prev1 = NULL;
            while(position != 1){
                prev1 = curr;
                curr = curr->next;
                position --;
            }
            // left side is sorted
            prev1->next = newNode; 
            newNode->prev = prev1;
            // right side is sorted
            newNode->next = curr;
            curr->prev = newNode ;
        }
    }

//  __________________________________ delete any possition ___________________________________________

    void deleteNode(Node* &head , Node* &tail ,int position ){
        int len = getlength(head);
        if(head==NULL){
            cout<<"can not be delete list is Empty \n";
            head = tail =NULL;
            return ;
        }
        // for only one node
        if(head == tail){
            Node* temp = head;
            delete temp;
            head = NULL;
            tail = NULL;
            return ;
        }
        if(position == 1){
            Node*temp = head;
            head = temp->next;
            temp->next = NULL;
            head->prev = NULL;
            delete temp;
        }
        else if(position  >= len){
            Node*preNode = tail->prev;
            preNode->next = NULL;
            tail->prev = NULL;
            delete tail;
            tail = preNode;
        }
        else{
            Node* prev1 = NULL;
            Node* curr = head;
            while(position != 1){
                position--;
                prev1 = curr;
                curr = curr->next;
        }
        Node* nextNode = curr->next;
        prev1->next = curr->next;
        nextNode->prev = curr->prev;
        delete curr;
      }
    }


    int main(){
        Node*head =NULL;
        Node*tail =NULL;
        insertatTail(head ,tail , 10);
        insertatTail(head ,tail , 20);
        insertatTail(head ,tail , 30);
        insertatTail(head ,tail , 40);
        insertAnyPosi(head ,tail , 5 , 25);
        print(head);
        cout<<endl;
        deleteNode(head , tail ,3);
        print(head);
        deleteNode(head , tail ,3);
        print(head);
        deleteNode(head , tail ,3);
        print(head);
        deleteNode(head , tail ,3);
        print(head);
         deleteNode(head , tail ,3);
        print(head);
        deleteNode(head , tail ,1);
        print(head);
        cout<< " length : "<< getlength(head);
        
        return 0;
    }


// minor style fix
