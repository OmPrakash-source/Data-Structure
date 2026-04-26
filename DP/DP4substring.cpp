#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;
// longest common substring
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
    
// ________________________________ longest increassing subsequence___________________
int LIS(vector<int>arr){
    unordered_set<int>s(arr.begin(),arr.end());
    // insert arr in unordered set only uniqe value insert
    
    // for(int el : s){
    //     s.insert(el);
    // }

    vector<int>arr2(s.begin(),s.end()); // push el of vector1 to vector2
    // for(int el : s){
    //     arr2.push_back(el);
    // }
    sort(arr2.begin(),arr2.end()); // ascd order me sorted

    //LIS => LCS
    int n = arr.size();
    int m = arr2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1] == arr2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    // string str1 = "abxyzpqcde";
    // string str2 = "axyzpqgce";
    // cout<< logComStr(str1,str2)<<endl;

    vector<int>arr = {50,3,10,7,40,80};
    cout<<LIS(arr);
}
// minor style fix
