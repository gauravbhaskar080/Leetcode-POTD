#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(1)
int appendCharacters(string s, string t){
    int n = s.length(), m = t.length();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            j++;
        }
        i++;
    }
    return m - j;
}
int main(){
    string s, t;
    s = "coaching", t = "coding";
    cout << appendCharacters(s, t) << endl;
    return 0;
}