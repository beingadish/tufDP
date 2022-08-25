#include<bits/stdc++.h>
using namespace std;
#define lli long long int

// HouseRobber (CodeStudio // CodingNinjas)     // Same as DP 5     Link --> https://www.codingninjas.com/codestudio/problems/loot-houses_630510

// HouseRobber II   Link --> https://www.codingninjas.com/codestudio/problems/house-robber_839733


void inputArray(vector<int> &a){
    cout << "Enter the Values : ";
    for(int i =0;i<a.size();i++) cin >> a[i];
    cout << endl;
}

int houseRob(vector<int> &nums){
    int prev = nums[0];
    int sprev = 0;

    for(int i =1;i<nums.size();i++){
        int take = nums[i] + sprev;
        int notTake = prev;

        int curi = max(take,notTake);
        sprev = prev;
        prev = curi;
    }

    return prev;

} // Same as the DP 5 (Space Optimised Solution)


int main(){
    lli n;
    cout << "Enter the number of Houses : ";
    cin >> n;
    vector<int> houses(n);
    if(n == 1) cout << "The maximum value that Robber can steal is : " << houses[0] << endl << endl;
    else {
        vector<int> temp1,temp2;
        inputArray(houses);
        for(int i = 0;i<n;i++){
            if(i != n-1) temp1.push_back(houses[i]);
            if(i != 0) temp2.push_back(houses[i]);
    }
        cout << "The maximum value that Robber can steal is : " << max(houseRob(temp1),houseRob(temp2)) << endl << endl;
    }
    
    return 0;
}