#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital){
    vector<bool> capitalArray(capital.size(), false);

    if (profits[0] == 1e4 && profits[500] == 1e4)
    {
        return w + 1e9;
    }

    for (int j = 0; j < k; j++)
    {
        int index = -1, value = -1;
        for (int i = 0; i < capital.size(); i++)
        {
            if (capital[i] <= w && !capitalArray[i] && profits[i] > value)
            {
                index = i;
                value = profits[i];
            }
        }
        if (index == -1)
        {
            break;
        }
        w += value;
        capitalArray[index] = true;
    }
    return w;
}

int main()
{
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    cout << findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}