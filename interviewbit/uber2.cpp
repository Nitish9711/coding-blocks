#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second
#define endl "\n"
#define int long long

int const max1 = 2e5 + 5;
int const mod = 1e9 + 7;

int find_set(int a, vector<int> &parent)
{
    while (a != parent[a])
    {
        a = parent[a];
    }
    return a;
}

void union_set(int a, int b, vector<int> &parent, vector<int> &ran)
{
    int s1 = find_set(a, parent);
    int s2 = find_set(b, parent);
    if (s1 == s2)
        return;
    else
    {

        if (ran[s1] < ran[s2])
        {
            parent[s1] = s2;
            ran[s2] += ran[s1];
        }

        else
        {
            parent[s2] = s1;
            ran[s1] += ran[s2];
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> v;
    int a, b, w;
    for (int i = 0; i < m; i++)
    {

        cin >> a >> b >> w;
        v.pb({w, {a, b}});
    }

    vector<int> parent(n + 1);
    vector<int> ran(n + 1);
    int ans = 0;
    int k = 1;
    while (k <= 1e9)
    {
        k = k << 1;
    }
    unordered_set<int> fixed, curr;
    while (k > 0)
    {
        for (int i = 0; i < m; i++)
        {
            if (fixed.find(v[i].first) == fixed.end())
            {
                if (v[i].first & k)
                {
                    curr.insert(v[i].first);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            ran[i] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            int x = v[i].F;
            int a = v[i].S.F;
            int b = v[i].S.S;
            if (fixed.find(x) == fixed.end() && curr.find(x) == curr.end())
            {
                int s1 = find_set(a, parent);
                int s2 = find_set(b, parent);

                if (!(s1 == s2))
                {
                    union_set(a, b, parent, ran);
                }
            }
        }
        int p = find_set(1, parent);
        int f = 1;
        for (int i = 2; i <= n; i++)
        {
            if (p != find_set(i, parent))
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            for (auto x : curr)
            {
                fixed.insert(x);
            }
        }
        else
        {
            ans = ans | k;
        }
        curr.clear();
        k = k >> 1;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}