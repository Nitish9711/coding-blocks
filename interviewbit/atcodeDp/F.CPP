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
string solve(string s, string t){
    ll n = s.length();
    ll m = t.length();

    vector<vector<ll>>dp(n+1, vector<ll>(m+1));
    for(int i=0;i<=m;i++)
        dp[0][i] = 0;
    for(int i =0;i<=n;i++)
        dp[i][0] = 0;

    // cout<<s<<endl;
    for(ll i =1;i<=n;i++){
        for(ll j =1;j<=m;j++){
            if(s[i-1] == t[j-1])
                dp[i][j]  = (ll)1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    string ans;
    ll i = n;
    ll j = m;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1])
            ans += s[i-1], i--, j--;
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    string s, t;
    cin>>s>>t;
    cout<<solve(s, t)<<endl;
    return 0;
}