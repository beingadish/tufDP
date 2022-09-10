#include<bits/stdc++.h>
using namespace std;

#define ulli unsigned long long int

// Climbing Stairs      (CodeStudio // CodingNinjas)     Link  --> https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650

void climbWays(ulli index, ulli &stairs, ulli &ans){
    if(stairs == 0) return;
    if(index >= stairs){
        if(index == stairs) ans+=1;
        return;
    }

    climbWays(index+1,stairs,ans);
    climbWays(index+2,stairs,ans);
};

ulli solution(ulli n){
    // ulli ans=0;
    // climbWays(0,n,ans);
    // return ans;

    ulli mod= 1000000007;
   ulli prev2 = 1;
   ulli prev = 1;
 
 for(ulli i=2; i<=n; i++){
     ulli cur_i = (prev2%mod+ prev%mod)%mod;
     prev2 = prev%mod;
     prev= cur_i%mod;
 }
 return prev%mod;
};

int main(){
    ulli t;
    cin >> t;
    while(t--){
        ulli stairs;
        cout << "Enter the number of Stairs : ";
        cin >> stairs;
        cout << "No. of ways in which one can climb the Stairs using 1 or 2 Jump = " << solution(stairs) << endl;
    }
    return 0;
};