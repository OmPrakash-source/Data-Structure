#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int hourglassSum(vector<vector<int>>& arr) {
    int max_sum = INT_MIN;  // Initialize max_sum to the smallest possible integer value2

    // Loop through the matrix and calculate the sum for each hourglass
    for (int i = 1; i < 5; i++) {  // We loop from row 1 to row 4 (inclusive)
        for (int j = 1; j < 5; j++) {  // We loop from column 1 to column 4 (inclusive)
            // Calculate the sum of the current hourglass
            int top = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1];
            int mid = arr[i][j];
            int bottom = arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];
            int hourglass = top + mid + bottom;

            // Update the max_sum if the current hourglass sum is larger
            if (hourglass > max_sum) {
                max_sum = hourglass;
            }
        }
    }

    return max_sum;
}

int main() {
    // Initialize the 6x6 matrix
    vector<vector<int>> arr(6, vector<int>(6));


    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout<<"enter :";
            cin >> arr[i][j];
        }
    }

    // Call the function to calculate the maximum hourglass sum
   cout<<"total sum is "<< hourglassSum(arr);

    return 0;
}