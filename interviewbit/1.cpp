#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define asc(i, a, n) for (I i = a; i < n; i++)
#define dsc(i, a, n) for (I i = n - 1; i >= a; i--)
#define forw(it, x) for (A it = (x).begin(); it != (x).end(); it++)
#define bacw(it, x) for (A it = (x).rbegin(); it != (x).rend(); it++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)
#define fbo(x) find_by_order(x)
#define ook(x) order_of_key(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (I)((x).size())
#define clr(x) (x).clear()
#define U unsigned
#define I long long int
#define S string
#define C char
#define D long double
#define A auto
#define B bool
#define CM(x) complex<x>
#define V(x) vector<x>
#define P(x, y) pair<x, y>
#define OS(x) set<x>
#define US(x) unordered_set<x>
#define OMS(x) multiset<x>
#define UMS(x) unordered_multiset<x>
#define OM(x, y) map<x, y>
#define UM(x, y) unordered_map<x, y>
#define OMM(x, y) multimap<x, y>
#define UMM(x, y) unordered_multimap<x, y>
#define BS(x) bitset<x>
#define L(x) list<x>
#define Q(x) queue<x>
#define PBS(x) tree<x, null_type, less<I>, rb_tree_tag, tree_order_statistics_node_update>
#define PBM(x, y) tree<x, y, less<I>, rb_tree_tag, tree_order_statistics_node_update>
#define pi (D) acos(-1)
#define md 1000000007
#define rnd randGen(rng)
#define int long long

#define int long long
#define N 100010
using namespace std;
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < 48)
    {
        if (c == '-')
            f = 0;
        c = getchar();
    }
    while (c >= 48)
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return f ? x : -x;
}

int n, m, k;
int a[N];
bool check(int n, int m)
{
    int s = 0;
    for (int i = 1; i <= k; i++)
    {
        int val = a[i] / n;
        if (val < 2)
            return 0;
        s += val;
        if (s >= m && 2 * i <= m)
            return 1;
    }
    return 0;
}


signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
         n = read();
    int cnt =0;
    for(int i=0;i<1000;i++)
        cnt++;
    m = read();
    k = read();
    for (int i = 1; i <= k; i++)
        a[i] = read();
    sort(a + 1, a + k + 1);
    reverse(a + 1, a + k + 1);
    if (check(n, m) || check(m, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    }
    return 0;
}