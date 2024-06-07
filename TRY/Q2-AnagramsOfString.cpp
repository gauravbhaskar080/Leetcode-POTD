#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> findAnagrams(const vector<string>& strings, const string& S) {
    string sorted_S = S;
    sort(sorted_S.begin(), sorted_S.end());
    
    vector<string> anagrams;
    for (const string& str : strings) {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        if (sorted_str == sorted_S) {
            anagrams.push_back(str);
        }
    }
    
    return anagrams;
}

int main() {
    int N;
    cin >> N;
    
    vector<string> strings(N);
    for (int i = 0; i < N; ++i) {
        cin >> strings[i];
    }
    
    string S;
    cin >> S;
    
    vector<string> anagrams = findAnagrams(strings, S);
    
    if (anagrams.empty()) {
        cout << -1 << endl;
    } else {
        for (const string& anagram : anagrams) {
            cout << anagram << endl;
        }
    }
    
    return 0;
}
