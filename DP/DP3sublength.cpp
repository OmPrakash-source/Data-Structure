#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

//_________________ if size is equal to all string _____________

    void LCS(string st1,string st2){
        int n = st1.length();
        int m = st2.length();
        queue<char>q;
        for(int i = 0;i<n;i++){ // O(n)
            char c = st1[i];
            q.push(c);
        }
        while (!q.empty()){ // O(n logn)
            for(int i=0;i<n;i++){
                if(st2[i] == q.front()){
                    cout<<q.front();
                    q.pop();
                 } else {
                    q.pop();
                    break;
                }
            }
        }
    }

// ________________ using recursion O(2 ^ n+m)_____________
    int recLCS(string st1,string st2){
        int n = st1.length();
        int m = st2.length();

        if(m<=0||n<=0){
            return 0;
        }
        if(st1[n-1] == st2[m-1]){
            // agar ye call lagi to equal hai so +1
            return 1 + recLCS(st1.substr(0,n-1),st2.substr(0,m-1)); // substr remove string from last substr(start-point,length)
        }   else{ // nhi to done me se 1-1 kam karke check jo bada wo return
            return max(recLCS(st1.substr(0,n-1),st2.substr(0,m)),recLCS(st1.substr(0,n),st2.substr(0,m-1)));
        }
        
    }

// ________________ using memoization O(n*m)_____________
    int memoLCS(string st1,string st2){
        int n = st1.length();
        int m = st2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(m<=0||n<=0){
            return 0;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(st1[n-1] == st2[m-1]){
            return dp[n][m] = 1 + memoLCS(st1.substr(0,n-1),st2.substr(0,m-1)); 
        } else{ 
            return dp[n][m] = max(memoLCS(st1.substr(0,n-1),st2.substr(0,m)),memoLCS(st1.substr(0,n),st2.substr(0,m-1)));
        }
    }

// ________________ using tabulation O(n*m)_____________

    int tabLCS(string st1,string st2){
        int n = st1.length();
        int m = st2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){

                if(st1[i-1] == st2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][m];
    }
int main(){
    string str1 = "abcde";
    string str2 = "abgce";
    LCS(str1,str2);
}
// minor style fix
