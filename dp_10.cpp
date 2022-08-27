#include<bits/stdc++.h>
using namespace std;

// Minimum Path Sum (CodeStudio // CodingNinjas)    Link --> https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?leftPanelTab=0

// SELF-SOLVED SOLUTION (Using Recursion)


void minPathSum(int m, int n, vector<vector<int>> &grid, int sum,vector<int> &ans){
    cout << "To m = " << m << " n = " << n << " sum = " << sum << endl;
    if(m == 0 && n == 0) {
        ans.push_back(sum);
        cout << "RETURNING" << endl;
        return;
    }

    else{
        if(m > 0){
            sum += grid[m-1][n];
            minPathSum(m-1,n,grid,sum,ans);
            sum -= grid[m-1][n];
        }
        if(n > 0){
            sum += grid[m][n-1];
            minPathSum(m,n-1,grid,sum,ans);
            sum -= grid[m][n-1];
        }
        cout << "RETURNING" << endl;
        return;
    }
}


// STRIVER's SOLUTION using Recursion (with Memoization)

int minSumPath(int i, int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(i == 0 && j == 0) return grid[i][j];
    if(i < 0 || j < 0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    int up = grid[i][j] + minSumPath(i-1,j,grid,dp);
    int left = grid[i][j] + minSumPath(i,j-1,grid,dp);
    return dp[i][j] = min(up,left);
}



void input2dArray(vector<vector<int>> &arr){
    int j = arr.size();
    for(int i = 0;i<j;i++){
        cout << "Enter Row " << i+1 << " : ";
        for(int k =0;k<arr[0].size();k++) cin >> arr[i][k];
    }
}

int solution(vector<vector<int>> &grid){

    int m = grid.size();
    int n = grid[0].size();
    

    // ACCORDING TO MY SOLUTION :

    // vector<int> ans;
    // minPathSum(m-1,n-1,grid,grid[m-1][n-1],ans);
    // sort(ans.begin(),ans.end());
    // return ans[0];



    // ACCORDING TO STRIVER's SOLUTION

    vector<vector<int>> dp(m,vector<int>(n,-1));
    return minSumPath(grid.size()-1,grid[0].size()-1,grid,dp);

}


int tabulation(vector<vector<int>> &grid,vector<vector<int>> &dp){
    
    int m = grid.size();
    int n = grid[0].size();
    
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else{
                int up = grid[i][j],left = grid[i][j];
                if(i > 0) up+= dp[i-1][j];
                else up += 1e9;
                if(j > 0) left+= dp[i][j-1];
                else left += 1e9;
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[m-1][n-1];
    
}


int main(){
    int m , n;
    cout << "Enter the Size of GRID as m n : ";
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int>(n));
    cout << "Enter the GRID COST Matrix : " << endl;
    input2dArray(grid);
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout << "Minimum Path Sum from [0][0] to [" << m-1 << "][" << n-1 << "] is : " << tabulation(grid,dp) << endl << endl;
    return 0;
}