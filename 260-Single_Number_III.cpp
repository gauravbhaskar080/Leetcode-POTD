#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
TC: O(n)
SC: O(n)
*/
vector<int> singleNumber(vector<int>& nums){
    unordered_map<int,int> mp;
    vector<int> ans;
    for(int i : nums){
        mp[i]++;
    }

    for(auto x : mp){
        if(x.second == 1){
            ans.push_back(x.first);
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> singleElements = singleNumber(nums);
    cout << "Single Elements Array = ";
    for (int num : singleElements) {
        cout << num << " ";
    }
    return 0;
}