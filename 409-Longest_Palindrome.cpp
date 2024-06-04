#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s){
    unordered_set<char> st;
    int ans = 0;
    for (char ch : s)
    {
        if (st.find(ch) != st.end())
        {
            st.erase(ch);
            ans += 2;
        }
        else
        {
            st.insert(ch);
        }
    }

    return (st.size() > 0) ? ans + 1 : ans;
}

int main(){
    string s = "abccccdd";
    cout << longestPalindrome(s);
    return 0;
}