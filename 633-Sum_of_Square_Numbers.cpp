#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//TC : O(log n)
//SC : O(1)
bool judgeSquareSum(int c) {
    long i = 0;
    long j = sqrt(c);
    while(i <= j){
        long mid = i*i + j*j;
        if(mid == long(c)){
            return true;
        }
        else if(mid > long(c)){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){
    int c1 = 5;
    cout<<judgeSquareSum(c1)<<endl;
    int c2 = 3;
    cout<<judgeSquareSum(c2)<<endl;
    return 0;
}