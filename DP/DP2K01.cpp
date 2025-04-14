#include<iostream>
#include<vector>
using namespace std;

bool targetSum(vector<int>nums,int target){
    int n = nums.size();

    if(target <= 0|| n <= 0) return 0;
    
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    for (int i = 1; i <= n; i++){   //for val
        for (int t = 0; t <= target; t++){  // for target
            if(nums[i-1] <= t){ // weight check
                dp[i][t] = max(nums[i-1]+dp[i-1][t-nums[i-1]],dp[i-1][t]); // nums[i-1] is weight or value both
            } else {
                dp[i][t] = dp[i-1][t];
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int t = 0; t <= target; t++){
            cout<<dp[i][t]<<" ";
        }
        cout<<endl;
    }
        return dp[n][target]==target;
    
}

    int coinChange(vector<int>coin,int amount){
        int n = coin.size();
        int ans = 0; // iski koi value nahi hai
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        if(amount <= 0 || n <= 0){
            return 0;
        }
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if( coin[i-1] <= j){
                    dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j]; // there we let a i in lnclusion becouse unlimited coins of each 
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

// ______________________ Pipe Cutting ________________________ 
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
        if(size >= currlenght){
            return dp[n][size] = max(profit + pipeCutting(Profit,length,size-currlenght,n),pipeCutting(Profit,length,size,n-1));
        } else {
            return dp[n][size] = pipeCutting(Profit,length,size,n-1);
        }
    } 

    int pipeCutting(vector<int>profit, vector<int>length, int W){
        int n = profit.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));

        for(int i=1;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(length[i-1] <= j){
                    dp[i][j] = max(profit[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
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
    // vector<int>nums = {1,2,5,10,20,50,100,200,500,2000};
    // int target = 250; 
    // cout<< coinChange(nums,target);

    vector<int>val = {1,5,1,1,1,1,1,1};
    vector<int>len = {2,2,3,10,5,6,7,8};
    int size = 8;
    int n = val.size();

    // cout<<pipeCutting(val,len,size);
    cout<<minPar(len);

    //1547
}