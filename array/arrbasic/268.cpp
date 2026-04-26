#include<iostream>
#include<vector>
using namespace std;

int usingXor(vector<int>arr){
    int ans = 0;
    int XOR1 = 0, XOR2 = 0;

    for(int i=0; i<arr.size(); i++){
        XOR1 = XOR1 ^ arr[i];
        XOR2 = XOR2 ^ i+1;
    }
    return XOR1 ^ XOR2;
}

int usingSum(vector<int>arr){
    int n = arr.size();
    int sum = (n *(n + 1)) / 2;

    int s = 0;
    for(int i=0; i<n; i++){
        s += arr[i];
    }
    int diff = sum - s;
    return diff;
}

int findMaxConsecutiveOnes__485(vector<int>& nums) {
        int maxcount = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
                maxcount = max(maxcount, count);
            }else{
                count = 0;
            }
        }
        return maxcount;
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int XOR = 0;
        for(int i=0;i<nums.size();i++){
            XOR = XOR ^ nums[i];    // when two value are same then is 0 or if one is 0 andother is num then return num
        }
        return XOR;
    }

int main(){
    vector<int>arr{0,1,3,2,5};//4 is missing 
    cout<<usingSum(arr)<<endl;
}
