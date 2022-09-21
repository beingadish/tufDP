#include<bits/stdc++.h>
using namespace std;

void inputArray(vector<int> &a){
    cout << "Enter the Values in Array : ";
    for(int i =0;i<a.size();i++) cin >> a[i];
}

bool f(int ind, int target, vector<int> &a, vector<vector<int>> &dp){
    if(target == 0) return true;
    
    if(ind == 0) return a[ind] == target; // True or False
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool notTake = f(ind-1,target,a,dp);
    bool take = false;
    if(a[ind] <= target) take = f(ind-1,target-a[ind],a,dp);
    
    return dp[ind][target] = (take || notTake);
}

int main(){

    int test;

    cout << "Enter number of test cases : ";
    cin >> test;

    while(test--){

        int n,sum=0;
        cout << "Enter the number of elements in Array : ";
        cin >> n;

        vector<int> arr(n);
        inputArray(arr);

        for(int i =0;i<arr.size();i++) sum+=arr[i];

        if(sum%2 != 0) cout << "False" << endl;

        else{
            vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
            if(f(n-1,sum/2,arr,dp)) cout << "True" << endl;
            else cout << "False" << endl;
        }
    }

    return 0;
}