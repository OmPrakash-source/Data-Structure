#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;
bool compare(pair<int,int>p1 , pair<int,int>p2){
    return p1.second < p2.second; // compair second value for each start or end ascending 
    // return p1.second > p2.second; // compair second value for each start or end descending
    // return p1.first < p2.first; // compair first value for each start or end descending
    // return p1.first > p2.first; // compair first value for each start or end descending

}
int main(){
    vector<int>start = {0,1,3};
    vector<int>end = {9,2,4};
    vector<pair<int,int>>activitie(3 , make_pair(0,0)); // make pair is a inbuid function of pair
    activitie[0] = make_pair(0,9);
    activitie[1] = make_pair(1,2);
    activitie[2] = make_pair(3,4);

    for(int i=0 ;i<activitie.size();i++){
        cout<<"A"<<i<<" :"<<activitie[i].first<<","<<activitie[i].second<<endl;   
    }
    sort(activitie.begin(), activitie.end(), compare); //It's a vector sorting pre defind function

    cout<<"__________________________ sorting ______________________________\n";

    for(int i=0 ;i<activitie.size();i++){
        cout<<"A"<<i<<" :"<<activitie[i].first<<","<<activitie[i].second<<endl;   
    }

    return 0;
}
// minor style fix

// final cleanup pass
