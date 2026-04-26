    #include<iostream>
    #include<string>
    #include<stack>
    using namespace std;
// _____________________________________ check redundenct of breacket ____________________________________________
    bool redundenct(string stk){
        stack<char> st;
        for(int i = 0 ; i<stk.length() ; i++){
            char ch = stk[i];
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
                st.push(ch);
            }
            else if (ch == ')'){
                int opretor = 0;
                while(!st.empty() && st.top()!= '('){
                    char temp = st.top();
                    if(temp == '+' || temp == '*' || temp == '-' || temp == '/' ){
                        opretor ++;
                    }
                    st.pop(); // yaha pe Jo bhi opretor mila usko pop kiya
                }
                // ya to stack.empty ya st.top() == ) ho
                // or stack ke top par 1 ( breacket hoga
                if (!st.empty() && st.top() == '(') {
                st.pop(); // yaha pe ( ye brecket pop hoga 
                }
                if(opretor==0){
                    return true; //-----------------------> paihle to check kare yahi return kar dega TRUE  
                }
            }
        }
        return false; //-----------------------> ya to false 
    }

// _________________________________________ check valid parentheces ______________________________________________
    bool parentheces(string s){
        stack<int>st ;
        for(int i=0;i<s.length();i++){
            char ch = s[i];   //--------------------------> copy each string value in charecter ch 
            if(ch == '(' || ch == '{' || ch == '[' ){
                st.push(ch);  //--------------------------> Agar open parentheses hai to stack me enter kar do 
            }
            else {
                if(!st.empty()){ //-----------------------> paihle check kare stack  khali hai kya 
                    if(ch == ')' && st.top()=='('){
                        st.pop();
                    }
                    else if(ch == '}' && st.top()=='{'){
                        st.pop();
                    }
                    else if(ch == ']' && st.top()=='['){
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {      //-------------------> paihle check kare stack khali hai kya agar ha to return 
                    return false;
                }
            }
        }
        return st.empty();  //-----------------------> yaha aa gaye matlab stack khali hai to usko return kar do
    }

    // 1021 outermost parentesis 
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans = "";
        for(char ch : s){
            if(ch == '('){
                if(!st.empty()){
                    ans += ch;
                }
                st.push(ch);
            }else{
                st.pop();
                if(!st.empty()){
                    ans += ch;
                }
            }
        }
    return ans;
    }
    int main(){
        // string stk = "((a+b)-(c*d))";
        // bool ans = redundenct(stk);

        string st = "({[]})";
        bool ans = parentheces(st);
        if(ans){
            cout<<" Valid parentheces \n";
        }
        else{
            cout<<" Invalid parentheces \n";
        }
    }