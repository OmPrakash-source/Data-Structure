#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
    /*
    // Stack implementation using array
    class Stack{
        public:
            int *arr;
            int top;
            int size;
            Stack(int size){
                arr = new int[size];
                this->top = -1;
                this->size = size;
            }
            void push(int data){
                if(top == size-1){
                    cout<<"Stack is overflow \n";
                    return;
                }else{
                    top++;
                    arr[top] = data;
                }
            }
            void pop(){
                if(top == -1){
                    cout<<"Stack is underflow\n";
                    return;
                }else{
                    top--;
                }
            }
            bool Isempty(){
                if(top == 1){
                    return true;
                } return false;
            } 
            int gettop(){
                if(top == -1){
                    cout<<"Stack is empty\n";
                    return -1;
                } else {
                    return arr[top];
                }
            }
            int getsize(){
                return top + 1;
            }
            int print(){
                for(int i=0; i<getsize(); i++){
                    cout<<arr[i] <<" ";
                }
            }
    };*/

    //__________________________ using template _______________________
    /* template<class T>
    class Stack{
    public:
        vector<T>vac;
        void push(T data){
            vac.push_back(data);
        }
        void pop(){
            if (vac.empty()) {
                cout << "Stack is underflow\n";
                return;
            }
            vac.pop_back(); 
        }
        bool Isempty(){
            return vac.size() == 0;
        }
        T gettop(){
            if (vac.empty()) {
                cout << "Stack is empty\n";
                return T(); 
            }
            return vac.back();
        } 
    };*/

    // __________________________ using LL __________________________
    //     template<class T>
    // class Stack{
    //         list<T>ll;
    //     public:
    //         void push(T data){
    //             ll.push_front(data);
    //         }
    //         void pop(){
    //             ll.pop_front();
    //         }
    //         T top(){
    //             return ll.front();
    //         }
    //         bool empty(){
    //             return ll.size() == 0;
    //         }
    // };

// --------------------- min stack -----------------------
    class MinStack {
    public:
        stack<int> st;
        stack<int> minSt;
        
        void push(int val) {
            st.push(val);
            if (minSt.empty() || val <= minSt.top()) {
                minSt.push(val);
            }
        }
    
        void pop() {
            if (st.top() == minSt.top()) {
                minSt.pop();
            }
            st.pop();
        }
    
        int top() {
            return st.top();
        }
    
        int getMin() {
            return minSt.top();
        }
    };

    // // reverse a string
    //     void reverse(string str){
    //         stack<char>st;
    //         for(int i=0; i<str.size(); i++){
    //             char temp = str[i];
    //             st.push(temp);
    //         }
    //         cout<<" orignal string: "<< str << endl;
    //         cout<<" reverse: ";
    //         while(!st.empty()){
    //             cout<<st.top();
    //             st.pop();
    //         }
    //         cout<<endl;
    //     }

    // // ~~~~~~~~~~~~~~~~~~~~~~ push at bottom ~~~~~~~~~~~~~~~~~~~~~~~~
    // void pushAtBottom(stack<int>&st, int val){
    //     if(st.empty()){
    //         st.push(val);
    //         return;
    //     }
    //     int temp = st.top();
    //     st.pop();
    //     pushAtBottom(st,val);
    //     st.push(temp);
    // }
    // // reverse a stack
    // void reverseAstack(stack<int>&st){
    //     if(st.empty()){
    //         return;
    //     }
    //     int temp = st.top();
    //     st.pop();
    //     reverseAstack(st);
    //     pushAtBottom(st, temp);
    // }
    // //~~~~~~~~~~~~~~~~~~~~~~~ get middle element ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // void solve(stack<int>&st, int& pos, int &ans){
    //     if(pos == 1){
    //         ans = st.top();
    //         return;
    //     }

    //     // first case jo ham karege
    //     pos--;
    //     int temp = st.top();
    //     st.pop();

    //     //rec
    //     solve(st, pos, ans);

    //     // backtreack
    //     st.push(temp);
    // }
    // int getMiddle(stack<int>&st){
    //     int size = st.size();
    //     int mid = 0;

    //     if(st.empty()){
    //         return -1;

    //     }else{

    //         if(size%2 == 1){
    //             mid = (size / 2) + 1;
    //         } else{
    //             mid = size / 2;
    //         }
    //     }
    //     int ans = -1;
    //     solve(st, mid, ans); 
    //     return ans;
    // }

    // // ~~~~~~~~~~~~~~~~~~~~~~~ insert at sorted stack ~~~~~~~~~~~~~~~~~~~~~~~

    //     void insertAtSoretedStack(stack<int>& st, int val){
    //         if(st.empty() || val < st.top()){
    //             st.push(val);
    //             return;
    //         }
    //         int temp = st.top();
    //         st.pop();
    //         insertAtSoretedStack(st, val);
    //         st.push(temp);
    //     }

    //          // ~~~~~~~~~~~ sort a stack ~~~~~~~~

    //     void sortStack(stack<int>&st){
    //         if(st.empty() || st.size() == 1){
    //             return;
    //         }
    //         int temp = st.top();
    //         st.pop();
    //         sortStack(st);
    //         insertAtSoretedStack(st, temp);
    //     }
    //----------------------- build a two stack using a single array -----------------------
    // class Stack{
    // public:
    //     int *arr;
    //     int top1;
    //     int top2;
    //     int size;
    //     Stack(int size){
    //         this->size = size;
    //         top1 = -1;
    //         top2 = size;
    //         arr = new int[size]; 
    //     }
    //     void push1(int data){
    //         if(top2-top1 == 1){
    //             cout<<"Stack is overflow "<<endl;
    //             return;
    //         }else{
    //             top1++;
    //             arr[top1] = data;
    //         }
    //     }
    //     void push2(int data){
    //         if(top2-top1 == 1){
    //             cout<<"Stack is overflow "<<endl;
    //             return;
    //         }else{
    //             top2--;
    //             arr[top2] = data;
    //         }
    //     }
    //     void pop1(){
    //         if(top1 == -1){
    //             cout<<"Stack is underflow "<<endl;
    //             return;
    //         } else {
    //             // No need to modify arr[top1], just move the top pointer
    //             top1--;
    //         }
    //     }
    //     void pop2(){
    //         if(top2 == size){
    //             cout<<"Stack is underflow "<<endl;
    //             return;
    //         } else{
    //             top2++;
    //         }
    //     }
    //     int gettop1(){
    //         if(top1 == -1){
    //             cout<<"can't access Stack "<<endl;
    //             return -1;
    //         } else {
    //             return arr[top1];
    //         }
    //     }
    //     int gettop2(){
    //         if(top2 == size){
    //             cout<<"can't access Stack "<<endl;
    //             return -1;
    //         } else {
    //             return arr[top2];
    //         }
    //     }
    //     bool empty1(){
    //         return top1 == -1? true : false;
    //     }
    //      bool empty2(){
    //         return top2 == size?true: false;
    //         }   
    // };
// __________________ valid perentisis ____________________
    bool validParenthisis(string str){
        stack<char>st;
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }else{
                if(!st.empty()){
                    if(st.top() == '(' && ch == ')'){
                    st.pop();
                    }else if(st.top() == '{' && ch == '}'){
                        st.pop();
                    }else if(st.top() == '[' && ch == ']'){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }else {
            false;
        }
    }

//___________ remove redundent brackets _____________
    bool redunBrack(string &str){
        stack<char>st;
        for (int i = 0; i < str.size(); i++){
            char ch = str[i];
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }else if(ch == ')'){
                int oprcout = 0;
                while(!st.empty() && st.top() != '('){
                    int temp = st.top();
                    if(temp == '+' ||temp == '-' ||temp == '*' ||temp == '/'){
                        oprcout++;
                    }
                    st.pop();
                }
                // loop end matlab stack ke top pe bas ( bacha hai
                if(!st.empty()) st.pop();
                if(oprcout == 0) return true;
            }
        }
        //agar main loop ke bahar hu matlab har 1 bracket ke liye oprater hai to return false hoga ki redundent bracket nhi hai
        return false;
    }
int main(){
    // Stack st(7);
    // // Stack<int>st;
    // st.push1(3);
    // st.push1(2);
    // st.push1(1);
    // st.push2(7);
    // st.push2(6);
    // st.push2(5);
    // st.push2(4);
    // while(!st.empty1()){
    //     cout<<st.gettop1()<<" ";
    //     st.pop1();
    // }
    // cout<<endl;
    // while(!st.empty2()){
    //     cout<<st.gettop2()<<" ";
    //     st.pop2();
    // }
    // cout<<endl;
    // cout<<st.empty1()<<endl;
    // cout<<st.empty()<<endl;
    

    // string str = "edcba";
    // reverse(str);

    // stack<int>st;
    // st.push(50);
    // st.push(40);
    // st.push(20);
    // st.push(10);
    // insertAtSoretedStack(st, 0);

    // st.push(10);
    // st.push(40);
    // st.push(30);
    // st.push(80);
    // st.push(33);
    // // sortStack(st);

    // // reverseAstack(st);

    // // int ans = getMiddle(st);
    // // cout<<ans;

    // // pushAtBottom(st,4);
    // // while(!st.empty()){
    // //     cout<<st.top()<<" ";
    // //     st.pop();
    // // }
    
    
    
    // // st.push(40);
    // // st.print();
    // // cout<< st.gettop()<<endl;
    // // st.pop();
    // // cout<< st.gettop()<<endl;
    // // st.pop();
    // // cout<< st.gettop()<<endl;
    // // st.pop();
    // // cout<< st.gettop()<<endl;
    // // st.pop();
    // while(!st.empty()){
    //     cout<< st.top()<<" ";
    //     st.pop();
    // } cout<<endl;

    // string str = "({[()]()})";
    string str = "((a+b) * (b+c))";
    if(redunBrack(str)){
        cout<<"Redundent brackets present \n";
    } else{
        cout<<"Redundent brackets not present \n";
    }

}



// minor style fix
