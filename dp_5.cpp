#include<bits/stdc++.h>
using namespace std;

// Maximum sum of Non-Adjacent Elements (CodeStudio // CodingNinjas)    Link --> https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261


void inputArray(vector<int> &a){
    cout << "Enter the Integers : ";
    for(int i =0;i<a.size();i++) cin >> a[i];
    cout << endl;
}

void pArray(vector<int> &arr){
    cout << "Printing Array" << endl;
    for(int j =0;j<arr.size();j++) cout << arr[j] << " ";
    cout << endl;
}

// Simple Recursion Solution

int maxSumAdj(int ind, vector<int> &arr){

    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    int pick = arr[ind] +  maxSumAdj(ind - 2, arr);
    int notPick = maxSumAdj(ind-1,arr);

    return max(pick,notPick);
}

// Applying DP Memoization

int maxSumAdjDP(int ind, vector<int> &arr, vector<int> &dp){
    if(dp[ind] != -1) return dp[ind];
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    int pick = arr[ind] +  maxSumAdj(ind - 2, arr);
    int notPick = maxSumAdj(ind-1,arr);

    return dp[ind] = max(pick,notPick);
}


// Tabulation Method

int maxSumAdjTAB(vector<int> &integers, vector<int> &dp){
    dp[0] = integers[0];
    int neg = 0;

    for(int i = 1;i<integers.size();i++){
        int take = integers[i];
        if(i > 1) take += dp[i-2];
        int notTake = dp[i-1];
        dp[i] = max(take,notTake);
    }

    pArray(dp);

    return dp[integers.size() - 1];
}

int main(){
    int n;
    cout << "Enter the number of Integers : ";
    cin >> n;
    vector<int> integers(n,0);
    vector<int> dp(n,-1);
    inputArray(integers);
    cout << "Maximum Sum of Adjacents Elements is : " << maxSumAdjTAB(integers,dp) << endl;
    return 0;
}