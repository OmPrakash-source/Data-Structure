#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int slidingSum(vector<int>nums, int k){
   int ans = 0;
    deque<int>q1 ,q2;
    for(int i=0; i<k; i++){
        while(!q1.empty() && nums[i] >= nums[q1.back()]){
            q1.pop_back();
        }
        while(!q2.empty() && nums[i] <= nums[q2.back()]){
            q2.pop_back();
        }
        q1.push_back(i);
        q2.push_back(i);
    }

    ans += nums[q1.front()]+nums[q2.front()];

    for(int i=k; i<nums.size();i++){
        // out of bound for both 
        while(!q1.empty() && i-q1.front() >= k){
            q1.pop_front();
        }// out of bound for both 
        while(!q2.empty() && i-q2.front() >= k){
            q2.pop_front();
        }

        while(!q1.empty() && nums[i] >= nums[q1.back()]){
            q1.pop_back();
        }
        while(!q2.empty() && nums[i] <= nums[q2.back()]){
            q2.pop_back();
        }
        q1.push_back(i);
        q2.push_back(i);

        ans += nums[q1.front()] + nums[q2.front()];
    }
    return ans;
}
int main(){
    vector<int>v{2,5,-1,7,-3,-1,-2};
    int k =4;
    cout<<slidingSum(v,k);
}

// minor style fix
