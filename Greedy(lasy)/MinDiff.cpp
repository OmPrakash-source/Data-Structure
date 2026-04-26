// Minimum absolute difference 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int>A = { 4, 1, 8, 7};
    vector<int>B = { 2, 3 ,6 ,5};

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
      int absDiff = 0;
      for(int i = 0 ;i < A.size();i++){
        absDiff += abs(A[i] - B[i]);  // abs is predefind func that return absolute value 
      }
      cout<<" Min abs diff = "<<absDiff;
}
// minor style fix
