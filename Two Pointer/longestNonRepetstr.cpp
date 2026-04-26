    #include<iostream>
    #include<string>
    #include<map>
    using namespace std;
    int longestSubstr(string str, int n){
        map<char,int>mp;
        int start = 0, maxlen = 0;
        for(int ed=0; ed<n; ed++){
            //
            if(mp.find(str[ed]) != mp.end() && mp[str[ed]] >= start){
                start = mp[str[ed]] + 1; //jo bhi last idx tha dup str ka usse 1 aage start ko rakhna hai agar dup mila to
            }
            mp[str[ed]] = ed; //yaha pe jo prev idx tha char ka usko new se update karna hai
            int currlen = ed -start + 1; //size nikalna hai substr ka 
            maxlen = max(maxlen,currlen);
        }
        return maxlen;
    }
    int main(){
        string str = "abcadadd";
        int n = str.size();
    }
// minor style fix
