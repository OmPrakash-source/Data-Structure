#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    map<char,int>m;
    int i=0;
    cout<<m.count(i); //
    // for create a unordered map
    unordered_map<string,float>m;
    //assining
    m["India"] = 150.66;
    m["China"] = 150.43;
    m["US"] = 50.5;
    m["UK"] = 20.5;
    m["Napal"] = 10.5;
    //print single value
    cout<<m["India"]<<endl;
    //full print
    for (pair<string,float>country:m){
        cout<<country.first<<", "<<country.second<<endl;
    }
    //rehase
    // m.rehash(1);

    cout<<m.size()<<endl;

    //erase
    // m.erase("US");

    for (pair<string,float>country:m){
        cout<<country.first<<", "<<country.second<<endl;
    }
    //exist of not
    // if(m.count("US")){
    //     cout<<"US is exist\n";
    // }else{
    //     cout<<"US dose't exist\n";
    // }
// ____________________________ map _____________________
    //order maintain
    map<string,int>p;
    p["Japan"] = 20;
    p["Korea"] = 15;
    p["Sigapur"] =5;
    p["Africa"] =50;
        int i = 1;
        cout<<"Order is maintain \n";
    for(pair<string,int>country: p){
        cout<<i<<". "<<country.first<<"' "<<country.second<<endl;
        i++;
    }

    
}
// minor style fix
