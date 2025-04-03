#include<iostream>
#include<vector>
#include<string>
using namespace std;

int logComStr(string st1,string st2){
    int n = st1.length();
    int m = st2.length();
    int ans = 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(st1[i-1]==st2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}
int main(){
    string str1 = "abcde";
    string str2 = "abgce";
    cout<< logComStr(str1,str2)<<endl;
}