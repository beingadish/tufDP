#include<bits/stdc++.h>
using namespace std;

// FROG JUMP (CodeStudio // CodingNinjas)

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
    cout << frogJump(0,energy,dp) << endl;
    return 0;
}