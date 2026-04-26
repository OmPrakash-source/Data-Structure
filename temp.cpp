
// int cadlans(int n){
    
//    vector<int>dp(n+1,0);
//    dp[0] = 1;
//    dp[1] = 1;
//    dp[2] = 2;
   
//    for(int i=3;i<=n;i++){ //ith catalan 
//     for(int j=0; j<i; j++){ // 0 to i
//        dp[i] += dp[j] * dp[i-j-1]; 
//     }
// }
//     return dp[n];
// }

// int main(){
//     cout<<cadlans(4);
// }
// void prefix(vector<int>arr, vector<int>&New, int n){
//     int sum = arr[0];
//     New.push_back(arr[0]);
//     for(int i=1; i<n; i++){
//         sum = sum + arr[i];
//         New.push_back(sum);
//     }
// }
// void newPrefix(vector<int>&arr, vector<int>&New){
//     int sum=0;
//     for(int i=0; i<arr.size(); i++){
//         sum += arr[i];
//         New.push_back(sum);
//     }
// }
// void prefixOptimize(vector<int>&arr){
//     for(int i=1; i<arr.size(); i++){
//         arr[i] += arr[i-1];
//     }
// }

//------------------- reverse word in string --------------------------------
// string reverseword(string str){
//     vector<string>temp;
//     string word;
//     for(char ch : str){
//         if(ch == ' '){
//             temp.push_back(word);
//             word.clear();
//         }else {
//             word += ch;
//         }
//     }
//     temp.push_back(word); 
//     reverse(temp.begin(), temp.end());
//     string result;

//     for (int i = 0; i < temp.size(); i++) {
//         result += temp[i];
//         if (i != temp.size() - 1)
//             result += ' ';
//     }
//     return result;
// }

// O(N)

// string reverseward_On(string str){
//     int n = str.size();
//     rs(str, 0, n-1);
//     int st = 0;
//     for(int i=0; i<=n; i++){
//         char ch = str[i];
//         if(ch == ' ' || i == n){
//             rs(str,st,i-1);
//             st = i+1;
//         }
//     }
//     return str;
// }
//------------------- longest word in string --------------------------------
// string longestward(string str){
//     vector<string>words;
//     string word;
//     for(char ch : str){
//         if(ch == ' '){
//             words.push_back(word);
//             word.clear();
//         }else{
//             word += ch;
//         }
//     }
//     int maxi = 0;
//     string result;
//     if(!word.empty())
//         words.push_back(word);
//     for(string s : words){
//         if(s.size() > maxi){
//             maxi = s.size();
//             result = s;
//         }
//     }
//     return result;
// }
// string removespace(string &str){
//     int n = str.size();
//     string word;
//     for(char ch : str){
//         if(ch == ' ')continue;
//         word += ch;
//     }
//     return word;
// }

// string decimaltofbinary(int n){
//     if(n == 0){
//         return "0";
//     }
//     string result = "";
//     while(n > 0){
//         result += '0'+(n%2);
//         n /= 2;
//     }
//     reverse(result.begin(),result.end());
//     return result;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int binarytodecimal(int n){
//     int result = 0;
//     int i = 0;
//     while(n > 0){
//         int lastdig = n%10;
//         result += lastdig * pow(2,i);
//         i++;
//         n /= 10;
//     }
//     return result;
// }
// int func(int n){
//     if(n<13)return n;
//     return n+1;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<func(n);
// }


#include<bits/stdc++.h>
using namespace std;

void func(int n){
    string st = to_string(n);
    int i=0, j = st.size()-1;
    bool flag = false;
    while(i < j){
        if(st[i]!=st[j]){
            flag = true;
            break;
        }else{
            i++;
            j--;
        }
    }
    if(flag){
        cout<<"INVALID";
    }else{
        cout<<"VALID";
    }
}
int findsunday(int n, string s){
    int day;
    if(s == "mon") day = 1;
    else if(s == "tue") day = 2;
    else if(s == "wed") day = 3;
    else if(s == "thu") day = 4;
    else if(s == "fri") day = 5;
    else if(s == "sat") day = 6;
    else if(s == "sun") day = 7;
    int count = 0;
    for(int i=day; i<=n; i++){
        int currday = day + i;
        if(currday % 7 == 0)count++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    string st;
    cin>>st;
    cout<<findsunday(n, st);
}
// minor style fix

// final cleanup pass
