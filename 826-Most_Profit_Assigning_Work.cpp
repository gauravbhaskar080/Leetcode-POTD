#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker){
    int maxDifficulty = *max_element(difficulty.begin(), difficulty.end());
    vector<int> maxProfitUpToDifficulty(maxDifficulty + 1, 0);

    for (int i = 0; i < difficulty.size(); ++i){
        maxProfitUpToDifficulty[difficulty[i]] = max(maxProfitUpToDifficulty[difficulty[i]], profit[i]);
    }

    for (int i = 1; i <= maxDifficulty; ++i){
        maxProfitUpToDifficulty[i] = max(maxProfitUpToDifficulty[i], maxProfitUpToDifficulty[i - 1]);
    }

    int totalProfit = 0;
    for (int ability : worker){
        if (ability > maxDifficulty){
            totalProfit += maxProfitUpToDifficulty[maxDifficulty];
        }
        else{
            totalProfit += maxProfitUpToDifficulty[ability];
        }
    }

    return totalProfit;
}

int main()
{
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    cout << maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}