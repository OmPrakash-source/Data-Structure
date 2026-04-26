
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->next=NULL;
    }
    
    Node( int data){
        this->data=data;
        this->next=NULL;
    }
    // constructor
    ~Node(){
        cout<<"Destructor is called for : "<<data<<endl;
    }
   
};
//________________________________ insert by head ____________________________________________
    void insertHead(Node* &head,Node* &tail ,int data){
        if(head==NULL){
            //if is it null
            // create new node
            Node* newNode = new Node(data);
            // head and tail both point NULL
            head=tail=newNode;
        }
        else { 
            // not Null
        // create new node
        Node*newNode = new Node(data);
        // point new node to head
        newNode->next = head;
        // updata newnode
        head = newNode;
        }
    }
//________________________________ insert by tail ____________________________________________
    void insertTail(Node* &head ,Node* &tail ,int data){
        // create new node
            Node* newNode = new Node(data);
        if(head==NULL){
            //if is it null
            // head and tail both point NULL
            head=tail=newNode;
        }
        else{
            //point tail next to newnode
            tail->next = newNode;
            //update new node
            tail=newNode;
        }
    }
    int getlength(Node*&head){
        Node*temp=head;
        int length=0;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        return length;
    }
//________________________________ insert by position ____________________________________________
    void insertAnyPosi(Node* &head ,Node*& tail ,int data ,int position){

        int length = getlength(head);
        if(position==1){
            insertHead(head , tail , data);
            return;
        }
        else if(position > length){
            insertTail(head ,tail , data);
            return;
        }
        else{
        //crete a new node
        Node* newNode = new Node(data);
        Node*prev=NULL;
        Node*curr=head;
        while(position!=1){// becouse position is dicraess given position align in head then head-1
            prev =curr;
            curr = curr->next;
            position--;
        }
        prev->next=newNode;
        newNode->next=curr;
      }
    }

//________________________________ PRINT ____________________________________________
    void print(Node*head){
        Node*temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"null"<<endl;
    }
//________________________________delete by position____________________________________________
    void deleteNode(Node* &head ,Node*& tail ,int position ){
        int len = getlength(head);
        if(head==NULL){
            cout<<"List is null\n";
            return;
        }
        // if position is a head 
        if(position==1){          
            Node*temp = head;     
            head = temp->next;      //  head is move by one
            temp->next=NULL;        // isoleted temp
            delete temp;            // delete temp
        }
        //for single value
        else if(head==tail){
           Node*temp = head; 
           delete temp;
            head =NULL; 
            return;
        }
        // if position is tail
        else if( position == len){
            Node*prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            delete tail;
            tail = prev;
        }
        else{
            Node*prev = NULL;
            Node*curr = head;
            while(position != 1){
                position--;
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;// prev point to curr + 1 node
            curr->next = NULL;      // isoleted node 
            delete curr;
        }
    }
//________________________________Delete by value____________________________________________
 void deleteval(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }
    
    // Case 1: Deleting the head node
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
     else if(head==tail){
           Node*temp = head; 
           delete temp;
            head =NULL; 
            head =NULL; 
            return;
        }

    // Case 2: Deleting any node in the middle or tail
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    prev->next = curr->next;
    
      // If deleting the last node, update the tail
    if (curr == tail) {  //if all the condition is pass and curr value = tail then update tail and delete curr val
        tail = prev;
    }
    curr->next = NULL;

    delete curr;
    return;
 }
//________________________________cycle ____________________________________________
            //     bool hasCycle(Node * &head) {
            //     if (!head || !head->next) return false;

            //     Node *slow = head;
            //     Node *fast = head;

            //     while (slow != fast) {
            //         if (fast==NULL || fast->next==NULL){
            //              return false;
            //         }
            //         slow = slow->next;
            //         fast = fast->next->next;
            //     }

            //     return true;
            // }
    bool cycle(Node* &head){
        cout<<"cycle function is called\n";
        Node* fast = head;
        Node* slow = head;
        while (fast != NULL && fast->next!= NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        //       find first number a Loop 
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        //       remove a Loop 
        Node* startpoin  = slow;
        Node* temp  = fast;
        while(temp -> next != startpoin){
            temp = temp->next;
        }
        temp->next = NULL;
    }
 //________________________________ reverse ____________________________________________
    Node* reverse(Node* &head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return prev;
    }
//________________________________ find mid ____________________________________________
    Node* findMiddle(Node * &head){
        Node* temp = head;
        if(temp == NULL && temp->next == NULL){
            return head;
        }
        Node* fast = head;
        Node* slow = head;
        Node* prev = NULL;
        while(fast != nullptr && fast->next!= nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
         if (prev != nullptr) {
        prev->next = NULL;
    }
        return slow;
    }

//________________________________ Add 1 IN List ____________________________________________
    void addOne(Node* &head){
        head = reverse(head);
        Node* temp = head;
        int carry = 1;
        while(temp->next != NULL){
            int TotalSum = temp->data + carry;
            int digit = TotalSum % 10;
            carry = TotalSum / 10;
            temp->data = digit;
            temp = temp->next;
            if(carry == 0){
                break;
            }
        }
        if(carry!=0){
            int TotalSum = temp->data + carry;
            int digit = TotalSum % 10;
            carry = TotalSum / 10;
            temp->data = digit;
            if(carry!=0){
                Node*newNode = new Node(carry);
                temp->next = newNode;
            }
        }
        reverse(head);
    }
//_____________________________________ remove duplicat______________________________________________
        Node* remove(Node* &head){
            Node* temp = head;
            if(temp == NULL || temp->next == NULL){
                return head;
            }
            while(temp!=NULL){
                if(temp->data == temp->next->data){
                    Node* NextNode = temp->next;
                    temp->next = NextNode->next;    // ye time pe yad nhi aaya hai
                    NextNode->next = NULL;
                    delete NextNode;
                }
                else{
                    temp = temp->next;
                }
            }
             return head;
        }
//_________________________________________________ zig-zag ________________________________________________________

  Node* Zig_zag(Node* &head){
    Node* mid = findMiddle(head);
    Node* rev = reverse(mid);
    Node* left = head;
    Node* right = rev;
    Node* tail = NULL;
    while(left != nullptr && right != nullptr){
        Node* nextright = right->next;
        Node* nextleft = left->next;
        tail = right;
        left->next = right;
        right->next = nextleft;
        tail = right;
        left = nextleft;
        right = nextright;
    }
    if (right != NULL){
        tail->next = right;
    }
    return head;
  }


    int main(){

        Node* head= NULL;
        Node* tail= NULL;
        // static
        insertTail(head,tail,9);
        insertTail(head,tail,8);
        insertTail(head,tail,0);
        // insertTail(head,tail,4);
        insertTail(head,tail,5);
        insertTail(head,tail,1);
     
    
        tail->next = head->next->next;
        // cout<<cycle(head)<<endl;
        // cycle(head);
       
        // addOne(head);
        // Node* DataMiddle = findMiddle(head);
        // cout<< DataMiddle->data<<endl;
        Zig_zag(head);
        print(head);
        // int position;
        // cout<<"Enter a position ";
        // cin>>position;
        // deleteNode(head , tail , position);
        
        // print(head);
    //    if (cycle(head)){
    //     cout<<"cycle detected in loop \n";
    //     return false;
    //    }
    //    else{
    //     cout<<"cycle is not detected in loop \n";
    //     return true;
    //    }
        //  dynamic
        // Node* a = new Node(10);
        // Node* b = new Node(20);
        // Node* c = new Node(30);
        // Node* d = new Node(40);

        // b->next = c;
        // a->next = b;
        // c->next = d;

        // Node*head = a;
        // Node*tail = d;
        
        // insertTail(head , tail ,50 );  // there we insert value using pass by refrence &
    }
// minor style fix
