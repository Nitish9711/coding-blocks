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

ll dp[100010];
ll topDown( vl ar, ll i, ll n){
    if(i < 0)
        return INT_MAX;


    if(dp[i] != INT_MAX)
        return dp[i];

    // dp[i] = min(abs(ar[i] - ar[i-1]) + topDown(dp, ar, i-1, n) ,abs(ar[i] - ar[i-2])+ topDown(dp, ar, i-2, n));
    ll op1 = i>=1 ? abs(ar[i]- ar[i-1]) + topDown( ar, i-1, n)  : INT_MAX;
    ll op2 = i>=2 ? abs(ar[i] - ar[i-2]) + topDown( ar, i-2, n) : INT_MAX;
    dp[i] = min(op1, op2);
    
    // cout<<i<<" "<<dp[i]<<" "<<op1<<" "<<op2<<endl;
    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ReadCP();
    ll n;
    cin >> n;
    vl ar(n);
    for (ll i = 0; i < n; i++)
        cin >> ar[i];

  


  

        fill(dp, dp + n, INT_MAX);

    dp[0] = 0;

    cout<<topDown(ar, n-1, n-1);
    return 0;
}