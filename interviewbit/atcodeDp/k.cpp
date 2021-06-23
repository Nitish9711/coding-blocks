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
    ll dp[3000][3000][2];
    vl ar(n);
    ll sum =0;
    for(ll i=0;i<n;i++){
        cin>>ar[i];
        sum += ar[i];
    }
    
    for(ll i =0;i<n;i++){
        dp[i][i][0] = ar[i];
        dp[i][i][1]  = i;
    }

    for(ll RminusL = 1;RminusL<n;RminusL++){
        for(ll L = 0;L + RminusL < n;L++){
            ll R = L + RminusL;
            dp[L][R][0] = max(ar[L] + dp[L+1][R][1],
                                ar[R] + dp[L][R-1][1]);

            dp[L][R][1] = min(dp[L+1][R][0], dp[L][R-1][0]);
        }
    }
    
    ll ans = 2*dp[0][n-1][0] - sum;
    cout<<ans<<endl;

    return 0;
}