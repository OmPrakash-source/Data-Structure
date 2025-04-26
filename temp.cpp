#include<iostream>
#include<vector>
using namespace std;

int fibo(int n){
    // if(n == 0 || n == 1) return n;
    vector<int>dp(n+1,0);
    // if(dp[n] != -1){
    //     return dp[n];
    // }
    // dp[n] = fibo(n-1) + fibo(n-2);
    // cout<<endl;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    vector<int>arr = {1,2,3,4,5,6};
    cout<<fibo(4)<<endl;
}