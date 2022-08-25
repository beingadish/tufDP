#include<bits/stdc++.h>
using namespace std;

// Ninja's Training (CodeStudio // CodingNinjas)   Link --> https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0

// Simple Recursive Solution

int ninja(int day, int last, vector<vector<int>> &pts){
    if(day == 0){
        int maxpt =0;
        for(int i =0;i<3;i++){
            if(i != last) maxpt = max(maxpt,pts[0][i]);
        }
        return maxpt;
    }
    
    int maxpt = 0;
    for(int j =0;j<3;j++){
        if(j != last) {
            int points = pts[day][j] + ninja(day-1,j,pts);
            maxpt = max(maxpt,points);
        }
        
    }
    
    return maxpt;
}

// DP Implemented Solution (Memoization)

int ninjaDP(int day, int last, vector<vector<int>> &pts, vector<vector<int>> &dp){
    if(day == 0){
        int maxpt =0;
        for(int i =0;i<3;i++){
            if(i != last) maxpt = max(maxpt,pts[0][i]);
        }
        return maxpt;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxpt = 0;
    for(int j =0;j<3;j++){
        if(j != last) {
            int points = pts[day][j] + ninjaDP(day-1,j,pts,dp);
            maxpt = max(maxpt,points);
        }
        
    }
    
    return dp[day][last] = maxpt;
}

void input2dArray(vector<vector<int>> &arr){
    int j = arr.size();
    for(int i = 0;i<j;i++){
        cout << "Enter the activity points for Day - " << i+1 << " : ";
        for(int k =0;k<3;k++) cin >> arr[i][k];
    }
}

int main(){
    int n;
    cout << "Enter number of Days : ";
    cin >> n;
    vector<vector<int>> days(n,vector<int>(3)),dp(n,vector<int>(4,-1));
    input2dArray(days);
    cout << "The maximum points that the Ninja can Score by performing different tasks on adjacent days is : " << ninjaDP(n-1,3,days,dp) << endl << endl;
    return 0;
}