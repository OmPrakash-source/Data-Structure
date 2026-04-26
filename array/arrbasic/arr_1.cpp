#include<iostream>
using namespace std;
int getUniqe(int arr[],int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans^arr[i];
    }
    return ans;
}
void pair_(int arr[] ,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<" ("<<arr[i]<<" "<<arr[j]<<") ";
        }
        cout<<endl;
    }
}

void shiftRight(int *arr, int n){
    int temp = arr[n-1];
    for(int i=n-1;i>=1;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}
void shiftLeft(int *arr, int n){
    int temp = arr[0];
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void shiftKele(int *arr,int n, int k){
    int temp[k];
    int j=0;
    for(int i=n-k; i<n; i++){
        temp[j++] = arr[i];
    }

    for(int i=n-k-1; i>=0; i--){
        arr[i+k] = arr[i];
    }

    for(int i=0; i<k; i++){
        arr[i] = temp[i];
    }
}
int main(){
    int vec[] = {10,20,30,40,50,60,70};
    int n = sizeof(vec) / sizeof(vec[0]);
    shiftKele(vec, n, 3);
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
}