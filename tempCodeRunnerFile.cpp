// #include<iostream>
// #include<stack>
// #include<unordered_map>
// #include<vector>
// using namespace std;
// void prefix(vector<int>arr, int n){
//     vector<int>newArr;
//     newArr.push_back(arr[0]);
//     for(int i=1; i<n;i++){
//         newArr.push_back(newArr[i-1] + arr[i]);
//     }
//     for(int i=0; i<n;i++){
//         cout<< newArr[i]<<" ";
//     }

// }


//   // 451
//   string frequencySort(string s) {
//         unordered_map<char, int>map;
//         string ans = "";
//         for(char ch:s){
//             map[ch]++;
//         }
//         while(!map.empty()){
//             int maxFreq = INT16_MIN;
//             char maxChar = '\0';
//             for(auto p : map){
//                 if(p.second > maxFreq){
//                     maxFreq = p.second;
//                     maxChar = p.first;
//                 }
//             }
//                 ans += string(maxFreq, maxChar);
//                 map.erase(maxChar);
//         }
//         return ans;
//     }

// // 151 
//     string reverseWords(string s) {
//         stack<string>st;
//         string str = "";
//         for(char ch : s){
//             if(ch == ' '){
//                 if(!str.empty()){
//                     st.push(str);
//                     str = "";
//                 }     
//             }else{
//                 str += ch;
//             }
//         }
//         if(!str.empty()){
//             st.push(str);
//             str = "";
//         }
//         str = "";
//         while(!st.empty()){
//             if(st.size() == 1){
//                 str += st.top();
//                 st.pop();
//             }else{
//                 str += st.top() + " ";
//                 st.pop();
//             }
//         }
//         return str;
//     }

//     bool isLeap(){
//         int uy;
//         cin>>uy;
//         int my = 2004;
//         if(my >= uy){
//             int check = my - uy;
//             if(check % 4 == 0) return true;  
//         }else{
//             int check = uy - my;
//             if(check % 4 == 0) return true;  
//         }
//         return false;
//     }
    
// int func(vector<int>&nums){
//      unordered_map<int,int>mpp;
//     for(int i:nums) mpp[i]++;
//     for(int i : nums){
//         if(mpp[i] == 1) // mpp[i] is a value access by key i
            //    return i; // i is a key 
//     }
//     return -1; 
// }

// int countones(vector<int>&nums){
//     int maxi = 0;
//     int result = 0;
//     for(const int &i : nums){
//         if(i == 1){
//             result++;
//             maxi = max(maxi,result);
//         }else{
//             result = 0;
//         }
//     }
//     return maxi;
// }


// int majority_element(vector<int>&nums){
//     unordered_map<int,int>freq;
//     int n = nums.size();
//     for(int i:nums)freq[i]++;
//     int maxi = 0;
//     int element = -1;
//     for(auto it : freq){
//         if(it.second > maxi){
//             maxi = it.second;
//             element = it.first;
//         }
//     }
//     int count = 0;
//     for(int i : nums){
//         if(element == i){
//             count++;
//         }
//     }
//     return (count > n/2) ? element : -1;
// }


// bool IsLeapYear(int year){
//     if((year%4==0 && year%100 !=0 ) || year % 400 == 0){
//         return true;
//     }
//     return false;
// }


// int Second_largest(vector<int>&nums, int n){
//     if(n < 2) return -1;
//     int maxi = INT_MIN, smaxi = INT_MIN;
//     bool foundsecond = false;
//     for(int i : nums) maxi = max(maxi,i);
//     for(int j : nums){
//         if(j < maxi && j > smaxi){
//             smaxi = j;
//             foundsecond = true;
//         }
//     }
//     return (foundsecond) ? smaxi : -1;
// }



// int CountSundays(int days, string s){
//     int day;
//     if(s == "mon") day = 1;
//     else if(s == "tue") day = 2;
//     else if(s == "wed") day = 3;
//     else if(s == "thu") day = 4;
//     else if(s == "fri") day = 5;
//     else if(s == "sat") day = 6;
//     else if(s == "sun") day = 7;
//     int count = 0;
//     for(int i=0; i<days; i++){
//         int currday = day+i;
//         if(currday % 7 == 0) count++; 
//     }
//     return count;
// }

// int lastdigit(int num){
//     if(num < 0) num = abs(num);
//     int tem = num;
//     while(tem >= 10){
//         int sum = 0;
//         while(tem > 0){
//             sum += tem%10;
//             tem /= 10;
//         }
//         tem = sum;
//     }
//     return tem;
// }
// Sum of digits until single digit


// char onesfreq(string s){
//     unordered_map<char,int>mp;
//     for(char ch : s) mp[ch]++;
//     for(char ch : s){
//         if(mp[ch] == 1) return ch;
//     }
//     return ' ';
// }

// string nonrepet(string s){
//     unordered_set<char>st(s.begin(),s.end());
//     string result = "";
//     for(char ch : s){
//         if(st.count(ch)){
//             result+=ch;
//             st.erase(ch);
//         }
//     }
//     return result;
// }

// int secondmaxelement(vector<int>&nums){
//     if(nums.size() < 2) return -1;
//     int maxi = INT_MIN;
//     int smaxi = INT_MIN;
//     bool found = false;
//     for(int i : nums)
//         maxi = max(maxi, i);
//     for(int i : nums){
//         if(i > smaxi && maxi > i){
//             smaxi = i;
//             found = true;
//         }
//     }
//     return (found)?smaxi:-1;
// }

// int countnextgrater(vector<int>&nums){
//     int count = 1;
//     int maxele = nums[0];
//     for(int i=1; i<nums.size(); i++){
//         if(nums[i] > maxele){
//             maxele = nums[i];
//             count++;
//         }
//     }
//     return count;
// }


// for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(nums[j] > nums[i]){
//                 int diff = nums[j] - nums[i];
//                 if(maxi < diff){
//                     maxi = diff;
//                     flag = true;
//                 }
//             }
//         }
//     }

// int maxdiff(vector<int>&nums, int &n){
//     int maxi = 0;
//     int mini = nums[0];
//     for(int i=0; i<n; i++){
//         if(nums[i] < mini){
//             mini = nums[i];
//         }else{
//             maxi = max(maxi, nums[i]-mini);
//         }
//     }
//     return (maxi == 0) ? -1 : maxi;
// }


// #include<algorithm>
// int GCD(int a, int b){
//     if(a == 0 && b == 0) return 0; 
//     return __gcd(a,b);
// }
// long LCM(int a, int b){
//     if(a == 0 && b == 0) return 0; 
//     int gcd = __gcd(a,b);
//     return (a*b)/gcd;
// }
// int main(){
//     int a,b;
//     cin>>a>>b;
//     cout<<GCD(a,b)<<" ";
//     cout<<LCM(a,b);
    
// }
// int secondmin(vector<int>&nums){
//     int mini = INT_MAX;
//     int smini = INT_MAX;
//     int flag = false;
//     for(int i : nums)
//         mini = min(mini,i);
//     for(int i : nums){
//         if(i < smini && i > mini){
//             flag = true;
//             smini = i;
//         }
//     }
//     return (flag)?smini:-1;
// }


// int findMaxSubArr(vector<int>&nums){
//     int i=0,j=0,maxi=0;
//     unordered_set<int>st;
//     while(j < nums.size()){
//         if(st.find(nums[j]) == st.end()){
//             st.insert(nums[j]);
//             maxi = max(maxi, j-i+1);
//             j++;
//         }else{
//             st.erase(nums[i]);
//             i++;
//         }
//     }
//     return maxi;
// }

// int min_length(vector<int>&nums, int k){
//     int i = 0, j = 0;
//     int mini = INT_MAX, sum = 0;
//     bool flag = false;
//     while(j < nums.size()){
//         sum+=nums[j];
//         while(sum >= k && i <= j){
//             mini = min(mini,j-i+1);
//             sum -= nums[i];
//             i++;
//             flag = true;
//         }
//         j++;
//     }
//     return (flag) ? mini : -1;
// }

// int greater_(vector<int>&nums){
//     int maxi = INT_MIN;
//     vector<bool>temp(nums.size(), false);
//     for(int i=0; i<nums.size(); i++){
//         if(nums[i] < maxi){
//             temp[i] = false;
//         }else{
//             temp[i] = true;
//             maxi = nums[i];
//         }
//     }
//     for(int i=0; i<temp.size(); i++){
//         if(temp[i]){
//             return nums[i];
//         }
//     }
//     return -1;
// }

// int rotate(vector<int>&nums,int k){
//     int n = nums.size();
//     if(n == 0) return -1;
//     k = k%n;
//     reverse(nums.end()-k, nums.end());
//     reverse(nums.begin(),nums.end()-k);
//     reverse(nums.begin(),nums.end());
//     return *max_element(nums.begin(),nums.end());
// }


// void removedup(vector<int>&nums, int &size){
//     int j = 0;
//     for(int i=1; i<nums.size(); i++){
//         if(nums[i] != nums[j]){
//             j++;
//             nums[j] = nums[i];
//         }
//     }
//     size = j+1;
// }
// #include<bits/stdc++.h>

// using namespace std;



// int fact(int n){
//     if(n <= 1) return 1;
//     return n*fact(n-1);
// }
// void func(int n){
//     int dig = n;
//     int sum = 0;
//     while(n > 0){
//         int digit = n%10;
//         sum += fact(digit);
//         n /= 10;
//     }
//     if(dig == sum){
//         cout<<"Strong Number";
//     }else{
//         cout<<"Not a Strong Number";
//     }
// }

// vector<int>leader(vector<int>& nums, int n){
//     vector<int>result;
//     int maxi = 0;
//     for(int i=n-1; i>=0; i--){
//         if(nums[i] > maxi){
//             maxi = nums[i];
//             result.push_back(nums[i]);
//         }
//     }
//     reverse(result.begin(), result.end());
//     return result;
// }

#include<bits/stdc++.h>
using namespace std;


  vector<int>union_(vector<int>&a1, vector<int>&a2){
    vector<int>ans;
    int i = 0, j = 0;
    while(i < a1.size() && j < a2.size()){
        while(i > 0 && i < a1.size() && a1[i] == a1[i - 1]) i++;
        while(j > 0 && j < a2.size() && a2[j] == a2[j - 1]) j++;

        if(i >= a1.size() || j >= a2.size()) break;

        if(a1[i] < a2[j]){
            ans.push_back(a1[i++]);
        }
        else if(a1[i] > a2[j]){
            ans.push_back(a2[j++]);
        }
        else{
            ans.push_back(a1[i]);
            i++; j++;
        }
    }
    while(i < a1.size()){
        if(i == 0 || a1[i] != a1[i-1]){
            ans.push_back(a1[i]);
        }
        i++;
    }
    while(j < a2.size()){
        if(j == 0 || a2[j] != a2[j-1]){
            ans.push_back(a2[j]);
        }
        j++;
    }
    return ans;
  }

  
void func(vector<int>&nums, int n){
    int j=0;
    for(int i=0; i<n; i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

char firstnonrepchar(string &s){
    unordered_map<char,int>mpp;
    for(auto &ch : s) mpp[ch]++;
    for(char ch : s){
        if(mpp.find(ch) != mpp.end()){
            if(mpp[ch] == 1){
                return ch;
            }
        }
    }
    return ' ';
}
int main(){
    string s = "LEETcODEL";
    cout<<firstnonrepchar(s);
}

// int n;cin>>n;
//     cin.ignore();
//     vector<int>nums;
//     string str, temp;
//     getline(cin,str);
//     if(str[0] == '['){
//         str.erase(str.begin());
//     }
//     if(str[str.size()-1] == ']'){
//         str.pop_back();
//     }
//     stringstream ss(str);
//     while(getline(ss,temp,',')){
//         nums.push_back(stoi(temp));
//     }
// minor style fix

// final cleanup pass
