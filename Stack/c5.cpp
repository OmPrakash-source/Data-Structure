#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//_______________________________________________ greaterright __________________________________________ 
        void greaterright(vector<int> &arr , vector<int> &ans){  // if change value in this it change in main 
            stack<int>st;
            int n = arr.size();         // last index of array 

            ans[n - 1] = -1;            // last value's nsl is -1 becouse no one value is exixt in right side of n
            st.push(arr[n-1]);          // push -1 in last answer array
            for(n = n-2 ; n>=0 ; n--){
                int curr = arr[n];
                if(!st.empty() && curr >=st.top()){  // अगर स्टैक खाली nahi है or (top < curr) se to POP 
                    st.pop();
                }
                // if else condition
                ans[n] = st.empty()? -1 : st.top(); //अगर स्टैक खाली है, तो nsl[n] = -1 होगा, अन्यथा nsl[n] = st.top() 

                st.push(curr);
            }
            for(int i=0 ;i<ans.size(); i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
// Function to find the next smaller elements to the right
void nextSmallerRight(const vector<int>& height, vector<int>& nsr) {
    stack<int> st;
    int n = height.size();

    nsr[n - 1] = -1; // Last value has no smaller value on its right
    st.push(height[n - 1]); // Push the last value of height into the stack

    for (int i = n - 2; i >= 0; i--) {
        int curr = height[i];

        while (!st.empty() && curr <= st.top()) {
            st.pop();
        }

        nsr[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Print results
    cout << "Next Smaller Right: ";
    for (int i = 0; i < n; i++) {
        cout << nsr[i] << " "; 
    }
    cout << endl;
}

// Function to find the next smaller elements to the left
void nextSmallerLeft(const vector<int>& height, vector<int>& nsl) {
    stack<int> st;
    int n = height.size();

    nsl[0] = -1; // First value has no smaller value on its left
    st.push(height[0]); // Push the first value into the stack

    for (int i = 1; i < n; i++) {
        int curr = height[i];

        while (!st.empty() && curr <= st.top()) {
            st.pop();
        }

        nsl[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Print results
    cout << "Next Smaller Left: ";
    for (int i = 0; i < n; i++) {
        cout << nsl[i] << " ";
    }
    cout << endl;
}
//__________________________________________ Histogrom __________________________________________ 
    void Histogrom(vector<int> height){
        int n = height.size();
        vector<int>nsl(n);
        vector<int>nsr(n);
        stack<int>st;

        //for left smaller
        // nsl[0] = -1;     no need to heandl this case
        // st.push(0);
        for(int i =0;i<n;i++){
            int curr = height[i];
            while(!st.empty() && curr <= height[st.top()]){
                st.pop();
            }
            nsl[i] = st.empty()? -1: st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        // for right smaller
        // nsr[n-1] = -1;    no need to heandl this case loop can heandl
        // st.push(n-1);
        for(int i =n-1; i>=0; i--){
            int curr = height[i];
            while(!st.empty() && curr <= height[st.top()]){
                st.pop();
            }
            nsr[i] = st.empty()? -1: st.top();
            st.push(i);
        }
          int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nsr[i] - nsl[i] - 1; // Width of the rectangle
        int area = height[i] * width;   // Area of the rectangle
        maxArea = max(maxArea, area);
    }

    cout << "Max area of histogram: " << maxArea << endl;
    }
int main(){
    vector<int>vec = {2,1,5,6,2,3};
    vector<int>nsl(vec.size(), 0);
    // greaterright(vec , nsl);
    nextSmallerRight(vec , nsl);
    nextSmallerLeft(vec , nsl);
    Histogrom(vec);
}
// minor style fix
