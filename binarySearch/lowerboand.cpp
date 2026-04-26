#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lowerbound(vector<int>a, int target){
    int n = a.size()-1;
    int ans = INT16_MAX;
    int st = 0, end = a.size()-1;
    if(target > a[n]) return a[n];
    while(st <= end){
        int mid = (st+end) / 2;
        if(a[mid] >= target && st <= end){
            // ans = mid; // if ask idx\
            end = mid-1;
            ans = min(a[mid], ans);
        }else if(a[mid] < target && st <= end){
            st = mid +1;
        }
    }
    return ans;
}

int upper_bound_(vector<int>a, int target){
    int n = a.size();
    if(target > a[n-1]) return n;
    int st = 0;
    int end = n-1;
    int ans = n;
    while(st <= end){
        int mid = (st+end) / 2;
        if(a[mid] > target){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    return ans;
}

// floor and ceil problem 
// floor = longer number <= x , ceil = smaller number which is >= x (lower_bound)
    int floor_ceil(vector<int>a,int target){
        int n = a.size();
        int floor = 0;
        int st = 0, end = n-1;
        while(st <= end){
            int mid = (st+end)/2;
            if(a[mid] <= target){
                floor = a[mid];
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return floor;
    }

// 34 print a target value when it first come and last come 
    vector<int> searchRange(vector<int>nums, int target) {
        int n = nums.size();
        auto first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        auto last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(first == n+1 || nums[first] != target)  return {-1, -1}; // if value is not exist
        
        return {(int)first, (int)last-1};
    }

int main(){
    vector<int>arr = {1,2,3,4,4,8,9,11,15};
    // cout<<arr.begin();
    cout<<lowerbound(arr, 60)<<endl;
    cout<<floor_ceil(arr, 10)<<endl;

    auto it = lower_bound(arr.begin(), arr.end(),6) - arr.begin(); // 8 at idx 5 use - arr.begin() becouse i need idx
    auto it2 = lower_bound(arr.begin()+2, arr.end()+7,6) - arr.begin();
                
    cout<<it2<<endl;
}

// minor style fix
