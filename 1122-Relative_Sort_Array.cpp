#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<arr1.size();i++){
        mp[arr1[i]]++;
    }
    for(int i=0;i<arr2.size();i++){
        while(mp[arr2[i]]>0){
            ans.push_back(arr2[i]);
            mp[arr2[i]]--;
        }
    }
    for(int i=0;i<10001;i++){
        while(mp[i]>0){
            ans.push_back(i);
            mp[i]--;
        }
    }
    return ans;
}

int main(){
    vector<int> arr1={2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2={2,1,4,3,9,6};
    vector<int> ans=relativeSortArray(arr1,arr2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}