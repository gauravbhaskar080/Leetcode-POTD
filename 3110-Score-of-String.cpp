#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//TC : O(n)
//SC : O(1)
int scoreOfString(string s){
    int ans = 0;
    for(int i=1;i<s.size();i++){
        ans += abs(s[i-1] - s[i]);
    }
    return ans;
}

int main(){
    string s = "hello";
    cout<<scoreOfString(s)<<endl;
    return 0;
}