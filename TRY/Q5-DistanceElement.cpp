#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void countDistinctAlphabets(const string& input) {
    map<char, int> frequency;

    for (char c : input) {
        frequency[c]++;
    }

    vector<char> keys;
    for (const auto& pair : frequency) {
        keys.push_back(pair.first);
    }
    sort(keys.begin(), keys.end());

    for (char c : keys) {
        cout << c << ":" << frequency[c] << endl;
    }
}

int main() {
    string input;
    cin >> input;

    countDistinctAlphabets(input);

    return 0;
}
