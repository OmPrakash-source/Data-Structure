// take a three number of opration 
// insert, delete, replace

// how many opration's are parfomed to convert str1 to str2 return total number of opration 

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int editDist(string st1,string st2){  // O(n^2)
    int n = st1.length();
    int m = st2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){ // dp[0,1,2,3...][0] = 0,1,2,3...
        dp[i][0] = i;
        dp[0][i] = i; // ye hi kam niche wale me ho ra hai
    }
    // for(int i=0;i<=m;i++){
    //     dp[0][i] = i;   // dp[0][0,1,2,3...] = 0,1,2,3...
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(st1[i-1] == st2[j-1]){
                dp[i][j] = dp[i-1][j-1]; //if equal hai to koi opration nhi
            } else {//if unequal hai to i
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1]));
                      //1 opr hai   // insert       // delete  // replace
            }
        }
    }
    return dp[n][m]; 
}

int main(){
    string str1 = "horse";
    string str2 = "rose";
    cout<<editDist(str1,str2)<<endl;
}
// minor style fix
