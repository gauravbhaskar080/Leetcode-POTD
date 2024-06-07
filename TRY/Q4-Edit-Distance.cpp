#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int editDistance(const string &word1, const string &word2)
{
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = j; // If first string is empty, insert all characters of second string
            }
            else if (j == 0)
            {
                dp[i][j] = i; // If second string is empty, remove all characters of first string
            }
            else if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1]; // If characters match, no operation needed
            }
            else
            {
                dp[i][j] = 1 + min({
                                   dp[i - 1][j],    // Remove
                                   dp[i][j - 1],    // Insert
                                   dp[i - 1][j - 1] // Replace
                               });
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    cout << editDistance(word1, word2) << endl;

    return 0;
}
