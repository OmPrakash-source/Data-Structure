#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.
 int gassta(vector<int>&gas, vector<int>&cost){
    int bal =0, def = 0, st = 0;
    for(int i = 0;i<gas.size(); i++){
        bal += gas[i] - cost[i];
        if(bal < 0){
            def += bal;
            bal = 0;
            st = i+1;
        }
    }
    if(def + bal >= 0) return st;
    else return -1;
 }
int main(){
    vector<int>gas = {1,2,3,4,5};
    vector<int>cost = {3,4,5,1,2};
    cout<<gassta(gas, cost);
    return 0;
}
// minor style fix

// final cleanup pass
