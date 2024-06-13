#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int ans = 0;
    for(int i = 0; i < seats.size(); i++){
        ans += abs(seats[i] - students[i]);
    }
    return ans;
}

int main(){
    vector<int> seats = {4, 1, 5, 9};
    vector<int> students = {1, 3, 2, 6};
    cout << minMovesToSeat(seats, students) << endl;
    return 0;
}