#include<iostream>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;

    int twoSumBruteForce(int arr[], int n, int target){
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(arr[i]+arr[j]==target && i != j){
                    cout<<"Pair found at indices: "<<i<<" and "<<j<<endl;
                    return 1;
                }
            }
        }
        return -1;
    }


    int twoSumOptimizeForce(int arr[], int n, int target){
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int more = target - arr[i];
            if(mpp.count(more)){
                cout<<"Pair found at indices: "<<mpp[more]<<" and "<<i<<endl;
                return 1;
            }
        }
        return -1;
    }
    
    string optimize(vector<int>arr, int n, int target){
        int i = 0, j=n-1;
        sort(arr.begin(),arr.end());
        while(i<j){
            int sum = arr[i] + arr[j];
            if(sum == target){
                return "yes";
            }
            else if(sum < target) i++;
            else j--;
        }
        return "no";
    }

    //______________________________ two sum II ______________________________

    vector<int> twoSumII(vector<int>&nums, int target){
        int st = 0, ed = nums.size()-1;
        vector<int>vec;
        while(st<ed){
            if(target == nums[st] + nums[ed]){
                vec.push_back(st+1);  // becouse idx start to 1
                vec.push_back(ed+1);  // becouse idx start to 1
                return vec;
            }else if(nums[st] + nums[ed] > target){
                ed--;
            }else{
                st++;
            }
        }
        return vec;
    }
int main(){
    int arr[] = {2, 3, 5, 11, 9};
    vector<int>vec = {2, 4, 5, 10, 14};
    cout<<twoSumOptimizeForce(arr, 5, 14)<<endl;
    vector<int> result = twoSumII(vec, 14);

    if (!result.empty()) {
        cout << "Pair found at indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    // cout<<optimize(vec, 5,
    }