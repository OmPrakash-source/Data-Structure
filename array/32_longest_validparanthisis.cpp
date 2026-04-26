#include<iostream> 
using namespace std;
int longestparn(string s){
    int left = 0, right = 0, maxlen = 0;
    for(char ch : s){
        if(ch == '(') left++;
        else right++;
        // agar 1 open or 1 close bracket mille to
        if(left == right) maxlen = max(maxlen, 2*right);//  valid hai 2 mille iss liye *2

        if(right > left) left = right = 0; // ham right se check kar rahe hai ye "(" extra backet handel karege
    }
    left = right = 0;
    for(char ch : s){
        if(ch == ')') right++;
        else left++;
        // agar 1 open or 1 close bracket mille to
        if(left == right) maxlen = max(maxlen, 2*left);//  valid hai 2 mille iss liye *2

        if(right < left) left = right = 0; // ham left se check kar rahe hai ye ")" extra backet handel karege
    }
    return maxlen;
}

int main(){
    string s = "()()((())";
    cout<<longestparn(s)<<endl;
}
// minor style fix
