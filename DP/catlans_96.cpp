// catalan is similer to fibonachi serice it's 1's of 0's have value 1 or catalan(3) = catalan(0)*(2) + catalan(1)*(1) + catalan(2)*(0) 
                                                                        //catalan(3) = 1*2            + 1*1            + 2*1 = 5

#include<iostream>
#include<vector>

using namespace std;

//______________________ catalan with recursion _________________________
int catRec(int n){ // O(2^n)
    if(n == 0||n == 1){
        return 1;
    }
    int ans = 0;
     for(int i=0; i<n; i++){
    //   ans +=     Ci    * Cn-i-1
         ans += catRec(i) * catRec(n-i-1);
    //   0 +=   first     * last;
     }
     return ans;
}

//______________________ catalan with memoization _______________________

int catMemo(int n){ // O(n^2)
    vector<int>dp(n+1,-1);

    if(n == 0||n == 1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 0;
     for(int i=0; i<n; i++){
    //   ans +=     Ci    * Cn-i-1
         ans += catMemo(i) * catMemo(n-i-1);
     }
     return dp[n] = ans;
}

//______________________ catalan with taabulation _______________________
int catTab(int n){
    vector<int>dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){ //ith catalan 
         for(int j=0; j<i; j++){ // 0 to i
            dp[i] += dp[j] * dp[i-j-1]; 
         }
    }
    return dp[n];
}

//__________________________ Count BST's _______________


int main(){
        // for(int i=0; i<=20; i++){
        //      cout << i << " -> "<< catTab(i)<<"\n";
        // } 
        // cout<<endl;
        cout<<catTab(3);
    
    return 0;
}
// minor style fix
