    #include<iostream>
    #include<stack>
    #include<queue>
    using namespace std;
//______________________________ circular queue ______________________________
    class Queue{
        int *arr;
        int currSize;
        int capacity;
        int f , r ;
        public:
        Queue( int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            currSize = 0;
            r = -1; 
            f = 0;
        }

         ~Queue() {
        delete[] arr;
        }
        void push(int data){
            if(currSize == capacity){
                cout<<"Queue is full \n";
                return;
            }
            r = (r+1) % capacity;   // formula that usse to index is not greaterthen size
            arr[r] = data;
            currSize ++ ;
            cout << "Pushed: " << data << " at index " << r << endl;
        }

        void pop(){
            if(currSize == 0 ){
                cout<<"Queue is empty \n";
                return;
            }
            cout << "Popped: " << arr[f] << " from index " << f << endl;
            f = (f+1) % capacity;
            currSize--;
        }
        int front(){
            if (currSize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
            return arr[f];
        }

        bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return currSize == capacity;
    }
    };
//_______________________________ reverse an queue _________________________________
    void reverse(queue<int>q){      //  O(n)
        stack<int>st;
        while(!q.empty()){
            st.push(q.front()); // | 1,2,3,4,5,6 -> in stack -> 6,5,4,3,2,1
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top()); // | 6,5,4,3,2,1 -> st.top() -> 6,5,4,3,2,1
            st.pop();
        }
        while(!q.empty()){
            cout<<q.front()<<" ,";
            q.pop();
        }
    }

    int main(){
        Queue q(5);
        //  queue<int>q;
         q.push(2);
         q.push(3);
         q.push(4);
         q.push(5);
        //  cout<< "Front: "<<q.front() <<endl;   // 2
        //  q.pop();   // 2 ,size 4
        //  cout<< "Front: "<<q.front() <<endl;   // 3
        //  q.pop();   // 3 ,size 3
        //  cout<< "Front: "<<q.front() <<endl;   // 4
        //  q.push(1); // Queue is now: [4, 5, 1]
        //  q.push(5); // Queue is now: [4, 5, 1 ,5]
        //  q.push(2); // Queue is now: [4, 5, 1 ,5 ,2] ,size 5 
        // cout<<"after reverse \n";
        // reverse(q);
        // cout<<endl;
        // cout<<"befour reverse \n";
        // while(!q.empty()){
        //     cout<<q.front();
        //     q.pop();
        // }

        q.push(23);
        q.pop();
        cout<<q.front();
    }
// minor style fix
