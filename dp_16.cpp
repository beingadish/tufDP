#include<bits/stdc++.h>
using namespace std;

// DP - 16  (CodeStudio // CodingNinjas)    Link --> https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return dp[ind][target] = true;
    if(ind == 0) return dp[ind][target] = arr[ind] == target;
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool nTake = f(ind-1,target,arr,dp);
    bool take = false;
    if(arr[ind] <= target) take = f(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] = nTake || take;
    
}


int solution(vector<int> &arr){
    int n = arr.size();
    int totSum =0;
    for(int i=0;i<n;i++) totSum += arr[i];
    vector<vector<int>> dp(n,vector<int>(totSum+1,-1));
    int mini = 1e9;
    for(int i =0;i<=totSum;i++){
        int diff;
        if( f(n-1,i,arr,dp) ) diff = abs(i- (totSum-i));
        mini = min(diff,mini);
    }
    return mini;
}


int main(){
    int t;
    cout << "Enter test cases : ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter array size : ";
        cin >> n;
        vector<int> a(n);
        cout << solution(a) << endl;
    }
    return 0;
}