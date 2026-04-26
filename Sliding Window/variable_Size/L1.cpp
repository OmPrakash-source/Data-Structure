#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
slide the window then find sum which is equal to k 
if sum reach to sum then check window size if max size reach or window equal to then return it
*/
int sumOfSizeK(vector<int>vec, int k){
    int i=0,j=0,sum=0,result = 0;
    while(j<vec.size()){
        sum+=vec[j];

        // check while sum of all val is greater then k then remove i'th val from sum 
        while(sum > k){
                sum-=vec[i];
                i++;    // increase mean remove i'th 
        }

        if(sum < k) j++;
        
        else if(sum == k){
            result = max(result,j-i+1); // j-i+1 is store a size of window
            j++;
        }
    }
    return result;
}
/*
    find a longest substring of k uniqe size 
    char repete ho sakte hai par har window me exact K size ke char uniqe hona chaniye
*/
int longestsubString(string s, int k){
    int i=0, j=0, result = 0;
    unordered_map<char, int>m;

    while(j < s.length()){
        m[s[j]]++; // har char ko map me insert kara or agar pahle se hai to count ko increase kiya

        while(m.size() > k){    // map ka size batayga ki kitne uniqe char hai map me agar char > k se to i-- 
            m[s[i]]--;
            if(m[s[i]] == 0) m.erase(s[i]); // agar koi char ka size 0 ho  jay to map se delete karna hai 
            i++;
        }

        if(m.size() < k) j++; // map ka size kam hia k se to j ko ++ kar ke size badana hai 
        // if size is  equal to k 
        else if(m.size() == k){
            result = max(result, j-i+1); // result find karo window ka
            j++;
        }
    }
    return result;
}

int longedSubstr_Without_repeting_char(string s){
    unordered_map<char,int>m;
    int i=0,j=0,result=0;
    while(j < s.length()){
        m[s[j]]++;
        while(m.size() < j-i+1){
            m[s[i]]--;
            if(m[s[i]] == 0)m.erase(s[i]);
            i++;
        }
        if(m.size() == j-i+1){
            result = max(result, j-i+1);
            j++;
        } 
    }
    return result;
}

string minSizeSlidingWindow(string s, string t){
    unordered_map<char,int>m;
    for(char ch : t) m[ch]++;
    int i=0, j=0,count = 0, result = INT32_MAX;
    int k = m.size();
    int start = -1;
    while(j < s.length()){
        if(m.count(s[j])){
            m[s[j]]--;
            if(m[s[j]] == 0){
                count++;
            }
        }
        if(count == k){
            result = min(result, i-j+1);
            start = i;
            if(m.count(s[i])){
                if(m[s[i]] == 0){
                    count--;
                }
                m[s[i]]++;
            }
            i++;
        }
        j++;
    }
    return start == -1? "": s.substr(start, result);
}

// _____________________________________________________________ 

int minSizeSlidingWindow_(string s, string t){
    unordered_map<char,int>m;
    for(char ch : t) m[ch]++;
    int i=0, j=0, result = INT32_MAX;
    int count = m.size();

    while(j < s.length()){

        if(m.count(s[j])){
            m[s[j]]--;
            if(m[s[j]] == 0){
                count--;
            }
        }
        while(count == 0){
            result = min(result, j-i+1);
            if(m.count(s[i])){
                m[s[i]]++;
                if(m[s[i]] > 0) count++;
            }
            i++;
        }
        j++;
    }
    return result;
}
int main(){
    vector<int>arr{4,1,1,1,2,3,5};
    cout<<sumOfSizeK(arr, 5)<<endl;

    string s = "aabacbebebe";
    cout<<longestsubString(s, 3)<<endl; 

    /*
    1. aabac
    2. abac
    3. bac
    4. acb
    5. cba
    6. cbeb
    ...
    9. cbebebe == 7 longest 
    */
    string str = "aabacbegbebe"; //acbeg
    cout<<longedSubstr_Without_repeting_char(str)<<endl;

    string st = "TOTMTAPTAT";
    string t = "TAT";

    cout<< minSizeSlidingWindow(st,t)<<endl;
    cout<< minSizeSlidingWindow_(st,t)<<endl;
}