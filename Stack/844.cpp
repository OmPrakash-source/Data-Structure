// if # apare in string then delete one string element which have before #

#include<iostream>
#include<string>
#include<stack>
using namespace std;
void reverse(string &result){
    int st = 0;
    int ed = result.size() - 1;
    while(st < ed){
        char temp = result[st];
        result[st] = result[ed];
        result[ed] = temp;
        st++;
        ed--;
    }
}

string halper(string str){
    stack<char>st;
    for( char ch : str){
        if(ch == '#'){
            if(!st.empty()) st.pop();
        }else{
            st.push(ch);
        }
    }
    string result;
    while(!st.empty()){
        result += st.top(); // yaha result me ulti string aai hai to reverse karna hai
        st.pop();
    }
    reverse(result);
    return result;
}
bool compear_string(string s, string t){
    return halper(s) == halper(t);
}

int main(){
    string s = "ab#c";
    string t = "ad#c";
    cout<< compear_string(s, t);
    return 0;
}
// minor style fix
