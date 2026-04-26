#include<iostream>
#include<vector>
using namespace std;
void print(int arr[],int n){

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
        // arr[i] = arr[i] + arr[mini];
        // arr[mini] = arr[i] - arr[mini];
        // arr[i] = arr[i] - arr[mini]; 
        
        // int temp = arr[i];
        // arr[i] = arr[mini];
        // arr[mini] = temp;
//______________________ bubble sort __________________________
int bubble_sort(int arr[],int n){
    for(int i=0 ; i<n ;i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    print(arr,n);
}

//______________________ insertion sort __________________________

void InsertionSort(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    // print(arr,n);
}
//______________________ selecton sort __________________________
void selectionSort(vector<int>&arr, int n){
    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] <= arr[mini]){
                mini = j;
            }
        }
        if (i != mini) {
            swap(arr[i],arr[mini]);
        }
    }  
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } 
}

int main(){

    int arr[] = {10,80,50,30,60,20};
    vector<int>nums = {10,80,50,30,60,20};
    int n = sizeof(arr)/sizeof(int);
    InsertionSort(nums, nums.size());
     for(int i = 0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}