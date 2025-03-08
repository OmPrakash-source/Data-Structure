#include<iostream>
using namespace std;

int function(int arr[] , int n){
    int total = 0;
    for(int i=0; i<n;i++){
        total +=arr[i];
    }
    return total;
}
int main(){
    int arr[7] ={2, 4, 6, 8, 9, 10, 20};
    cout<<function(arr , 7);
}