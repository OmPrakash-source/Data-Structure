#include<iostream>
#include<vector>
using namespace std;

// time O(3N) space O(2N)

vector<int> prefix(vector<int>arr){ //left se har index ki max value nikalegi 
    vector<int>pre(arr.size());
    pre[0] = arr[0];
    for(int i=1; i<arr.size(); i++){
        pre[i] = max(arr[i], pre[i-1]);
    }
    return pre;
}
vector<int> suffix(vector<int>arr){ //right se har index ki max value nikalegi 
    vector<int>suf(arr.size(),-1);
    int n = arr.size()-1;
    suf[n] = arr[n];
    for(int i=n-1; i>=0; i--){
        suf[i] = max(arr[i], suf[i+1]);
    }
    return suf;
}
void rainWater(vector<int>nums){
    vector<int>pre = prefix(nums);
    vector<int>suf = suffix(nums);
    
    int total = 0;
    for(int i=0;i<nums.size();i++){
        int left = pre[i]; int right = suf[i];
        if(nums[i] <= left && nums[i] <= right){
            total += min(left,right) - nums[i];
        }
    }
    cout<< total;
}

int moreOptimalTrap(vector<int>nums){
    int l=0,r=nums.size()-1,total= 0, lmax =0, rmax=0;
    while(l < r){
        // agar left smaller hai to right tak to water bhar sakte hai
        if(nums[l] <= nums[r]){
            // ager left me curr left se badi value hai to pani bhar sakte hai
            if(lmax > nums[l]){
                total += lmax - nums[l]; // left ki badi value se curr idx ki value ke barabar pani aayga
            }else{  // agar left me koi value max nhi hai curr idx to max ko update 
                lmax = max(lmax,nums[l]);
            }
            l++; 
        // ager right smaller hai left se to matlab left ke barabar water fill kar sakte hai 
        }else{
            if(rmax > nums[r]){
                total += rmax - nums[r];
            }else{
                rmax = max(rmax, nums[r]);
            }
            r--;
        }
    }
    return total;
}
int main(){

    vector<int>arr {0,1,0,2,1,0,1,3,2,1,2,1};
   cout<< moreOptimalTrap(arr);
}
// minor style fix
