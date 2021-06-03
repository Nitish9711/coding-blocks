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
ll solve(vector<vector<ll>> adj, ll n, ll m)
{
    vector<bool> visited(n + 1, false);
    queue<ll> q;

    // visited[1] = true;
    vector<ll> res;

    for (ll i = 1; i <= n; i++)
    {
        // cout<<i<<endl;
        if (visited[i] == false)
        {
            q.push(i);
            ll cnt = 1;
            visited[i] = true;
            while (!q.empty())
            {
                auto p = q.front();
                q.pop();
                // cout << p << endl;
                for (auto x : adj[p])
                {
                    if (visited[x] == false)
                    {
                        q.push(x);
                        visited[x] = true;
                        cnt++;
                    }
                }
            }
            res.push_back(cnt);
        }
    }
    ll ans = 0;
    for(auto x: res){
        ans += 3 * (1<<(x-1));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    ll n, m;
    cin >> n >> m;
    ll t = m;
    vector<vector<ll>> adj(n + 1);
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // for(ll i=0;i<=n;i++){
    //     cout<<i<<" ->";
    //     for(ll j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout << solve(adj, n, m) << endl;
    return 0;
}