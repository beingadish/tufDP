#include<bits/stdc++.h>
using namespace std;

int count(int ind, int target, vector<int> &a, vector<vector<int>> &dp){
    if(ind == 0){
        if(target ==0 && a[0] == 0) return 2;
        if(target == 0 || target == a[0]) return 1;
        else return 0;
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int nTake = count(ind-1,target,a,dp);
    int take=0;
    if(a[ind] <= target) take = count(ind-1,target-a[ind],a,dp);
    
    return dp[ind][target] = take + nTake;
}

int solution(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return count(n-1,tar,num,dp);
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
        int n,tar;
        cout << "Enter array size : ";
        cin >> n;
        cout << "Enter Target : ";
        cin >> tar;
        vector<int> a(n);
        inputArray(a);
        cout << solution(a,tar) << endl;
    }
    return 0;
}