#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
// if array is sorted --> TWO pointer approch
// only reduse a size of main vector to add value only once
int twoPointer(vector<int> &arr,int n ){
    int i=0;
    for(int j=1;j<n;j++){
            if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    
    return i+1;
}

// left Rotate the array by one place
//{1,2,3,4,5} --> {2,3,4,5,1} result
//optimal --> also use for two or three rotation 
void oneLeft(vector<int>arr,int n){ 
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i]; //shift idx i to idx i-1 not include first
    }
    arr[n-1] = temp; //then inlast store first value which store in temp

    //print
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//brute --> approch becouse in their approch we use extra space 
void OneLeft(vector<int>arr,int n){
    vector<int>arr1;
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr1.push_back(arr[i]);
    }
    arr1.push_back(temp);
    //print
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }

}
int main(){
    vector<int>arr = {1,2,2,3,3,3,5,6};
    int n = arr.size();
    // cout<<"twoPointer Approch "<<twoPointer(arr,n)<<endl;
    OneLeft(arr,n);
    
    return 0;
}