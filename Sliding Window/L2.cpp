/*
find first Nagative number on givven array 
*/

#include<iostream>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
void window(int arr[], int n, int k){
    deque<int>q;
    //first window
    for(int i=0; i<k; i++){
        if(arr[i] < 0){
            q.push_back(i);
        }
    }
    //remaining window
    for(int i=k; i<n; i++){
        // prev value print karna hai
        if(q.empty()) cout<<0<<" "; // agar empty hai to 0
        else cout<<arr[q.front()]<<" ";  // agar value hai to q.front ki value jo bhi index pe hai wo array me jaha bhi hai usko print karna hai

        // out off window element 
        while((!q.empty()) && (i - q.front() >= k)){
            q.pop_front();
        }
        // current element check
        if(arr[i] < 0) q.push_back(i);
    }
    // last window ke liye print agar q me koi or element hai to usko bhi print karna hai 
    while(!q.empty()){
            cout<<arr[q.front()]<<" ";
            q.pop_front();
    }
}

void firstnagative(vector<int>vec,int k){
    queue<int>q;
    int i = 0, j= 0;
    while(j < vec.size()){
        // Case 1: J -ve hai ( Calculation )
        if(vec[j] < 0){ // j wala kam har bar top pe ho jayga 
            q.push(j);
        }
        // Case 2: window not found so increase j
        if(j-i+1 < k){
            j++;
        }else if(j-i+1 == k){   // Case 3: Window found
            // Parform opration( Calculation )
            if(q.empty()){
                cout<<0<<" ";
            }else{
                cout<<vec[q.front()]<<" ";
            }
            // Remove out of bound elemant (Slide window)
            if(vec[i] == vec[q.front()]){
                q.pop();
            }
            // Make window size constent
            i++;
            j++;
        }
    }
    while(!q.empty()){
        q.empty()? cout<<0<<" ":cout<<vec[q.front()]<<" ";
        q.pop();
    }
    
}
int main(){
    // int arr[] = {-8, 2, 3, -6, 10};
    int arr[] = {-8, -2, 3, 6, 10, -3, 10, -12};
    vector<int>vec = {-8, -2, 3, 6, 10, -3, 10, -12};
    int k = 3; 
    int n = sizeof(arr)/ sizeof(int);
    window(arr,n,k);
    cout<<endl;
    firstnagative(vec,k);
}