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

// I a[100000] = {0};
void update(I i, I val,I bit[], I N)
{
    while (i <= N)
    {
        bit[i] += val;
        i += (i & (-i));
    }
}
I query(I bit[], I i)
{
    I ans = 0;
    while (i > 0)
    {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}
int main()
{
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<I> randGen;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    I t;
    cin >> t;
    while (t--)
    {
        I n, u;
        cin >> n >> u;
        I bit[n+10] = {0};
        while (u--)
        {
            I a, b, x;
            cin >> a >> b >> x;
            a++;
            b++;
            update(a, x, bit, n);
            update(b+1, -x,bit, n);
            
        }

        I q;
        cin>>q;
        while(q--){
            I idx;
            cin>>idx;
            idx++;
            cout<<query(bit, idx)<<endl;
        }
    }
    return 0;
}