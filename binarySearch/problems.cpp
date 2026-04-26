#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int findMin(vector<int> nums) {
        int st = 0, end = nums.size()-1;
        int ans = INT16_MAX;
        while(st <= end){
            int mid = (st + end) / 2;
            if(nums[st] <= nums[mid]){
                ans = min(ans,nums[st]);
                st = mid+1;
            }else{
                ans = min(ans, nums[mid]);
                end = mid-1;
            }
        }
        return ans;
    }

    int howmanytimerotede(vector<int>a){
        int st = 0, end = a.size()-1;
        int ans = INT16_MIN;
        int idx = -1;
        while(st <= end){
            int mid = (st+end) / 2;

            if(a[st] <= a[end]){
                if(a[st] <= ans){
                    idx = st;
                    ans = a[st];
                }
                st = mid + 1;
            }else{
                if(a[mid] <= ans){
                    idx = mid;
                    ans = a[mid];
                }
                end = mid-1;
            }
        }
        return idx;
    }

    int singleNonDuplicate_540(vector<int>& a) { // all element are duplicate but only one element is single so find a single one in O(log n) 
        
        int n = a.size();
        if(n == 1) return a[0]; //agar size 1 hai to 
        if(a[0] != a[1]) return a[0]; // ager first != second 
        if(a[n-1] != a[n-2]) return a[n-1]; // ager last != second last

        int st = 1;
        int end = n-2;
        while(st <= end){
            int mid = (st+end) / 2;
            if(a[mid] != a[mid - 1] && a[mid] != a[mid+1]) return a[mid]; // if single value find

            if((mid % 2 == 1 && a[mid] == a[mid-1]) || (mid % 2 == 0 && a[mid] == a[mid+1])){  // if(even , odd meet then remove left part)
                st = mid+1;
            }else{ // else remove right part 
                end = mid-1;
            }
        }
        return -1;
    }

    int findPeakElement_162(vector<int>& nums) {
        int n = nums.size();
        int st = 1, end = nums.size()-2;
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        while(st <= end){
            int mid = (st + end) / 2;
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;

            else if(nums[mid] > nums[mid-1]) st = mid + 1; // eliminate a left becouse always right have a pick

            else end = mid -1; // eliminate a right becouse always left have a pick
        }
        return -1;
    }
// maximum element that less then or equal to n squre 
/*
ex - 
n = 28 
ans = 5 == (5*5 = 25 or 6*6 = 36) but 36 > 28 so 5 is max which lessthen or equal to n
*/
    long long floorSqrt(long long n)  {
      long long ans = 0;
      int st = 1, end = n;
      while(st <= end){
        int mid = (st+end)/2;
        if(mid * mid <= n){
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
      }
      return ans;
    }
// leet code 875 find a min time when koko eat all banana in given time
    int calculateTotalHours(vector<int> &v, int hourly) {
        int totalH = 0;
        int n = v.size();
        //find total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }
    int mintimetoEatBanana(vector<int>&v, int hr){
        int st = 1, end = 0;
        for(int i:v){
            if(end < i){
                end = i;
            }
        }
        while(st <= end){
            int mid = (st + end) / 2;
            if(calculateTotalHours(v, mid) <= hr){
                end = mid -1;
            }else{
                st = mid + 1;
            }
        }
        return st;
    }

//(1482) find a number of bouquet that build on min day 
/* given 
k = total flower required in make a bouquet
m = number or bouquet required
array = day's that flower are bloomed
*/

int posible(vector<int>&a, int day, int bou, int flow){
    int tbou = 0, count = 0;
    for(int i:a){
        if(i <= day) count++; // ager array me flower ke bloomed day <= curr day se matlab flower use kar sakte hai
        else{
            tbou += count / flow; // kitne flower bloom hue hai usko total bouque me add karna 
            count = 0; // kyoki continue or adjencent hai
        }
    }
    tbou += count / flow; // last ke liye check
    return bou <= tbou; // ager last me bouque question ne diye hai or jo hamne nikale hai to return true; 
}

int rosegarden(vector<int>a, int bou, int flo){
    int n = a.size();
    if(bou * flo > n) return -1; // not enough flower have 
    int ans = 0;
        int mini = INT16_MAX, maxi = INT16_MIN;
        for(int i:a){
            if(i > maxi){
                maxi = i;
            }
            if(i < mini){
                mini = i;
            }
        }
    while(mini <= maxi){
        int mid = (mini+maxi) / 2;
        if(posible(a, mid, bou, flo)){  // ager mid ans hai to right me koi or ans nhi hoga 
            ans = mid;
            maxi = mid -1;
        }else{
            mini = mid + 1; // ager mid ans nhi hai to left me koi or ans nhi hoga 
        }
    }
    return ans;
}

// 1283 find a smallest diviser given a threshold 
/* given data- 
    array = total day's that divide by number
    threshold - a number which is equal or less then divider mean a stop value

    Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
*/

    bool posible(vector<int>&nums, int target, int threshold){
        int ans = 0;
        for(int i : nums){
            ans += ((double)i / (double)target);
        }
        return threshold >= ans; // ager ans thershole se chota hai to true 
    }
    int minof_1283(vector<int>&nums, int threshold){
        int result = 0;
        int end = INT16_MIN;
        int st = 1;
        for(int i: nums){
            end = max(end,i);
        }
        while(st <= end){
            int mid = (st+end)/2;
            if(posible(nums, mid, threshold)){ // ager mid ke liye true aaya to right ke to sab true hogi par left me choti value hogi
                end = mid -1;
            }else{  // ager mid ke liye false aaye to uske left me or koi value ke liye true nhi hoga
                st = mid +1;
            }
        }
        return st; //kyoki first me end point karega jo ans hai par last me jab st end ko cross karega to st point karga ans ko
    }
// 1011 ship capacity 
/*
given a day and an array with some number we want to shift each array element to given day's 
capacity of ship we can choose so find a min capacity where we transport each item with in day's
*/
bool check(vector<int>&a, int cap, int days){
    int load = 0, day = 1;
    for(int i=0; i<a.size(); i++){
        if(load + i > cap){ // if load + i is more then cap then reinitilize load as new val 
            load = i;
            day++; // and increass day to next day
        }else{
            load += i; // if cap is not full then fill load 
        }
    }
    return day <= days;
}
int ship_brute(vector<int>&a, int days){
    int st = INT16_MIN; // this is max value of array becouse if we take another value so any grater value which parsent in arry is not tranport
    int end = 0;
    for(int i : a){
        st = max(st, i);
        end += i;
    }
    if(days == 1) return end; //becouse all item transport on single day
    for(int i=st; i<end; i++){
        int day = check(a, i); 
        if(day <= days){
            return i;
        }
    }
    return -1;
}

int ship_optimal(vector<int>&a, int days){
    int st = INT16_MIN; // this is max value of array becouse if we take another value so any grater value which parsent in arry is not tranport
    int end = 0;
    for(int i : a){
        st = max(st, i);
        end += i;
    }
    if(days == 1) return end; //becouse all item transport on single day
    while(st <= end){
        int mid = (st+end) / 2;
        if(check(a, mid, days)){ // agar mid ke liye true hai to mid se choti val ke liye check karna hai
            end = mid -1;
        }else{
            st = mid +1;
        }
    }
    return st;
}

// IMPORTENT 1539 return a kth missing value
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k) return k;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= k)k++;
            else break;
        }
        return k;
    }
// agrassive cow 
bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) { 
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}
int main(){
    vector<int>arr{6,5,4,1,2,3}; //ans = 0
}

// 460