#include<bits/stdc++.h>
using namespace std;

// Unique Paths II (Maze Obstacles)     (CodeStudio // CodingNinjas)    Link --> https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?leftPanelTab=0

// Using Recursion & Memoization

int uniPathsII(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &deadState){
    
    // Condition For Dead State Check

    if(i >= 0 && j >= 0 && deadState[i][j] == -1) return 0;

    if(i == 0 && j == 0) return 1;
    
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int up = uniPathsII(i-1,j,dp,deadState);
    int left = uniPathsII(i,j-1,dp,deadState);
    return dp[i][j] = up + left;
}

// Tabulation Method

int uniPathsIITAB(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &dS){

    for(int x = 0;x<i;x++){
        for(int y = 0;y<j;y++){
            if(x == 0 && y == 0) dp[x][y] = 1;
            else if(dS[x][y] == -1 ) dp[x][y] = 0;
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

int uniPathsIIOPTI(int i , int j, vector<vector<int>> &dS){
    vector<int> prev(j,0);

    for(int x =0;x<i;x++){
        vector<int> cur(j,0);
        for(int y = 0;y<j;y++){
            if(x == 0 && y == 0) cur[y] = 1;
            else if(dS[x][y] == -1) cur[y] = 0;
            else{
                int up=0,left=0;
                if(x > 0) up = prev[y];
                if(y > 0) left = cur[y-1];
                cur[y] = up + left;
            }
        }
        prev = cur;
    }

    return prev[j-1];
}

void input2dArray(vector<vector<int>> &arr){
    int j = arr.size();
    for(int i = 0;i<j;i++){
        cout << "Enter Row " << i+1 << " : ";
        for(int k =0;k<arr[0].size();k++) cin >> arr[i][k];
    }
}

int main(){
    int m , n;
    cout << "Enter the Size of GRID as m n : ";
    cin >> m >> n;
    vector<vector<int>> deadState(m,vector<int>(n));
    cout << "Enter the Dead State Matrix : " << endl;
    input2dArray(deadState);
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout << "Total number of Unique Path from [0][0] to [" << m-1 << "][" << n-1 << "] without crossing any obstacles are : " << uniPathsIIOPTI(m,n,deadState) << endl << endl; 
    return 0;
}