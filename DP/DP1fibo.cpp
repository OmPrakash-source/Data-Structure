#include<iostream>
#include<vector>
using namespace std;

// fibonachi using extra data structure (vector)
// O(n)
    int fibDP( int n, vector<int>&f){
        if(n ==0 || n == 1){
            return n;
        }
        if(f[n] != -1){
            return f[n];
        }
        f[n] = fibDP(n-1,f) + fibDP(n-2,f);
        return f[n];
    }
// clibing stair's Problem using recuesion

        int Ways(int n){
           if (n == 1 || n == 0){
              return 1;
           }
       
           return Ways(n-1) + Ways(n-2);
           // for one jump + two jump
        }

// clibing stair's Problem using memoization

// Ways(6)
// ├── Ways(5)
// │   ├── Ways(4)
// │   │   ├── Ways(3)
// │   │   │   ├── Ways(2)
// │   │   │   │   ├── Ways(1) → 1   (Base case)
// │   │   │   │   ├── Ways(0) → 1   (Base case)
// │   │   │   │   → Ways(2) = 2
// │   │   │   ├── Ways(1) → 1   (Base case)
// │   │   │   → Ways(3) = 3
// │   │   ├── Ways(2) → 2  (Memoized)
// │   │   → Ways(4) = 5
// │   ├── Ways(3) → 3  4(Memoized)
// │   → Ways(5) = 8
// ├── Ways(4) → 5  (Memoized)
// → Ways(6) = 13
// O(n) time and O(n) space complexity
// using memoization
        int Ways(int n,vector<int>&f){
            if(n == 1||n == 0){
                return 1;
            }
            if(f[n] != -1){
                return f[n];
            }
            f[n] = Ways(n-1,f) + Ways(n-2,f);
            return f[n];
        }

// using tabulation botton up approce 
        void climbWithTab(int n){  // if total 4 jump allow
            vector<int>dp(n+1,0);
            dp[1] = 1;
            dp[0] = 1;
            dp[2] = 2;
            for(int i=3;i<=n;i++){
                dp[i] = dp[i-1] + dp[i-2]+ dp[i-3] ;
            }
            cout<< dp[n] << endl;
        }
int main(){
    int n = 4;
    vector<int>f(n+1,-1);
    // cout<<fibDP(n,f)<<endl;

    cout<<Ways(n,f)<<endl;

    climbWithTab(n);
}