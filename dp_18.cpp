#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 +7;

int f(int ind, int target, vector<int> &a, vector<vector<int>> &dp){
    if(ind == 0){
        if(target == 0 && a[ind] == 0) return 2;
        if(target == 0 || a[ind] == target) return 1;
        else return 0;
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int ntake = f(ind-1,target,a,dp);
    int take = 0;
    if(a[ind] <= target) take = f(ind-1,target-a[ind],a,dp);
    
    return dp[ind][target] = (take + ntake)%mod;
    
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum =0;
    for(int i =0;i<n;i++) totSum+=arr[i];
    
    // handling base cases if fraction or D is greater than sthe sum
    if(totSum-d < 0) return 0;
    if((totSum-d)%2 == 1) return 0;
    int s2 = (totSum-d)/2;
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return f(n-1,s2, arr, dp);
}

void inputArray(vector<int> &a){
    cout << "Enter the Values in Array : ";
    for(int i =0;i<a.size();i++) cin >> a[i];
}

int main(){
    int t;
    cout << "Enter test cases : ";
    cin >> t;
    while(t--){
        int n,d;
        cout << "Enter array size : ";
        cin >> n;
        cout << "Enter Difference : ";
        cin >> d;
        vector<int> a(n);
        inputArray(a);
        cout << countPartitions(n,d,a) << endl;
    }
    return 0;
}