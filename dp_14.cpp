#include<bits/stdc++.h>
using namespace std;

// Subset Sum Equal to K  (CodeStudio // CodingNinjas)  Link --> https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

bool f(int ind, int target, vector<int> &a, vector<vector<int>> &dp){

    if(target == 0) return true;
    if(ind == 0) return a[ind] == target;
    if(dp[ind][target] != -1) return dp[ind][target];

    bool nTake = f(ind-1,target,a,dp);
    bool take = false;
    if(target >= a[ind]) take = f(ind-1,target-a[ind],a,dp);
    
    return (take || nTake);
}

void inputArray(vector<int> &a){
    cout << "Enter the Values in Array : ";
    for(int i =0;i<a.size();i++) cin >> a[i];
}

int main(){

    int test;

    cout << "Enter number of test cases : ";
    cin >> test;

    while(test--){

    int n,tar;
    cout << "Enter the number of elements in Array & Target : ";
    cin >> n >> tar;

    vector<int> v(n);
    inputArray(v);

    vector<vector<int>> dp(n,vector<int>(tar+1,-1));

    if(f(n-1,tar,v,dp)) cout << "Yes, there exist a Subsequence with the target value = " << tar << endl;
    else cout << "No, there is no subsequence with target value = " << tar << endl;

    }
    
    return 0;
}