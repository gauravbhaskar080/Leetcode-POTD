#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
TC : O(n*log n)
SC : O(log n)
*/
int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                count+=nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return count;
    }

int main(){
    vector<int> nums = {3,2,1,2,1,7};
    cout<<minIncrementForUnique(nums)<<endl;
    return 0;
}