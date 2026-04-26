#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key){
    int st = 0, ed = n-1;
    while(st <= ed){
        int mid = st + (ed - st) / 2;
        if(arr[mid] == key){
            return mid;
        } else if(arr[mid] < key){
            st = mid+1;
        }else{
            ed = mid-1;
        }
    }
    return -1;
}
int linearSearch(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {2,4,5,6,7,9,10,23};
    int n = sizeof(arr)/sizeof(int);
    cout<<binarySearch(arr, n, 10)<<endl;
    int m = sizeof(arr)/sizeof(int);
    int arr_1[] = {4, 2, 6, 16, 8, 12, 10, 14};
    cout<<linearSearch(arr_1, m, 16)<<endl;
}