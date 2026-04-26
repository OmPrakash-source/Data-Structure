#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
#include<vector>
using namespace std;

// maximum sum of subarray 
int maxSum_of_subarray(vector<int>arr){
    int sum = 0, maxsum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(sum < 0) sum = 0;    //agar sum - me hai to usko 0 kardo 
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

// sort 0, 1, 2
int sort_0_1_2(vector<int>arr){
    int c0 = 0, c1 = 0, c2 = 0;
    for(int i = 0;i<arr.size(); i++){
        if(arr[i] == 0) c0++;
        if(arr[i] == 1) c1++;
        if(arr[i] == 2) c2++;
    } 
    int idx = 0;
    for (int i = 0; i < c0; i++) arr[idx++] = 0;
    for (int i = 0; i < c1; i++) arr[idx++] = 1;
    for (int i = 0; i < c2; i++) arr[idx++] = 2;
}
// 169 

int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }
            if(count > (n/2)){
                return arr[i];
            }
        }
        return -1;
    }
     int majorityElement_brute(vector<int>& arr) {
        int n = arr.size();
        map<int,int>m;
        for(int i:arr) m[i]++;
        for(auto i : m){
            if(i.second > (n/2)) return i.first;
        }
        return -1;
    }
// leader prob if right of any element is less value so it will be leader
/* i/p - 10,22,12,3,0,6
   o/p - 22,12,6
*/
// brute
 vector<int> leader_brute(vector<int>arr){
    int n =arr.size();
    vector<int>ans;
    for(int i=0; i<n; i++){
        bool leader = true;
        for(int j=i; j<n; j++){
            if(arr[i] < arr[j]){ // agar right me large value milli to break
                leader = false;
                break;
            }
        }
        if(leader){ // right me large value nhi mill matlab ans hai
            ans.push_back(arr[i]);
        }
    }
    return ans;
 }

// optimal 
 vector<int> leader(vector<int>arr){
    int maxi = INT16_MIN;
    int n =arr.size();
    vector<int>ans;
    for(int i=n-1; i>=0; i--){
        if(maxi < arr[i]){ //right value check if right is greater curr val so push it on ans
            ans.push_back(arr[i]);
            maxi = arr[i]; // or update max value
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
 }

//128. Longest Consecutive Sequence find a longest sequence or Consecutive numbers 
 int longestConsecutive_brute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = 0, count = 0, last = INT16_MIN, n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] - 1 == last){ // check one smaller value avalable or not
                count++;    
                last = nums[i];
            }else if(nums[i] != last){
                count = 1;
                last = nums[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }

int longestConsecutive_optimal(vector<int>arr){
    int n = arr.size();
    int longest = 0;
    unordered_set<int>st(arr.begin(),arr.end()); // initilize all vector value into map

    for(auto i:arr){
        if(st.find(i-1) == st.end()){ //agar value-1 nahi mili matlab starting hai 
            int count = 1;
            int val = i;
            while(st.find(val + 1) != st.end()){  // next val+1 jab tak map me hai count ++ 
                val++;
                count++;
            }
            longest = max(longest,count);// jaise val+1 map se khatam hui longest nikal lo
        }
    }

    return longest;
}

// ___________________________________ 229 magority element II ___________________________________
vector<int> majorityElement_brute_II(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mmp;
        vector<int>temp;
        int mmin = (n/3)+1;
        for(int i=0; i<n;i++){
            mmp[nums[i]]++;
            if(mmp[nums[i]] == mmin){
                temp.push_back(nums[i]);
            }
            if(temp.size() == 2) break;
        }
        return temp;
    }
vector<int> majorityElement_optimal(vector<int>& nums) {
        int n=nums.size();
        int el1 = INT16_MIN, el2 = INT16_MIN;
        int count1 = 0, count2 = 0;
        vector<int>temp;
        int mini = n/3;
        for(int i=0; i<n;i++){
            if(count1 == 0 && nums[i] != el2){
                count1 = 1;
                el1 = nums[i];
            }else if(count2 == 0 && nums[i] != el1){
                count2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]) count1++;
            else if(el2 == nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(el1 == nums[i]) count1++;
            if(el2 == nums[i]) count2++;
        }
        if(count1 > mini) temp.push_back(el1);
        if(count2 > mini) temp.push_back(el2);
        return temp;
    }
// ___________________________________ 15 three sum ___________________________________

vector<vector<int>> threeSum_brute(vector<int>& nums) { // O(N^3)
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int>temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>ans (st.begin(), st.end());
        return ans;
    }

 vector<vector<int>> threeSum_batter(vector<int>& nums) {
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            set<int>hash;
            for(int j=i+1;j<n;j++){
                int third = -(nums[i] + nums[j]);
                if(hash.find(third) != hash.end()){
                    vector<int>temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hash.insert(nums[j]);
            }
        }
        vector<vector<int>>ans (st.begin(), st.end());
        return ans;
    }

// four sum brute
vector<vector<int>> brute_four_sum(vector<int>a, int target){
    int n = a.size();
    vector<vector<int>>ans;
    set<vector<int>>st;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                for (int l = k+1; l < n; l++){
                    long long sum = a[i] + a[j];
                    sum += a[k]; sum += a[l];
                    if(sum == target){
                        vector<int>temp = {a[i], a[j], a[k], a[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    ans = vector<vector<int>>(st.begin(), st.end());
    return ans;
}


vector<vector<int>> optimal_four_sum(vector<int>a, int target){
    int n = a.size();
    vector<vector<int>>ans;
    set<vector<int>>st;
    for (int i = 0; i < n; i++){
        if(i > 0 && a[i] == a[i-1]) continue;
        for (int j = i+1; j < n; j++){
            if(j > i+1 && a[j] == a[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l){
                long long sum = a[i] + a[j];
                sum += a[k]; sum += a[l];

                if(sum > target) k++;
                else if(sum < target) l--;
                else{
                    vector<int>temp = {a[i], a[j], a[k], a[l]};
                    ans.push_back(temp);
                    k++;l--;
                    while(k < l && a[k] == a[k-1]) k++;
                    while(k < l && a[l] == a[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

// longest subarray with sum 0 
int longestsub_brute(vector<int>a){
    int n=a.size();
    int longest = INT16_MIN;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += a[j];
            if(sum == 0){
                int size = j-i+1;
                longest = max(longest, size);
            }
        }
    }
    return longest;
}

//  repeting and missing number in array // there one value is missing and one is repeting we found both
vector<int> missingAndRepiting_brute(vector<int>a){
    int n = a.size();
    int repeting = -1, missing = -1;
    for(int i=1; i<=n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(a[j] == i) count++;
        }
        if(count == 2) repeting = i;
        else if(count == 0) missing = i;
        if(repeting != -1 && missing != -1) break;
    }
    return {repeting, missing};
}

vector<int>missingAndRepiting_batter(vector<int>a){
    unordered_map<int, int>m(0);
    int repeting = -1, missing = -1;
    for(int i:a) m[i]++;
    for(int i=1; i<=a.size(); i++){
        if(m[i] == 2){
            repeting = i;
        }
        else if(m[i] == 0){
            missing =  i;
        }
    }
return {repeting, missing};
}

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array
    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    //S-Sn = X-Y:
    long long val1 = S - SN;
    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;
    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;
    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
