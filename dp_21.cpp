#include<bits/stdc++.h>
using namespace std;

int f(int ind, int sum, vector<int> &a, vector<vector<int>> &dp){
    if(ind == 0){
        if(sum == 0 && a[ind] == 0) return 2;
        if(sum == 0 || sum == a[ind]) return 1;
        return 0;
    }
    
    if(dp[ind][sum] != -1) return dp[ind][sum];
    
    int ntake = f(ind-1,sum,a,dp);
    int take = 0;
    if(a[ind] <= sum) take = f(ind-1,sum-a[ind],a,dp);
    
    return dp[ind][sum] = take + ntake;
};

int targetSum(int n, int target, vector<int>& arr) {
    int totSum =0;
    for(int i =0;i<n;i++) totSum+=arr[i];
    if((totSum-target) < 0) return 0;
    if((totSum-target)%2 == 1) return 0;
    
    int s2 = (totSum-target)/2;
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return f(n-1,s2,arr,dp);
};

void inputArray(vector<int> &a){
    cout << "Enter the Values in Array : ";
    for(int i =0;i<a.size();i++) cin >> a[i];
}


int main(){
     int t;
    cout << "Enter test cases : ";
    cin >> t;
    while(t--){
        int n,tar;
        cout << "Enter array size : ";
        cin >> n;
        cout << "Enter Target : ";
        cin >> tar;
        vector<int> a(n);
        inputArray(a);
        cout << targetSum(n,tar,a) << endl;
    }
    return 0;
}