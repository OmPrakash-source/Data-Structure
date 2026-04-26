/*
Given a two string one is bigger and another is smaller we can jumbel a smaller one then search a word are prasent on bigger or not 
Ex- (forxxrfoocsrof) and (for) so Anagrames are :- for,fro,rof,rfo,orf,ofr so that are prasent on bigger one 
Note:- Number of charector should be same or quantity are also same 
Ex:- ffoe - feof,fefo,eoff,fofe etc.
return total anagram prasent in bigger string 
EX:- aabaabaa, aaba :-- (aaba,abaa,aaba,abaa) Return 4

total Anagram are equal to number of latter ! == (for = 3!), (aaba = 4!)
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
int CountOccurrencesOfAnagrames(string b, string s){
    map<char, int>freq;
    for(char c:s) freq[c]++;

    int k = s.size();
    int count  = freq.size();
    int i=0, j=0, ans = 0;
        while(j < b.size()){
            // freq.end is default function batata hai ki wo val dhund rahe hai wo map me nhi hai to yaha pe agar wo value hai to hi remaining work karna hai
            if(freq.find(b[j]) != freq.end()){ // yaha pe har char jo string me hai uske liye check karge ki wo map me hai kya 

                freq[b[j]]--; // yaha aay matlab val map me hai to usko -- karna hai
                if(freq[b[j]] == 0) count--; // agar val 0 ho jay to count --
            }
            
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                if(count == 0) ans++; //jab count 0 hai matlab anagram hai

                //yaha same kam i ke liye karna hai par ulta agar val map me hai to count ++ karna hai or map me val ki key bhi ++ hogi
                if(freq.find(b[i]) != freq.end()){
                    if(freq[b[i]] == 0) count++;
                    freq[b[i]]++;
                }
                i++;
                j++;
            }
        }
        return ans;
}

int main(){
    string bigger = "aabaabaa";
    string smaller = "aaba";
    cout<< CountOccurrencesOfAnagrames(bigger,smaller);
}
// minor style fix
