#include<iostream>
#include<vector>
using namespace std;


// ____________________ recursion ____________________

int knapsack(vector<int>val,vector<int>wt,int W,int n){
    if(W == 0 || n <= 0 ) return 0;
    int itemwt = wt[n-1]; // last idx ka weight
    int profit = val[n-1];
    if(W >= itemwt){
        // item include
        int ans1 = knapsack(val,wt,W-itemwt,n-1) + profit;

        //item exclude
        int ans2 = knapsack(val,wt,W,n-1);

        return max(ans1,ans2);
    } else {
        return knapsack(val,wt,W,n-1);
    }
}

// ____________________ memoization ____________________
int knapsackMemo(vector<int>val,vector<int>wt,int W,int n,vector<vector<int>>&dp){
    if(W == 0 || n <= 0 ) return 0;

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    int itemwt = wt[n-1]; // last idx ka weight
    int profit = val[n-1];
    if(W >= itemwt){
        // item include
        int ans1 = knapsackMemo(val,wt,W-itemwt,n-1, dp) + profit;

        //item exclude
        int ans2 = knapsackMemo(val,wt,W,n-1,dp);

        return dp[n][W] = max(ans1,ans2);
    } else {
        return dp[n][W] = knapsackMemo(val,wt,W,n-1,dp);
    }
}

// ____________________ tabulation ____________________
int knapsackTab(vector<int>val,vector<int>wt,int W,int n){

    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            int itemwt = wt[i-1];
            int itemval = val[i-1];

            if(itemwt <= j){
                dp[i][j] = max(itemval + dp[i-1][j-itemwt] , dp[i-1][j]);
                //                                include  , exclude
            } else { // exclude
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][W];
}
int main(){
    vector<int>val = {15,14,10,45,30};
    vector<int>wt = {2,5,1,3,4};
    int W = 7;
    int n = val.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));

    // 2D vector        (nis last idx+1 , W is last idx+1, show -1)
    // cout<<knapsackMemo(val,wt,W,n,dp)<<endl;;

    // for(int i= 0;i<n+1;i++){
    //     for(int j=0;j<W+1;j++){
    //         cout<< dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<knapsackTab(val,wt,W,n);
    return 0;
}