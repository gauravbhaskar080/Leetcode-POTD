#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
TC: O(log n)
SC: O(1)
*/

void sortColors(vector<int> &nums){
    int low = 0, mid = 0, high = nums.size() - 1;
    while(mid<=high){
        if(nums[mid]==0) {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            mid++;
            high--;
        }
    }

}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(auto x:nums){
        cout<<x<<" ";
    }

    return 0;
}