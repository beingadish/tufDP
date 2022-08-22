#include<bits/stdc++.h>
using namespace std;

// Climbing Stairs (CodeStudio // CodingNinjas)

void climbWays(int index, int &stairs, int &ans){
    if(stairs == 0) return;
    if(index >= stairs){
        if(index == stairs) ans+=1;
        return;
    }

    climbWays(index+1,stairs,ans);
    climbWays(index+2,stairs,ans);
};

int solution(int n){
    int ans=0;
    climbWays(0,n,ans);
    return ans;
};

int main(){
    int stairs;
    cout << "Enter the number of Stairs : ";
    cin >> stairs;
    cout << "No. of ways in which one can climb the Stairs using 1 or 2 Jump = " << solution(stairs) << endl;

    return 0;
};