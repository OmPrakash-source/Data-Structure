#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// maximum value of k size 

vector<int> SlidingWindow(vector<int>nums, int k){
    deque<int>q;
    vector<int>ans;
    for(int i=0;i<k;i++){
        // choti val ko pop kalna hai last se 
            while(!q.empty() && nums[i] >= nums[q.back()]){  // maine yaha if condition laga di thi galti se 
                q.pop_back(); //kyoki last val choti hai 
            }
            q.push_back(i);// yaha back ki place pe front karta hu mistake
    }
    ans.push_back(nums[q.front()]);

    for(int i=k;i<nums.size();i++){
        if(!q.empty() && i-q.front() >= k){
            // out of window hai 
            q.pop_front();
        }
        while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
        }
        q.push_back(i);
        ans.push_back(nums[q.front()]);
    }
    return ans;
}
vector<int>Deque_base(vector<int>n,int k){
    int i=0,j=0,maxval=0;
    vector<int>ans;
    deque<int>q;
    while(j<n.size()){
        while(!q.empty() && q.back() < n[j]){ // back agar choti hai current val se to pop kardo 
            q.pop_back();
        }
        q.push_back(n[j]); //back se push karna hai 
        if(j-i+1 < k) j++;
        else if(j-i+1 == k){
            ans.push_back(q.front());//front pe he actual big val store hai

            if(!q.empty() && q.front() == n[i]){ // agar i list ke front me prasent hai to pop krna hai 
                q.pop_front();
            }
            i++;j++;
        }
    }
    return ans;
}
vector<int>probfree(vector<int>n,int k){
    int i=0,j=0,maxval=0;
    vector<int>ans;
    queue<int>q;
    while(j<n.size()){
        while(!q.empty() && q.front() < n[j]){
            q.pop();
        }
        q.push(n[j]);
        maxval = max(maxval,max(q.front(),n[j]));
        if(j-i+1 < k) j++;
        else if(j-i+1 == k){
            ans.push_back(maxval);
            if(!q.empty() && maxval == n[i]){
                q.pop();
                maxval = q.front();
            }
            i++;j++;
        }
    }
    return ans;
}


int main(){
    vector<int>nums{2,1,0,5,-1,4,3};
    int k = 3;
    vector<int>vec = SlidingWindow(nums,k);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    vector<int>ans = Deque_base(nums,k);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    vector<int>v = probfree(nums,k);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}