#include<bits/stdc++.h>
using namespace std;

// TRIANGLE (CodeStudio // CodingNinjas)    Link --> https://www.codingninjas.com/codestudio/problems/triangle_1229398

void inputTriangleArray(vector<vector<int>> &triangle){
    for(int i =0;i<triangle.size();i++){
        cout << "ENTER ROW " << i+1 << " : ";
        for(int k = 0;k<=i;k++){
            int temp=0;
            cin >> temp;
            triangle[i].push_back(temp);
        }
    }
}

int main(){
    int t;
    cout << "Enter size of Triangle : ";
    cin >> t;
    vector<vector<int>> triangle(t);
    inputTriangleArray(triangle);
    
    return 0;
}