// canonical value's
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 0(n)
int coins (vector<int>coin , int V){
    int n = coin.size();
    int ans = 0;
    for(int i=n-1; i>=0; i--){
        if(coin[i] <= V){
            ans += V / coin[i]; // How much coin is used
            cout<<coin[i]<<endl;
            V = V % coin[i];    // total remaning coin
        }
    }
    cout<<" Total coin use = "<<ans;
    return ans;
}

int main(){
    vector<int>coin={1,2,5,10,20,50,100,500,2000};
    int V = 999;
    coins(coin , V);
}
// minor style fix
