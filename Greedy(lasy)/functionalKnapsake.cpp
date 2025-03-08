#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparison function for sorting based on ratio in descending order
bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first;
}

// Fractional Knapsack implementation
int Knapsack(vector<int> val, vector<int> wt, int W) {
    int n = val.size();
    vector<pair<double, int>> ratio(n , make_pair( 0.0 , 0)); // Holds value-to-weight ratios and indices

    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        double r = val[i] / (double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    // Sort items by ratio in descending order
    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0.0; // Maximum value we can take

    // Apply the fractional knapsack approach
    for (int i = 0; i < n; i++) {
        int idx = ratio[i].second; // Get the original index of the item
        if (wt[idx] <= W) {
            // Take the whole item
            ans += val[idx];
            W -= wt[idx];
        } else {
            // Take a fraction of the item
            ans += W * ratio[i].first;
            W = 0;
            break;
        }
    }

    cout << "Maximum value: " << ans << endl;
    return ans;
}

int main() {
    vector<int> value = {100, 120, 60};
    vector<int> weight = {20, 10, 30};
    int capacity = 50;
    Knapsack(value, weight, capacity);
    return 0;
}
