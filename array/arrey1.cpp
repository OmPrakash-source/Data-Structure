#include<iostream>
#include<vector>
using namespace std;

int countAllele(int arr[] , int n){
    int total = 0;
    for(int i=0; i<n;i++){
        total +=arr[i];
    }
    return total;
}

bool isSorted(int arr[],int n){
    int ans[] = {};
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}
// find max sum of given sliding window
int slidingWindow(int arr[], int n,int k){
    int maxsum = INT32_MIN;
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    for(int i=k ; i<n-1;i++){
        sum = sum + arr[i] - arr[i-k];
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

// first max element of arr

    int firstMax(int arr[],int n){
        int larger = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] > larger){
                larger = arr[i];
            }
            // if(arr[i] > arr[i+1] ){      // another approch
            //     largest = max(largest,arr[i]);
            // }
        }
        return larger;
    }

// largest second element --------- BRUTE APPROCH -> Sort an arr then n-2 value is second sortest
                                // BETTER APPROCH -> Compeare to first max value 
int secondMax(int arr[],int n){
    int largest = arr[0];
    int secondlargest = -1;
    for(int i=1; i<n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i] > secondlargest && arr[i] != largest){
            secondlargest = arr[i];
        }
    }
    return secondlargest;
}
// G.O.A.T (optimized) method

    int secondMaxVal(vector<int>arr,int n){
        int largest = arr[0];
        int seclargest = INT32_MAX;
        for(int i=0;i<n;i++){
            if(arr[i] > largest){
                seclargest = largest;
                largest = arr[i];
            } else if(arr[i] != seclargest && arr[i] > seclargest){
                seclargest = arr[i];
            }
        }
        return seclargest;
    }
    int secondSmallVal(vector<int>arr,int n){
        int smallest = arr[0];
        int ssmallest = INT32_MAX;
        for(int i=0;i<n;i++){
            if(arr[i] > smallest){
                ssmallest = smallest;
                smallest = arr[i];
            } else if(arr[i] != ssmallest && arr[i] > ssmallest){
                ssmallest = arr[i];
            }
        }
        return ssmallest;
    }
    
// _____________________ Remove duplicate return total number 
 int removedupSorted(vector<int>arr, int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
        }
    }
    return i;//return total number 
 }
int main(){
    // int arr[] ={2, 3, 11, 99, 12};
    // int n = sizeof(arr)/sizeof(int);

   vector<int>arr={2, 3, 11, 12, 12, 12, 13, 13, 14, 99};
   int n=arr.size();
    // cout<<"Second maximum value is : "<<secondMaxVal(arr,n);
    cout<<removedupSorted(arr,n);
}
// minor style fix

// final cleanup pass
