#include<bits/stdc++.h>
using namespace std;

// FROG JUMP with K Distance (CodeStudio // CodingNinjas)

// Method 1 : Using Simple Recursion (with Memoization)

int frogJumpK(int ind, int k, vector<int> &energy, vector<int> &dp){

    if(ind == 0) return 0;

    int minSteps = INT_MAX,jump = INT_MAX;
    for(int j =1;j<k;j++){
        if(ind-j>= 0) int jump = frogJumpK(ind-j,k,energy,dp) + abs(energy[ind] - energy[ind-j]);
        minSteps = min(minSteps,jump);
    }
    
    return minSteps;
}

// // Method 2 : Using Tabulation

// int frogJumpTab(vector<int> &energy, vector<int> &dp){

//     dp[0] = 0;
//     for(int i=1;i<energy.size();i++){
//         int fs = dp[i-1] + abs(energy[i] - energy[i-1]);
//         int ss = INT_MAX;
//         if(i > 1) ss = dp[i-2] + abs(energy[i] - energy[i-2]);
//         dp[i] = min(fs,ss);
//     }

//     return dp[energy.size() - 1];
// }


// // Optimisation (Space Optimisation)

// int frogJumpOptimsed(vector<int> &energy){
//     int prev = 0,sprev=0;
//     int curEnergy;

//     for(int i =1;i<energy.size();i++){
//         int fs = prev + abs(energy[i] - energy[i-1]);
//         int ss = INT_MAX;
//         if(i > 1) ss = sprev + abs(energy[i] - energy[i-2]);
//         curEnergy = min(fs,ss);
//         sprev = prev;
//         prev = curEnergy;
//     }

//     return prev;
// }


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
    cout << frogJumpK(stairs,2,energy,dp) << endl;
    return 0;
}