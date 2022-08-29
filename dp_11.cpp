#include<bits/stdc++.h>
using namespace std;

// TRIANGLE (CodeStudio // CodingNinjas)    Link --> https://www.codingninjas.com/codestudio/problems/triangle_1229398


// RECURSION + MEMOIZATION

int rmemo(int i,int j,vector<vector<int>> &tri,vector<vector<int>> &dp){
    int n = tri.size();
    if(i == n-1) return tri[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int down = tri[i][j] + rmemo(i+1,j,tri,dp);
    int adj = tri[i][j] + rmemo(i+1,j+1,tri,dp);
    return dp[i][j] = min(down,adj);
}

// TABULATION

int tab(vector<vector<int>> &tri, vector<vector<int>> &dp){
    int n = tri.size();
    for(int k = 0;k<n;k++) dp[n-1][k] = tri[n-1][k];
    for(int i = n-2 ;i>=0;i--){
        for(int j = i;j>=0;j--){
                int down = tri[i][j] + dp[i+1][j];
                int adj = tri[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,adj);
            }
        }
    
    return dp[0][0];
    }

// SPACE OPTIMISATION

int spaceOpti(vector<vector<int>>& tri){
    vector<int> front(tri.size(),0);
    for(int i =0;i<tri.size();i++) front[i] = tri[tri.size()-1][i];
    for(int i = tri.size()-2 ;i>=0;i--){
        vector<int> cur(tri.size(),0);
        for(int j = i;j>=0;j--){
                int down = tri[i][j] + front[j];
                int adj = tri[i][j] + front[j+1];
                cur[j] = min(down,adj);
            }
        front = cur;
        }
    return front[0];
}


// SOLUTION 

vector<int> sol(vector<vector<int>> &tri){
    vector<int> ans;
    
    
}

void inputTriangleArray(vector<vector<int>> &triangle){
    for(int i =0;i<triangle.size();i++){
        cout << "ENTER ROW " << i+1 << " : ";
        for(int k = 0;k<=i;k++){
            int temp=0;
            cin >> temp;
            triangle[i].push_back(temp);
        }
    }
}

int main(){
    int t;
    cout << "Enter size of Triangle : ";
    cin >> t;
    vector<vector<int>> tri(t);
    inputTriangleArray(tri);
    vector<vector<int>> dp(t,vector<int>(t,-1));
    cout << "SOLUTIONS according to Recursion + Memoization | TABULATION | SPACE OPTIMISED are : ";
    cout << rmemo(0,0,tri,dp) << " ";
    cout << tab(tri,dp) << " ";
    cout << spaceOpti(tri) << endl;
    cout << endl;
    return 0;
}