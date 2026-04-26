#include<iostream>
#include<vector>
using namespace std;

// space O(n)
// time O(n)
void moveZeroBrute(vector<int>&nums){
    int count = 0;
    vector<int>vec;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] != 0){
            vec.push_back(nums[i]);
        }else{
            count++;
        }
    }
    while(count > 0){
        vec.push_back(0);
        count--;
    }
    nums = vec;
}

// space O(1)
// time O(n)
void moveZeroOptimize(vector<int>&nums){
    int j = 0;
    for(int i=0 ;i<nums.size(); i++){
        if(nums[i] != 0){
            if(i != j){
                swap(nums[i], nums[j]);
            }
            j++;
        }
    }
}
int main(){
    vector<int>nums = {0, 1, 4 ,0, 10};
    moveZeroBrute(nums);
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}
// minor style fix
