#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
First Approach
TC : O(n^3)
SC : O(1)
*/

int countTriplets1(vector<int>&arr){
    int n=arr.size();
    int count=0,xora,xorb;

    for(int i=0;i<n;i++){
        xora=0;
        for(int j=i+1;j<n;j++){
            xora = xora ^ arr[j-1]; //xora for(i to j-1)
            xorb = 0;
            for(int k=j;k<n;k++){
                xorb = xorb ^ arr[k]; //xorb for(j to k)
                if(xora == xorb){
                    count++;
                }
            }
        }
    }
    return count;
}

/*
Second Approach
TC : O(n^2)
SC : O(n)
*/

int countTriplets2(vector<int>&arr){
    int n=arr.size(),ans=0;
    vector<int> prefixXor(n+1,0);
    /*
    arr =         [2 3 1 6 7]
    prefixXor = [0 2 1 0 6 1]
                 i     k      ans  = 3 - (0+1) = 2  prefixXor[i] == prefixXor[k]
                   i       k  ans  = 2
                     i     k  ans  = 2 + ( 5 - (2+1)) = 2+2 = 4;  prefixXor[i] == prefixXor[k]
                       i   k  ans  = 4;
                         i k  ans  = 4;
    */                   
    for(int i=0;i<n;i++){
        prefixXor[i+1] = prefixXor[i]^arr[i];
    }

    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if(prefixXor[i] == prefixXor[k]){
                ans += k + (i+1);
            }
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {2,3,1,6,7};
    cout<<"First Approach = "<<countTriplets1(arr)<<endl;
    cout<<"Second Approach = "<<countTriplets2(arr)<<endl;
    return 0;
}

/*
Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
*/

