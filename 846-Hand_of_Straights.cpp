#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//TC : O(n*log n)
//SC : O(1)
bool helper(vector<int> &hand, int groupSize, int i, int n){
    int nextEle = hand[i]+1;
    hand[i] = -1;
    int count = 1;
    i+=1;
    while(i<n && count<groupSize){
        if(hand[i] == nextEle){
            nextEle = hand[i]+1;
            hand[i] = -1;
            count++;   
        }
        i++;
    }
    if(count != groupSize){
        return false;
    }
    else return true;
}
bool isNStraightHand(vector<int> &hand, int groupSize){
    sort(hand.begin(), hand.end());
    int n = hand.size();
    if (n % groupSize != 0)
        return false;
    for (int i = 0; i < n; i += groupSize)
    {
        if (hand[i] >= 0)
        {
            if (!helper(hand, groupSize, i, n))
            {
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    cout << isNStraightHand(hand, groupSize) << endl;
    return 0;
}