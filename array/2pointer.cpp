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

// Rotate Array by kth position or ->> size of array is rotate same orignal array
// like size of arr-> 7 and rotateion also 7 so is similer to orignal array
// then find the remaining value D = D % size (15 -> 7+7+1) 15 % 7 = 1

void bruatRotedarr(vector<int>arr,int n,int d){ //O(d) + O(n-d) + O(d) = O(n+d) and space => O(d)
    vector<int>temp;
    for(int i=0;i<d;i++){
        temp.push_back(arr[i]); // push D'th element from temp
    }
    for(int i=d;i<n;i++){
        arr[i-d] = arr[i]; //shift from d to n ->i=d (d-d = 0 dth element shift to 0th element)
    }
    for(int i=n-d;i<n;i++){
        arr[i] = temp[i-(n-d)]; //n-d => 7-3 = 4 || it start to n-d that is 4 so temp (4-4 = 0)"their 0 is idx" similer
    }                           //arr[4]=temp[0] || temp 5-4 = 1 or 6-4 = 2 that is idx || idx (4) of arr store idx of (0) from temp
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
} 

 void reverse(vector<int>&arr,int st,int end){
    while(st <= end){
        int temp = arr[st];
        arr[end] = arr[st];
        arr[end] = temp;
        st++;
        end--;
    }
 }
 
 void optimalRotate(vector<int>&arr, int n, int d){
    reverse(arr,0,d);
    reverse(arr,d,n);
    reverse(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
 }
int main(){
    vector<int>arr = {1,2,2,3,3,3,5,6};
    int n = arr.size();
    // cout<<"twoPointer Approch "<<twoPointer(arr,n)<<endl;
    // OneLeft(arr,n);
    optimalRotate(arr,n,6);
    
    return 0;
}