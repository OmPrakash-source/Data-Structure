#include<iostream>
#include<string>
using namespace std;

bool palindrom(string s){
    int i = 0,j = s.length()-1;
    while(i < j){
        if(!isalnum(s[i])){ i++; continue;} // isalnum use for skip not char and num val like sapce , :
        if(!isalnum(s[j])){ j--; continue;}
        if(tolower(s[i] )!= tolower(s[j])){ //tolower use for non case sencative 
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    cout<<palindrom(s);
    return 0;
}