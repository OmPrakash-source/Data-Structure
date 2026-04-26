#include<iostream>
#include<vector>
using namespace std;
 int fiboBymemo(int n){
    if(n == 0 || n == 1) return n;
    vector<int>dp(n+1, -1);
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fiboBymemo(n-1) + fiboBymemo(n-2);
    return dp[n];
 }

 int fiboByteb(int n){
    vector<int>DP(n+1, 0);
    DP[0] = 0;
    DP[1] = 1;
    for(int i=2; i<=n; i++){
        DP[i] = DP[i-1] + DP[i-2];
    }
    return DP[n];
 }
int main(){
    int n;
    cin>>n;
    cout<<fiboByteb(n);

}

// minor style fix
