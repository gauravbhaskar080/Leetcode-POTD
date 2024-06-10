#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int heightChecker(vector<int>& heights) {
    int count=0;
    vector<int> temp=heights;
    sort(temp.begin(),temp.end());
    for(int i=0;i<heights.size();i++){
        if(temp[i]!=heights[i]){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> heights={1,1,4,2,1,3};
    cout<<heightChecker(heights)<<endl;
    return 0;
}