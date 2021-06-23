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
#define mod 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    ll r, c;
    cin>>r>>c;
    vector<string>ar(r);
    for(auto &x:ar){
        cin>>x;
    }
    vector<vector<ll>>dp(r, vector<ll>(c));
   

   for(ll i=0;i<r;i++){
       if(ar[i][0] == '.')
            dp[i][0]  = 1;
        else
            break; 
   }
   for(ll i = 0;i<c;i++){
       if(ar[0][i] == '.')
        dp[0][i] = 1;
        else
            break;
   }
   for(ll i=1;i<r;i++){
       for(ll j= 1;j<c;j++){
           if(ar[i][j] == '.'){
               if(ar[i-1][j] == '.')
                dp[i][j] += dp[i-1][j];

                dp[i][j] %=mod;

                if(ar[i][j-1] == '.')
                    dp[i][j] += dp[i][j-1];

                dp[i][j] %=mod;
           }
       }
   }
   
    // for(ll i =0;i<=r;i++){
    //     for(ll j =0;j<=c;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }


    // dp[r][c] = dp[r][c] %mod;
    dp[r-1][c-1] %= mod;
    cout<<dp[r-1][c-1]<<endl;
    return 0;
}