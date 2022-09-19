#include<bits/stdc++.h>
using namespace std;

// Ninja & Chocolates (CodeStudio // CodingNinjas)   Link --> https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885


// Recursion + Memoization using 3D DP

int chocolatesMemo(int c, int r, int c1, int c2, vector<vector<int>> &a,vector<vector<vector<int>>> &dp){
    int n = a.size();
    if(c1 < 0 || c1 >= c || c2 < 0 || c2 >= c) return -1e8;
    if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
    if(r == n-1){
        if(c1 == c2) return a[r][c1];
        else return a[r][c1] + a[r][c2];
    }
    
    int maxc = 0;
    for(int dc1 = -1;dc1 < 2;dc1++){
        for(int dc2 = -1; dc2 < 2; dc2++){
            if(c1 == c2) maxc = max(maxc,(a[r][c1] + chocolatesMemo(c,r+1,c1+dc1,c2+dc2,a,dp)));
            else maxc = max(maxc, (a[r][c1] + a[r][c2] + chocolatesMemo(c,r+1,c1+dc1,c2+dc2,a,dp)));
        }
    }
    return dp[r][c1][c2] = maxc;
}

int solution(vector<vector<int>> &grid){
    int  c = grid[0].size();
    int r = grid.size();
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return chocolatesMemo(c,0,0,c-1,grid,dp);
}

void inputGrid(vector<vector<int>> &matrix){
    cout << "Enter the Chocolates in Grid : " << endl;
    for(int i =0;i<matrix.size();i++)
        for(int j =0;j<matrix[0].size();j++)
            cin >> matrix[i][j];
}

int main(){
    cout << "Enter Number of Test Cases : ";
    int t;
    cin >> t;
    while(t--){
    int r,c;
    cout << "Enter Grid Size : ";
    cin >> r >> c;
    vector<vector<int>> choco(r,vector<int>(c));
    inputGrid(choco);
    cout << "Maximum Number of Chocolates that can be taken by Alice & Bob are : " << solution(choco) << endl;
    }
    return 0;
}