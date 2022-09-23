#include<bits/stdc++.h>
using namespace std;

int f(int ind, int tar, vector<int> &a, vector<vector<int>> &dp){
    if(ind == 0){
        if(tar%a[0] == 0) return dp[ind][tar] = tar/a[0];
        else return 1e9;
    }
    
    if(dp[ind][tar] != -1) return dp[ind][tar];
    
    int ntake = f(ind-1,tar,a,dp);
    int take = 1e9;
    if(a[ind] <= tar) take = 1 + f(ind,tar-a[ind],a,dp);
    
    return dp[ind][tar] = min(take,ntake);
    
}

void inputArray(vector<int> &a){
    cout << "Enter the Values in Array : ";
    for(int i =0;i<a.size();i++) cin >> a[i];
}

int minimumElements(vector<int> &num, int x){
    vector<vector<int>> dp(num.size(),vector<int>(x+1,-1));
    // ANSWER must be given according to the question
    int ans = f(num.size()-1,x,num,dp);
    if(ans >= 1e9) return -1;
    else return ans;
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
            cout << minimumElements(a,tar) << endl;
        }
    return 0;
}