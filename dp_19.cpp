#include<bits/stdc++.h>
using namespace std;

int ks(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if(ind == 0){
        if(wt[ind] <= w) return val[ind];
        return 0;
    }
    
    if(dp[ind][w] != -1) return dp[ind][w];
    
    int ntake = 0 + ks(ind-1,w,wt,val,dp);
    
    // 0 because no value had been taken into the bag
    
    int take = INT_MIN;
    if(wt[ind] <= w) take = val[ind] + ks(ind-1,w-wt[ind],wt,val,dp);
    
    return dp[ind][w] = max(take,ntake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return ks(n-1,maxWeight,weight,value,dp);
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
        int n,mxwt;
        cout << "Enter array size : ";
        cin >> n;
        vector<int> wt(n),val(n);
        cout << "Enter the Weight Array : " << endl;
        inputArray(wt);
        cout << "Enter the Value Array : " << endl;
        inputArray(val);
        cout << "Enter Max Weight : ";
        cin >> mxwt;
        cout << knapsack(wt,val,n,mxwt) << endl;
    }
    return 0;
}