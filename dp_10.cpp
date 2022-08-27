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
    vector<int> ans;
    minPathSum(m-1,n-1,grid,grid[m-1][n-1],ans);
    sort(ans.begin(),ans.end());
    return ans[0];
}


int main(){
    int m , n;
    cout << "Enter the Size of GRID as m n : ";
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int>(n));
    cout << "Enter the GRID COST Matrix : " << endl;
    input2dArray(grid);
    // vector<vector<int>> dp(m,vector<int>(n,-1));
    cout << "Minimum Path Sum from [0][0] to [" << m-1 << "][" << n-1 << "] is : " << solution(grid) << endl << endl;
    return 0;
}