#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int minPatches(vector<int>& nums, int n) {
    long reach = 0; // Use long to avoid overflow issues.
    int i = 0;
    int count = 0;

    // Loop until we can cover the range [1, n]
    while (reach < n) {
        // If the current number in nums is within the current reachable range
        if (i < nums.size() && nums[i] <= reach + 1) {
            reach += nums[i]; // Extend the range by nums[i]
            i++;
        } else {
            // Otherwise, we need to patch
            reach += reach + 1;
            count++;
        }
        // Debugging output to trace the internal state
        cout << "Current reach: " << reach << ", Count: " << count << ", i: " << i << endl;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 3}; // Example input
    int n = 6;                 // Example target
    cout << "Minimum patches required: " << minPatches(nums, n) << endl;
    return 0;
}
