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
const int N = 1e5 +2;
I a[N], tree[4*N];
void build(I node, I st, I en){
    if(st == en){
        tree[node] = a[st];
        return;
    }
    I mid = (st + en)/2;
    build(2*node, st, mid);
    build (2*node+1, mid+1, en);
    tree[node] = tree[2*node] + tree[2*node + 1];
}
I query(I node , I st, I en, I l, I r){
    if(st > r || en < l)
        return 0;
    if(st >=l && en <=r){
        return tree[node];
    }
    I mid = (st + en)/2;
    I q1 = query(2*node, st, mid, l, r);
    I q2 = query(2*node + 1, mid+1, en, l, r);
    return q1 + q2;
}
void update(I node, I st, I en, I idx, I val){
    if(st == en){
        a[st] == val;
        tree[node] = val;
        return;
    }
    I mid = (st + en)/2;
    if(idx <=mid){
        update(2*node, st, mid, idx, val);
    }
    else{
        update(2*node+1, mid+1, en, idx, val);
    }
    tree[node] = tree[2*node] + tree[2*node+1];
}
int main()
{
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<I> randGen;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    vector<int>ar = {5, 3, 2, 4, 1, 8, 6, 10};
    I n = ar.size();

    for(int i=0;i<n;i++){
        a[i] = ar[i];

    }
    build(1, 0, n-1);
    
    cout<<query(1, 0, n-1, 0, 7)<<endl;
    
    return 0;
}