#include<iostream>
#include<vector>
using namespace std;
int SlidingWindowMaxSum(vector<int>vec, int k){
    int maxsum = 0, sum = 0;
    for(int i=0; i<vec.size()-k;i++){
        for(int j=i; j<k+i; j++){
            sum+=vec[j];
        }
        maxsum = max(maxsum,sum);
        sum = 0;
    }
    return maxsum;
}

int optimalSliding(vector<int>vec, int k){
    if (vec.empty() || k > vec.size()) return 0;
    int i = 0, j = 0, sum = 0, maxsum = 0;
    while(j < vec.size()){
        sum+=vec[j];
        if(j-i+1 < k){  // K size ki window jab tak equal nhi hua 
            j++;    // j ko k size tak aage badana hai 
        }else if(j-i+1 == k){   // jab j equal huaa
            maxsum = max(maxsum, sum); // max nikal 
            sum -= vec[i]; // size me se last index ka size - kar diya (out of bound)
            // ab size maintain rakhna hai 
            i++; //i ko aage fir 
            j++; //j ko agee
        }
    }
    return maxsum;
}
int main(){
    vector<int>vec{2,5,1,8,2,9,1};
    cout<<optimalSliding(vec, 3)<<endl;
}
// minor style fix
