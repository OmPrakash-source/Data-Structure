#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    string str = "123456789";
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
    cout<<"st 2 ka top "<<st2.top();
    return 0;
}