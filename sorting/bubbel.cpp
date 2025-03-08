#include<iostream>
using namespace std;
void print(int arr[],int n){

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int bubbelsort(int arr[],int n){
    for(int i=0 ; i<n ;i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j]){
                //swap(arr[i],arr[j]);
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    print(arr,n);
}

//

int main(){

    int arr[] = {10,80,50,30,60,20};
    int n = sizeof(arr)/sizeof(int);
    bubbelsort(arr, n);
    return 0;
}