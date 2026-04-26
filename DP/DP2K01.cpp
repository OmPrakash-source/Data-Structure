#include<iostream>
#include<vector>
using namespace std;
   
// __________________________ Knapsack Problem ________________________
    // 0-1 Knapsack using memoization
    int knapsackmemo(vector<int>val, vector<int>wat, int W, int n){
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        if(n == 0||W == 0){
            return 0;
        }
        int currprofit = val[n-1];
        int currwat = wat[n-1];

        if(currwat <= W){
            //include
            int ans1 = knapsackmemo(val, wat, W-currwat, n-1);
            //exclude
            int ans2 = knapsackmemo(val, wat, W, n-1);
            dp[n][W] =  max(ans1,ans2);
        } else{
            dp[n][W] = knapsackmemo(val, wat, W, n-1);
        }
        return dp[n][W];
    }

// unbounded knapsack using memoization
    int ubKnapsack(vector<int>val, vector<int>wt, int W, int n, vector<vector<int>>&dp){
        if(n == 0 || W == 0){
            return 0;
        }
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        int currval = val[n-1];
        int currwat = wt[n-1];
        if(currwat <= W){
            dp[n][W] = max(ubKnapsack(val, wt, W-currwat, n, dp),ubKnapsack(val, wt, W, n+1, dp));
        } else {
            dp[n][W] = ubKnapsack(val, wt, W, n+1, dp);
        }     
        return dp[n][W];
    }
bool targetSum(vector<int>nums,int target){
    int n = nums.size();

    if(target <= 0|| n <= 0) return 0;
    
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    for (int i = 1; i <= n; i++){   //for val
        for (int t = 0; t <= target; t++){  // for Weight
            if(nums[i-1] <= t){ // weight check
                dp[i][t] = max(nums[i-1]+dp[i-1][t-nums[i-1]],dp[i-1][t]); // nums[i-1] is weight or value both
            } else {
                dp[i][t] = dp[i-1][t];
            }
        }
    }
        return dp[n][target]==target;
    
}
// ______________________ Pipe Cutting ________________________ 

    
    int pipeCutting(vector<int>profit, vector<int>length, int W){
        int n = profit.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));

        for(int i=1;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(length[i-1] <= j){
                    dp[i][j] = max(profit[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
                                    //unbounded i becouse unlimited
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for(int i=1;i<=n;i++){
           for(int j=1;j<=W;j++){
                cout<<dp[i][j]<<" ";
           }
           cout<<endl;
        }
        return dp[n][W];
    }

    int pipeCutting(vector<int>Profit, vector<int>length, int size, int n){
        vector<vector<int>>dp(n+1,vector<int>(size+1,-1));
        if(n <= 0 || size <= 0){
            return 0;
        }
        int currlenght = length[n-1];
        int profit = Profit[n-1];
        
        if(dp[n][size] != -1){
            return dp[n][size];
        }
            int skip = pipeCutting(Profit,length,size,n-1);
            int take = INT16_MIN;
            if(currlenght <= length[n]){
                profit + pipeCutting(Profit,length,size-currlenght,n);
            }
            return dp[n][size] = max(take, skip);
    } 

    int pipeCuttingHelper(vector<int> &price,vector<vector<int>>&dp,int N,int idx){
        if(idx == 0){
            return N*price[idx];
        }
        if(dp[idx][N] != -1) return dp[idx][N];
        int skip = 0 + pipeCuttingHelper(price,dp,N, idx-1);
        int take = INT32_MIN;
        int rodlength = idx-1; // there length is IDX not value or pre defind
        if(rodlength <= N){
            take = pipeCuttingHelper(price,dp,N-rodlength, idx);
        }
        return dp[idx][N] = max(take, skip);
    }
    int pipeCutting(vector<int> &price,int N){
        vector<vector<int>>dp(N,vector<int>(N+1, -1));
    }


//___________________ coin chcange by memoization ___________________
    
    int coinchangeMemo(vector<int>coin, int amount, int n, vector<vector<int>>&dp){
        if(n<=0 ) return 0;
        if( amount==0 ) return 1;
        if(dp[n][amount] != -1) return dp[n][amount];
        int currwt = coin[n-1];
        if(currwt <= amount){
            return dp[n][amount] = coinchangeMemo(coin, amount - currwt, n, dp) + coinchangeMemo(coin, amount, n-1, dp);
        } else {
            return dp[n][amount] = coinchangeMemo(coin, amount, n-1, dp);
        }
    }
// by tabulation 
    int coinChange(vector<int>coin,int amount){
        int n = coin.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        // agar coin hai par koi value nhi hai 
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if( coin[i-1] <= j){
                    dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j]; // there we let a i in lnclusion becouse unlimited coins of each 
                             // add               // skip
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(int i = 1;i<=n;i++){
        //     for(int j=1;j<=amount;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][amount];
    }

// ___________________ minmum Partitioning ______________
    int minPar(vector<int>nums){
        int totsum = 0;
        // sum of all numbers
        for(int el : nums){
            totsum += el;
        }
        int n = nums.size();
        int w = totsum/2;
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        //0-1 knapsak
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(nums[i-1] <= j){ //idx(0) <= weight
                    //dp     = max(include, Exclude )
                    dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]],dp[i-1][j]);
                    //            wt add + [decrease size][wt-used wt],[decrease size][wt]   
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int grp1Sum = dp[n][w];
        int grp2Sum = totsum - dp[n][w];
        return abs(grp1Sum - grp2Sum);
    }

int main(){ 
    vector<int>coin = {1,2,5,10,20,50,100,200,500,2000};
    // vector<int>nums = {1,2,5,9,20,5,9,10,11,18,19};
    // int target = 9; 
    // cout<< targetSum(nums,target);
    int n = coin.size();
    int amount = 5;
    vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
    cout<< coinchangeMemo(coin,amount,n,dp);
    // vector<int>val = {1,5,1,1,1,1,1,1};
    // vector<int>len = {2,2,3,10,5,6,7,8};
    // int size = 8;
    // int n = val.size();

    // // cout<<pipeCutting(val,len,size);
    // cout<<minPar(len);

    //1547
}