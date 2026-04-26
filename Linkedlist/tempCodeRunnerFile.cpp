    #include<iostream>
    using namespace std;

    class Node{
        public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
    };
    void insertAthead(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAttail(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    int getlength(Node* head){
        Node* temp = head;
        int length = 0;
        while(temp != nullptr){
            temp = temp->next;
            length++;
        }
        return length;
    }
    void insertAtany(Node* &head, Node* &tail, int data, int position){
        int lan = getlength(head);
        Node* temp = head;
        if(position == 1){
            insertAthead(head, tail, data);
        } else if(position >= lan){
            insertAttail(head, tail, data);
        } else{
            Node* newNode = new Node(data);
            Node* prev = NULL;
            Node* curr = head;
            while (position != 1){
                prev = curr;
                curr = curr->next;
                position--;
            }
            prev->next = newNode;
            newNode->next = curr;
        }
    }

    Node* reverseRec(Node* &curr, Node* &prev){
        if(curr == NULL) return prev;
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        return reverseRec(curr, prev);
        
    }

    void deleteLL(Node* &head, Node* &tail, int position);

    bool detectCycle(Node* &head, Node* &tail);

    void print(Node*head){
           Node* temp = head;
           while(temp != nullptr){
               cout<<temp->data<<"->";
               temp = temp->next;
           }
           cout<<"NULL"<<endl;
    }

    void findMid(Node* &head){
        int n = getlength(head);
        // if(n == 0 || n == 1) return;
        int posi = (n/2) + 1;
        Node* temp = head;
        while(posi != 1){ 
            temp = temp->next;
            posi--;
        }
        cout<<temp->data;
    }
   void findMidBySlowFast(Node* &head){
        Node* fast = head;
        Node* slow = head;
        while(fast != nullptr){
            fast = fast->next;
            if( fast!= NULL){
            fast = fast->next;
            slow = slow->next;
            }
        }
        cout<<slow->data;
   }
    Node* Reverse(Node* &head){
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
bool findPalindrome(Node* head) {
    if (!head || !head->next) return true;

    // Step 1: Find the middle using slow and fast
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Create reversed copy of the second half
    Node* curr = slow;
    Node* reversedCopy = nullptr;

    while (curr) {
        Node* newNode = new Node(curr->data);
        newNode->next = reversedCopy;
        reversedCopy = newNode;
        curr = curr->next;
    }

    // Step 3: Compare original and reversed copy
    Node* first = head;
    Node* second = reversedCopy;
    bool isPalindrome = true;

    while (second) {
        if (first->data != second->data) {
            isPalindrome = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Step 4: Free memory of reversed copy
    while (reversedCopy) {
        Node* next = reversedCopy->next;
        delete reversedCopy;
        reversedCopy = next;
    }

    return isPalindrome;
}

    int main(){
        Node*head = NULL;
        Node*tail = NULL;
        insertAthead(head, tail, 5);
        insertAthead(head, tail, 4);
        insertAthead(head, tail, 2);
        insertAthead(head, tail, 1);
        insertAttail(head, tail, 6);
        insertAttail(head, tail, 7);
        insertAtany(head, tail, 3, 3);
        print(head);
        if(findPalindrome(head)){
            cout<<"plandreom dose exist";
        }else{
            cout<<"plandreom dose not exist";
        }
        // findMid(head);

        // Node* prev = NULL;
        // head = reverseRec(head, tail);
        // print(head);
        
        // if(head->next != NULL && head->next->next){
        //     cout<<"we have single value so loop is not exist";
        // }else{
        //     tail->next = head->next->next;
        // }
        // tail->next = head->next->next;

        // if(detectCycle(head, tail) == 1){
        //     cout<<"Cycle is detected ";
        // } else {
            // cout<<"Cycle is not detected ";
        // }
        // print(head);
        // deleteLL(head, tail, 3);
        // print(head);
        delete head;
    }

// ________________________ delete a LL ________________________
    void deleteLL(Node* &head, Node* &tail, int position){
        if (head == NULL && tail == NULL) {
        cout << "List is empty, nothing to delete" << endl;
        return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        return;
    }

    bool detectCycle(Node* &head, Node* &tail){
        if(head == NULL && tail == NULL) return false;
        Node* fast = head;
        Node* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        slow = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
        Node* currptr = slow;
        Node* temp = fast;
        while (temp->next != currptr){
            temp = temp->next;
        }
        temp->next = NULL; 
    }   
// minor style fix
