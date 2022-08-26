#include<bits/stdc++.h>
using namespace std;

// DynamicProgramming (DP) on [Grids / 2D Matrix]

// Standard Problems asked in MNCs:

//  1. Count Paths 
//  2. Count Paths with Obstacles
//  3. Minimum Path Sum
//  4. Maximum Path Sum
//  5. Triangle Problem
//  6. 2-Start Points

// TOTAL UNIQUE PATHS (CodeStudio // CodingNinjas)  Link --> https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

// Using Recursion & Memoization

int totUniPaths(int i, int j, vector<vector<int>> &dp){
    
    if(i == 0 && j == 0) return 1;
    
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int up = totUniPaths(i-1,j,dp);
    int left = totUniPaths(i,j-1,dp);
    return dp[i][j] = up + left;
}

// Using Tabulation

int totUniPathsTAB(int i, int j, vector<vector<int>> &dp){

    for(int x = 0;x<i;x++){
        for(int y = 0;y<j;y++){
            if(x == 0 && y == 0) dp[x][y] = 1;
            else{
                int up=0;int left =0;
                if(x > 0) up = dp[x-1][y];
                if(y > 0) left = dp[x][y-1];
                dp[x][y] = up + left;
            }
        }
    }


    return dp[i-1][j-1];

}

// Space Optimization (2D Space Optimization)

int totUniPathsOPTI(int i , int j){
    
}

int main(){
    int m , n;
    cout << "Enter the Size of GRID as m n : ";
    cin >> m >> n;
    vector<vector<int>> dp(m,vector<int>(n,0));
    cout << "Total number of Unique Path from [0][0] to [" << m-1 << "][" << n-1 << "] are : " << totUniPathsTAB(m,n,dp) << endl << endl; 
    return 0;
}