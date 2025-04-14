// find if wildcard pattern can be matched with a text.The wildcard pattern can include the characters '?' or '*' 

// ? - matched any singal charecter
// * - matched any sequence of characters(includeing the empty sequence) 


#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isMatch_44(string t,string p){
    int n = t.length();
    int m = p.length();
    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    dp[0][0] = true;

    // when text is empty and pattern have value
    for(int j=1;j<=m;j++){ 
        if(p[j-1] == '*'){
            dp[0][j] = dp[0][j-1];
        } else { // ? or eng char
            dp[0][j] = false;
        }
    } 

    // if text is not empty of pattern is empty
    for(int i=1;i<=n;i++){ 
        dp[i][0] = false;
    }
    // final filling 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //last char = strlast char|| last char = '?'
            if(t[i-1] == t[j-1] || p[j-1] == '?'){ // last == char or ? 
                dp[i][j] = dp[i-1][j-1]; 
            } else if (p[j-1] == '*'){ // last == *
                dp[i][j] = dp[i-1][j] || dp[i][j-1]; // * = more then ine engchar || * = " " (empty string)
            } else {
                dp[i][j] = false; //if last = eng char but diff 
            }
        }
    }
    return dp[n][m];
}
int main(){
    string str1 = "abaaabab";
    string str2 = "?**b*ab*"; // that is imp test case
    cout<<isMatch_44(str1,str2);
    return 0;
}

