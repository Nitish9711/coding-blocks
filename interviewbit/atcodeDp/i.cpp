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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    ll n;
    cin>>n;
    vector<double> p(n+1);
    p[0] = 0;
    for(ll i =1;i<=n;i++){
        cin>>p[i];
    }

    vector<vector<double>>dp(n+1, vector<double>(n+1, 0));

    dp[0][0] = 1;
    for(ll i= 1;i<=n;i++)
        dp[0][i] = 0;

    
    for(ll i = 1;i<=n;i++){
        dp[i][0] = dp[i-1][0] * (1.0  - p[i]);     
    }

    for(ll i = 1;i<=n;i++){
        for(ll j =1;j<=n;j++){
            dp[i][j] = dp[i-1][j] * (1.0 - p[i]) + dp[i-1][j-1] * p[i] ;
        }
    }
    // for(ll i =0;i<=n;i++){
    //     for(ll j =0;j<=n;j++){
    //         cout<<dp[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    double ans =0.0;
    ll d = (n/2) + 1;
    for(ll i = d;i<=n;i++){
        ans += dp[n][i];
    }
    cout.precision(10);
    cout<<fixed <<ans<<endl;





    return 0;
}