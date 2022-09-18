#include<bits/stdc++.h>
using namespace std;
#define ulli unsigned long long int

ulli fibRecur(int n, vector<ulli> &dp){
    if(n<2) return dp[n] = n;
    if(dp[n] != -1) return dp[n];
    else return dp[n] = fibRecur(n-1,dp) + fibRecur(n-2,dp);
}

ulli fibTab(int n , vector<ulli> &dp){
    if(n == 0) return dp[0] = 0;
    if(n == 1) return dp[1] = 1;
    if(n >=2) {
        for(int i =2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
}

ulli fibOpti(ulli n){
    ulli curi;
    ulli sprev = 0;
    ulli prev = 1;
    if(n == 0) return sprev;
    if(n == 1) return prev;
    else{
        for(int i =2;i<=n;i++){
            curi = prev + sprev;
            sprev = prev;
            prev = curi;
        }

        return curi;
    }
}

int main(){
    int N;
    cout << "Enter the value of N (tested & found accurate upto 1000000) --> ";
    cin >> N;
    vector<ulli> dp1(N+1,-1),dp2(N,-1);
    // cout << endl << "Using RECURRENCE method : " << endl << endl;
    // cout << "[ ";
    // for(int i =0;i<=N;i++) cout << fibRecur(i,dp1) << " ";
    // cout << "]" << endl;
    // cout << endl << "Using TABULAR method : " << endl << endl;
    // cout << "[ ";
    // for(int i =0;i<=N;i++) cout << fibTab(i,dp2) << " ";
    // cout << "]" << endl;
    cout << endl << "Using OPTIMISED method : " << endl << endl;
    cout << "[ ";
    for(int i =0;i<=N;i++) cout << fibOpti(i) << " ";
    cout << "]" << endl;
    return 0;
}