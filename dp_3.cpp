#include<bits/stdc++.h>
using namespace std;

// FROG JUMP (CodeStudio // CodingNinjas)

// Method 1 : Using Simple Recursion (with Memoization)

int frogJump(int ind, vector<int> &energy, vector<int> &dp){

    if(ind == energy.size()-1) return 0;

    int left = INT_MAX;
    int right = INT_MAX;

    if(dp[ind] != -1) return dp[ind];

    else{
        left = frogJump(ind+1,energy,dp) + abs(energy[ind] - energy[ind+1]);
    if( ind < energy.size() - 2){
        right = frogJump(ind+2,energy,dp) + abs(energy[ind] - energy[ind+2]);
    }

    return dp[ind] = min(left,right);

    }
    
}

// Method 2 : Using Tabulation

int frogJumpTab(vector<int> &energy, vector<int> &dp){

    dp[0] = 0;
    for(int i=1;i<energy.size();i++){
        int fs = dp[i-1] + abs(energy[i] - energy[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = dp[i-2] + abs(energy[i] - energy[i-2]);
        dp[i] = min(fs,ss);
    }

    return dp[energy.size() - 1];
}


void inputArray(int n,vector<int> &arr){
    cout << "Enter the Energy Level at each Staircase : ";
    for(int i =0;i<n;i++) cin >> arr[i];
}

int main(){
    int stairs;
    cout << "Enter the size of the staircase : ";
    cin >> stairs;
    vector<int> energy(stairs),dp(stairs,-1);
    inputArray(stairs,energy);
    cout << "Minimum Energy Required : ";
    cout << frogJumpTab(energy,dp) << endl;
    return 0;
}