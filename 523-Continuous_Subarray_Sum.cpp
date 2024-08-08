#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k){

    int Sum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {

        // Edge Case , consecutive zeros always give true answer
        if (nums[i - 1] == 0 && nums[i] == 0)
        {
            return true;
        }

        Sum += nums[i];

        if (Sum % k == 0) // Check if the cumulative sum is divisible by k
            return true;

        int j = 0;
        int tempSum = Sum;

        while ((i - j) > 1 && tempSum >= k)
        {
            tempSum -= nums[j];
            j++;

            if (tempSum % k == 0)
            { // Check if temporary sum is divisible by k
                return true;
            }
        }
    }
    // If no valid subarray is found, return false
    return false;
}

int main()
{
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << checkSubarraySum(nums, k) << endl;
    return 0;
}