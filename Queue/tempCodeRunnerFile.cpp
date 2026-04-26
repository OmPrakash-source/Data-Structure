#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//______________________________ Array to queue ______________________
    class Queue1{
    public:
        int *arr;
        int front, rear, size;
        Queue1(int size){
            this->size = size;
            arr = new int[size];
            front = 0;
            rear = 0;
        }
        void push(int data){
            if(rear == size){
                cout<<"Queue is full\n";
            }else{
                arr[rear] = data; // q me jaha rear hai wo location pe data feed karo or rear ko aage bada do
                rear++; //rear hamesa empty location pe hoga jaha data push huaa hai uske aage
            }
        }
        void pop(){
            if(front == rear){
                cout<<"Queue is empty nothing is pop\n";
            }else{
                cout<<arr[front]<<" is poped\n";

                arr[front] = -1; // array ke front ko mark kardo -1 or aage bada do
                front++;
                if(front == rear){ // agar front or rear same position pe hai to fir se start se start kana hai 
                    front = 0;
                    rear = 0;
                }
            }
        }
        int getfront(){
            if(front == rear) return -1;
            else return arr[front];
        }
        bool empty(){
            return front == rear;
        }
        int getsize(){
            return rear - front; // rear idx - front idx
        }
    };

//______________________________ vector to queue ______________________
    class Queue2{
    public:
        vector<int>arr;
        int rear, front;
        Queue2(){
            rear = 0;
            front = 0;
        }
        void push(int data){
                arr.push_back(data);
                rear++;
        }
        void pop(){
            if(front == rear) cout<<"Queue is empty \n";
            else {
                front++;
                if(front == rear){
                    front = 0;
                    rear = 0;
                }
            }
        }
        int getfront(){
            if(front == rear) return -1;
            else return arr[front];
        }
        bool isEmpty(){
            return front == rear;
        }
    };

//______________________________ circular queue ______________________

    class Cqueue{
        public:
            int front , rear;
            vector<int>arr;
            Cqueue(){
                front = -1;
                rear = -1;
            }
        void push(int data){
            //full
            if(front == rear+1 || (front == 0 && rear == arr.size())){
                cout<<"Queue is full \n";
            }
            //front
            else if(front == -1){
                front = rear = 0;
                arr.push_back(data);
            }
            //circule
            else if(rear == arr.size()-1 && front != 0){
                rear = 0;
                arr.push_back(data);
            }
            // Normar case
            else{
                rear++;
                arr.push_back(data);
            }
        }
        void pop(){
            if(front == -1 && rear == -1){
                cout<<"Queue is empty\n";
            }
            // if single value then move front and rear to -1
            else if(rear == front){
                arr.pop_back();
                rear = front = -1;
            }
            // circule
            else if(front == arr.size()-1){
                arr.pop_back();
                front = 0;
            }
            // normal case
            else{
                arr.pop_back();
                front++;
            }
        }
        int getFront(){
            return arr[front];
        }
        bool isEmpty(){
            return front == -1;
        }
    }; 
// by array and correct 
    class Caqueue{
        public:
            int front , rear, size;
            int *arr;
            Caqueue(int size){
                this->size = size;
                arr = new int[size];
                front = -1;
                rear = -1;
            }
        void push(int data){
            //full
            if(front == rear+1 || (front == 0 && rear == size-1)){
                cout<<"Queue is full \n";
            }
            //front
            else if(front == -1){
                front = rear = 0;
                arr[rear] = data;
            }
            //circule
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[0] = data;
            }
            // Normar case
            else{
                rear++;
                arr[rear] = data;
            }
        }
        void pop(){
            if(front == -1 && rear == -1){
                cout<<"Queue is empty\n";
            }
            // if single value then move front and rear to -1
            else if(rear == front){
                rear = front = -1;
            }
            // circule
            else if(front == size-1){
                front = 0;
            }
            // normal case
            else{
                front++;
            }
        }
        int getFront(){
            return arr[front];
        }
        bool isEmpty(){
            return front == -1;
        }
    }; 

// reverse a queue
    void reverse(queue<int>&q){
        if(q.empty()){
            return;
        }
        int t = q.front();
        q.pop();
        reverse(q);
        q.push(t);
    }
    // using stack

    void reverseQusingstack(queue<int>&q){
        stack<int>st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
    }

// reverse first K element 
    void reverseFirstKelement(queue<int>&q, int posi){
        stack<int>st;
        int n = q.size();
        int k = posi;
        if(posi <= 0 || posi > n){
            return;
        }
        // k element ko stack me dal diya
        while(k--){
            st.push(q.front());
            q.pop();
        }
        // stack se queue me reverse kar ke wapas dal diya
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        // jo n-k element bache the wo queue me piche side dal diye 
        int lasst = n-posi; // 6-4 = 2
        while(lasst--){
            q.push(q.front());
            q.pop();
        }
        // for (int i = 0; i < n - posi; ++i) {
        //     q.push(q.front());
        //     q.pop();
        // }
    }

// _______________________ interleave first and second half _______________________
    void interleaveQueue(queue<int>&q){
        queue<int>q1;
        int mid = q.size() / 2;
        while(mid--){
            q1.push(q.front());
            q.pop();
        }
    
        while(!q1.empty() && !q.empty()){
            q.push(q1.front());
            q1.pop();
            q.push(q.front());
            q.pop();
        }
        // agar size odd hai to top pe extra element hoga to sif usko front se pop kar ke back me dal diya
        if(q.size()& 1){
            q.push(q.front());
            q.pop();
        }
    }
//____________________________ first non repeting char ___________________________
    // jo element repet na ho usko print karna hai or wo q ke top pe ho

    void nonRepetchar(string str, string &ans){
        int freq[26] = {0};
        queue<char>q;
        for(char ch:str){
            freq[ch - 'a']++; // a = 97 so (97-97 = 0) idx
            q.push(ch);
            while(!q.empty()){
                if(freq[q.front() - 'a'] > 1){
                    q.pop();
                }else{
                    ans.push_back(q.front());
                    break; // yaha ans mill gaya matlab break kardo
                }
            }
            if(q.empty()){
                ans.push_back('#');
            }
        }
        
    }
int main(){
    // Cqueue c;
    // c.push(30);
    // c.push(40);
    // c.push(50);
    // // Caqueue cq(3);
    // // cq.push(30);
    // // cq.push(40);
    // // cq.pop();       // remove 30
    // // cq.push(50);    // wrap around if needed
    // cout << c.getFront() << endl;

    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    // reverse(q);
    // reverseFirstKelement(q,7);
    // interleaveQueue(q);
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

    // cout<<endl;
    string str = "aabc";
    string ans = "";
    nonRepetchar(str,ans);
    cout<<ans;
    
}