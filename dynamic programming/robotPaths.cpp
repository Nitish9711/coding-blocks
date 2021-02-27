#include <bits/stdc++.h>
using namespace std;
#define ll int
#define null NULL
#define MOD 1000000007

ll dp[1001][1001];

ll solve(ll m, ll n)
{
    if (dp[0][0] == -1)
        return 0;

    for (int j = 0; j < n; j++)
    {
        if (dp[0][j] != -1)
        {
            dp[0][j] = 1;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (dp[i][0] != -1)
        {
            dp[i][0] = 1;
        }
        if (dp[i][0] == -1)
            break;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {

            if (dp[i][j] != -1)
            {
                dp[i][j] = 0;
                if (dp[i][j - 1] != -1)
                {
                    dp[i][j] = dp[i][j - 1] % MOD;
                }
                if (dp[i - 1][j] != -1)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                }
            }
        }
    }
    if (dp[m - 1][n - 1] == -1)
    {
        return 0;
    }

    return dp[m - 1][n - 1];
}
int main()
{
    // memset(dp,0,sizeof dp);
    ll n, m, p;
    cin >> m >> n >> p;
    // vector<pair<ll, ll>>grid;
    ll x, y;
    for (int i = 0; i < p; i++)
    {
        cin >> x >> y;
        dp[x - 1][y - 1] = -1;
    }

    cout << solve(m, n) << endl;
    // cout << numWays(m, n) << endl;
    //  for(int i =1;i<=m;i++){
    //     for(int j =1;j<=n;j++)
    //         cout<<dp[i][j]<<" ";

    //     cout<<endl;
    // }

    return 0;
}