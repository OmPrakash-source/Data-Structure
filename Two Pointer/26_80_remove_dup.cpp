#include<iostream>
#include<vector>
using namespace std;
int removeDupI(vector<int>vec){
    int j = 1;
    for(int i=1;i<vec.size();i++){
        if(vec[i-1] != vec[i]){     //agar prev != curr to dup nhi hai
            vec[j] = vec[i];        // j hamesa dup pe point karega i ke pahle wale pe
            j++;                    // fir j ko increase jab loop katam matlab unique 1 size hai
        }
    }
    return j; // kitni value hai unique wo batana hai
}

int removeDupII(vector<int>vec){
    int count = 1, j =1;
    for(int i=1; i<vec.size(); i++){
        if(vec[i-1] == vec[i]) count++; // agar dup hai to count karo kitne hai
        else count = 1;                 // agar dup nhi hai to count ko reset karna hai

        if(count <= 2){                 // jab count 2 se chota ya 2 hai to ye
            vec[j] = vec[i];
            j++;
        }
    }
    return j-1;
}
int main(){
    vector<int>vec = {0,1,1,2,3,3};
    // output - 0,1,2,3 = 4
    cout<<removeDupII(vec)<<endl;
    // output - 0,1,1,2,3,3 = 6
    cout<<removeDupI(vec)<<endl;
}