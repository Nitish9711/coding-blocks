#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}



int knapsack(int n, int s, vector<int>wt, vector<int>p){

   vector<int>dp(s+1, 0);

    for(int i =1;i<=s;i++){
        for(int j =0;j<n;j++){

            if(wt[j]<=i)
                dp[i] = max(dp[i],dp[i-wt[j]] + p[j]);
        }
    }

    return dp[s];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    int n, s;
    cin>>n>>s;

    vector<int>wt;
    vector<int>p;

        int d;
    for(int i=0;i<n;i++){
        cin>>d;
        wt.push_back(d);
    }
    for(int i=0;i<n;i++){
        cin>>d;
        p.push_back(d);
    }
    cout<<knapsack(n, s, wt, p)<<endl;


        
    
    return 0;
}