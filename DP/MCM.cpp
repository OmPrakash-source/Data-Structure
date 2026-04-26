#include<iostream>
#include<vector>
using namespace std;

int MCMrec(vector<int>arr, int i,int j){
    if(i == j) return 0; // if start == end => single matrix 
    
    int ans = INT16_MAX;
    for(int k=i; k<j; k++){
        //(i,k) first group
        int cost1 = MCMrec(arr, i, k);

        //(k+1,j) second group
        int cost2 = MCMrec(arr, k+1, j);
         
        //curr partition cost
        int currcost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);

        ans = min(ans,currcost);
    }
    return ans;
}

//_________________________ MCM using memo ________________________
    int MCMmemo(vector<int>arr,int st,int ed,vector<vector<int>> &dp){
        if(ed == st) return 0;
        
        int ans = INT32_MAX;
        if(dp[st][ed] != -1){
            return dp[st][ed];
        }
        for(int k=st; k<ed; k++){
            int cost1 = MCMmemo(arr,st,k,dp);
            int cost2 = MCMmemo(arr,k+1,ed,dp);
            int currcost = cost1 + cost2 + (arr[st-1] * arr[k] * arr[ed]);

            ans = min(ans,currcost);
        }
        return dp[st][ed] = ans;
    }

//_________________________ MCM using tabulation ________________________

    int MCMtab(vector<int>arr){ // O(n^3)
        int n =arr.size();
        vector<vector<int>>dp(n,vector<int>(n,INT16_MAX));
        
        for(int i=1;i<n;i++){
            dp[i][i] = 0; // fill all st == ed => 0;
        }
        for(int len=2;len<n;len++){
            for(int i=1;i<= n-len;i++){
                int j = i+len-1;

                for(int k=i;k<j;k++){
                    int cost1 = dp[i][k];
                    int cost2 = dp[k+1][j];
                    int currcost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
                    dp[i][j] = min(dp[i][j],currcost);
                }
            }
        }
        
        return dp[1][n-1];
    }
int main(){
    vector<int>arr = {1, 2, 3, 4, 3};
    int n =arr.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    // cout<<MCMmemo(arr,1,n-1,dp)<<endl;
    cout<<MCMtab(arr)<<endl;
}


// minor style fix
