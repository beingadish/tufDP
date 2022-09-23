#include<bits/stdc++.h>
using namespace std;

int f(int ind1, int ind2, string s, string t, vector<vector<int>> &dp){
    if(ind1 < 0 || ind2 < 0) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(s[ind1] == t[ind2]) return dp[ind1][ind2] = 1 + f(ind1-1,ind2-1,s,t,dp);
    if(s[ind1] != t[ind2]) return dp[ind1][ind2] = max(f(ind1-1,ind2,s,t,dp),f(ind1,ind2-1,s,t,dp));
    
}

int lcs(string s, string t)
{
    vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
	return f(s.size()-1,t.size()-1,s,t,dp);
}

int main(){
    string str1,str2;
    cout << "Enter String 1 : ";
    cin >> str1;
    cout << "Enter String 2 : ";
    cin >> str2;
    cout << lcs(str1,str2) << endl;
    return 0;
}