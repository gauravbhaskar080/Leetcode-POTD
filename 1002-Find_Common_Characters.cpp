#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<string> commonChars(vector<string> &words){
    int n = words.size();
    vector<int> final_count(26,0);
    for(auto word : words[0]){
        final_count[word - 'a']++; 
    }
    for(int j=1;j<n;j++){
        vector<int> temp_count(26,0);
        for(auto word : words[j]){
            temp_count[word - 'a']++;
        }
        for(int i=0;i<26;i++){
            final_count[i] = min(final_count[i],temp_count[i]);
        }
    }

    vector<string> ans;
    for(int i=0;i<26;i++){
        int count=final_count[i];
        while(count--){
            ans.push_back(string(1,'a'+i));
        }
    }
    return ans;
}

int main(){
    vector<string> words = {"bella","label","roller"};
    vector<string> ans = commonChars(words);
    for(auto word : ans){
        cout<<word<<" ";
    }
    cout<<endl;
    return 0;
}