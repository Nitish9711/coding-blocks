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
void readme()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
I solve2(I a, I b, I c, I d)
{
    if (a * d == b * c)
        return 0;

    I mul1 = a * d;
    I mul2 = b * c;
    if (mul1 != 0 && mul2 % mul1 == 0)
        return 1;
    else if (mul2 != 0 && mul1 % mul2 == 0)
        return 1;
    return 2;
}
I solve3(V(I) ar, I n)
{
    sort(ar.begin(), ar.end());
    I ans = 0;
    ans += ar[n - 1];
    ans += ar[n - 2];
    I ans2 = ar[0] + ar[1];
    return ans - ans2;
}
bool class1;
bool class2;
V(I) dx={1,0,0,-1,1,-1,1,-1}; 
V(I) dy={0,-1,1,0,1,-1,-1,1};  
I solve(V(string) ar, I n, I m)
{
    class1 = false;
    class2 = false;
    I ans = 0;

    I i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (ar[i][j] == '0')
            {
                class1 = true;
                for (I k = 0; k < 8; k++)
                {
                    I x = i + dx[k];
                    I y = j + dy[k];
                    if (x < n && x >= 0 && y >= 0 && y < m && ar[x][y] == '0')
                    {
                        class2 = true;
                    }
                }
            }
            else
                ans+=1;
        }
    }
    if (class2)
        return ans;
    else if (class1)
    {
        return ans - 1;
    }
    return ans - 2;
}

int main()
{
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<I> randGen;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // readme();
    I t;
    cin >> t;
    while (t--)
    {
        I n, m;
        cin >> n >> m;
        V(string)
        ar(n);
        asc(i, 0, n)
            cin >>ar[i];
        cout << solve(ar, n, m) << endl;
    }
    return 0;
}