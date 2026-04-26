#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

// leet code 1021 
 string removeOuterParentheses(string s) {
        string result;
        stack<char> st;

        for (int i=0;i<s.size();i++) {
            char c = s[i];
            if (c == '(') {
                if (!st.empty()) {
                    result += c;
                }
                st.push(c);
            } else { // c == ')'
                st.pop();
                if (!st.empty()) {
                    result += c;
                }
            }
        }

        return result;
    }

// celeblity problem (in one party every one know celeblity but celeblity can not know any one so we want to find celeblity )
 int celeblity_found(vector<vector<int>>& M){
    stack<int>st;
    for(int i=0;i<M.size(); i++){
        st.push(i);
    }
    
    while(st.size() > 1){
        int a = st.top(); st.pop(); // first a = 2
        int b = st.top(); st.pop(); // and b = 1
        if(M[a][b] == 1){ // if a know b then a is not celeblity
            st.push(b); //may be b is celeblity
        }else{
            st.push(a);
        }
    }
    if (st.empty()) return -1;

    int candidate = st.top();
    for(int i=0; i< M.size(); i++){  
        if(i != candidate){    
        //if(some one not know cel. || cel. know some one )
            if(M[i][candidate] == 0 || M[candidate][i] == 1){
                return -1;
            }
        }
    }
    return candidate;
 }

// reveerse an string using stack 
void revStr(string str){
    stack<char>st1;
    stack<char>st2;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        st1.push(ch);
    }
    while(!st1.empty()){
        cout<<st1.top();
        int temp = st1.top();
        st2.push(temp);     // 1 stack se dusre stack me enter kar rahe hai
        st1.pop();
    }
    cout<<endl;
    while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
}
int main(){
    string str = "123456789";
    vector<vector<int>>M = {{1, 0, 1},
                            {0, 1, 1},
                            {0, 0, 0}};
    cout<<celeblity_found(M);
    return 0;
}
