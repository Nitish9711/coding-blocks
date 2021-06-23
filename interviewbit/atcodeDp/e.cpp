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

#define inf 1e13
ll knapsack(ll n, ll W, vl wt, vl val){
    ll max_val = 0;
    for(ll i =1;i<=n;i++)
        max_val += val[i];
    
    vector<ll>dp(max_val + 1, inf);
    dp[0] = 0;
    for(ll item = 1;item<=n;item++){
        ll w = wt[item];
        ll v = val[item];

        for(ll j = max_val; j>=v;j-- ){
            dp[j] = min(dp[j], dp[j-v] + w);
        }
    }

    for(ll i = max_val;i>=0;i--){
        if(dp[i] <=W)
        {
           return i;
            break;
        }
    }

    return 0;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    ll n, w;
    cin>>n>>w;
    vl wt(n+1), val(n+1);
    wt[0]=0;
     val[0] = 0;
    for(ll i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<knapsack(n, w,wt,val);

    return 0;
}