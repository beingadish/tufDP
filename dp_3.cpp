#include<bits/stdc++.h>
using namespace std;

// FROG JUMP (CodeStudio // CodingNinjas)

int frogJump(int ind, vector<int> &energy){

    if(ind)

    int left = frogJump(ind+1,energy);
    int right = frogJump(ind+2,energy);

    return min(left,right) + abs(energy[ind+1]-)
    
}


void inputArray(int n,vector<int> &arr){
    for(int i =0;i<n;i++) cin >> arr[i];
}

int main(){
    int stairs;
    cout << "Enter the size of the staircase : ";
    cin >> stairs;
    vector<int> energy(stairs);
    inputArray(stairs,energy);
    cout << "Minimum Energy Required : ";
    cout << solution(energy) << endl;
    return 0;
}