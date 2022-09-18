#include<bits/stdc++.h>
using namespace std;

// Maximum Path Sum (CodeStudio // CodingNinjas)    Link --> https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

// Using Recursion & Memoization


int sumMemo(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){

    if(col < 0 || col >= matrix[0].size()) return -1e8;
    if(row == 0) return matrix[0][col];
    if(dp[row][col] != -1) return dp[row][col];
    
    int u = matrix[row][col] + sum(row-1,col,matrix,dp);
    int ld = matrix[row][col] + sum(row-1,col-1,matrix,dp);
    int rd = matrix[row][col] + sum(row-1,col+1,matrix,dp);
    return dp[row][col] = max(u,max(ld,rd));

}

int solution(vector<vector<int>> &matrix){
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
    int maxi = -1e8;
    for(int j =0;j<matrix[0].size();j++) maxi = max(sum(matrix.size()-1,j,matrix,dp),maxi);
    return maxi;
}


void inputMatrix(vector<vector<int>> &matrix){
    cout << "Enter the Elements of Matrix : " << endl;
    for(int i =0;i<matrix.size();i++)
        for(int j =0;j<matrix[0].size();j++)
            cin >> matrix[i][j];
}

int main(){
    int n,m;
    cout << "Enter the size of the matrix : ";
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    inputMatrix(matrix);
    cout << "Maximum Path Sum from 1st Row to Last Row is : " << solution(matrix) << endl;
    return 0;
}