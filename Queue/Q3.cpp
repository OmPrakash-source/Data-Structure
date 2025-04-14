    #include<iostream>
    #include<stack>
    #include<queue>
    #include<string>
    using namespace std;
// create a queue using a 2 stack 
        class Queue{
        stack<int>s1;
        stack<int>s2;
        public: 
        void push(int data){
            //s1 -> s2
            while(!s1.empty()){
                cout << "Moving " << s1.top() << " from s1 to s2" << endl;
                s2.push(s1.top());
                s1.pop();
            }
            cout << "Pushing " << data << " to s1" << endl;
            s1.push(data);
            //s2->s1  
            while(!s2.empty()){
                cout << "Moving " << s2.top() << " from s2 to s1" << endl;
                s1.push(s2.top());
                s2.pop();
            }
        }
        void pop(){
            s1.pop();  
        }
        int front(){
            return s1.top();
        }
        bool empty(){
            return s1.empty();
        }
    };
// create a stack using a 2 queue 
    class Stack { 
        queue<int> q1 ,q2;
        public:
        void push(int data){
            // q1 -> q2
            while(!q1.empty()){
                cout<< q1.front()<< " is move q1 -> q2\n";
                q2.push(q1.front());
                q1.pop();
            }
            cout<< "moving "<< data<< " from q1\n";
            q1.push(data);

            while(!q2.empty()){
                cout<< q2.front()<< " is move q2 -> q1\n";
                q1.push(q2.front());
                q2.pop();
            }
        }
        void pop(){
            q1.pop();
        }
        int top(){
            return q1.front();
        }
        bool empty(){
            return q1.empty();
        }
    };

// ________________________________________ First non repeating char ______________________________________
   // Function to print the first non-repeating character at each step
void Nonrepeat(string str) {
    queue<char> q;               // Queue to store characters in order of their arrival
    int freq[26] = {0};          // Frequency array to track the count of each character

    // Traverse through each character in the string
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];        // Current character in the string
        q.push(ch);              // Add the character to the queue
        int idx = ch - 'a';
        freq[idx]++;        // Increment the frequency of the character

        // Remove characters from the front of the queue if they are repeated
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();             // Remove repeated characters from the queue
        }

        // If the queue is empty, no non-repeating character exists at this step
        if (q.empty()) {
            cout << "-1\n";
        } else {
            // Otherwise, the front of the queue is the first non-repeating character
            cout << q.front() << "\n";
        }
    }
 }
//_________________________________________  Interleave ______________________________________

    void Interleave(queue<int>org){
        queue<int>q1,q2;
        int size = org.size();
        int halfsize = (size / 2) + 1;
        // to half a list into both Queue org or q1
        while(!org.empty() && org.front() != halfsize){
            q1.push(org.front());
            org.pop();
        }
        // move data one by one both queue 
        while(!org.empty() && !q1.empty()){
            q2.push(q1.front());
            q1.pop();
            q2.push(org.front());
            org.pop();
        }
        while(!q2.empty()){
            cout<<q2.front()<<" ";
            q2.pop();
        }

    }
int main() {
    // string str = "aabccxb";      // Input stringl
    // Nonrepeat(str);              // Call the function
    // queue<int>q;
    Queue q;
    for(int i = 1 ; i<=10 ; i++){
       q.push(i);
    }
    for(int i = 1 ; i<=10 ; i++){
        cout<<q.front();
        q.pop();
     }
    // Interleave(q);
}