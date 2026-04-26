#include<iostream>
#include<vector>
using namespace std;

int stock(vector<int>arr,int n){
    int buyprice = INT32_MAX;
    int maxprofit = 0;
    for(int i=0;i<n;i++){
        if(buyprice < arr[i]){ //agar buy profit kam hai today se to sell ki planning
            int profit = arr[i] - buyprice; 
            maxprofit = max(profit,maxprofit);
        } else{
            buyprice = arr[i]; //agar buyprice jyada hai to buy ki planning
        }
    }
    return maxprofit;
}
int main(){
    vector<int>arr = {7,1,5,3,6,4};
    int n = arr.size();
    cout<<stock(arr,n);

}
// minor style fix

// final cleanup pass
