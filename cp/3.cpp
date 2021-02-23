#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{   
     vector<vector<int>>output;

    return isWater;
}

int main()
{
    vector<vector<int>> isWater{{0,0,1}, {1,0,0},{0,0,0}};

    vector<vector<int>>output = highestPeak(isWater);

    for(auto it: output){
        for(auto jt : it){
            cout<<jt<<" ";
        }
        cout<<endl;
    }
    // cout<<jt<<endl;

    return 0;
}