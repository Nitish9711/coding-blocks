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
vl tree(400005);
vl ar(100005);
vl lazy(100005);

void buildTree(ll si , ll ss , ll se){
    if(ss == se)
    {
        tree [si] = ar[ss];
        return;
    }   

    int mid = (ss + se)/2;
    buildTree(2*si, ss, mid);
    buildTree(2*si + 1, mid+1, se);
    tree[si] = tree[2*si] + tree[2*si+1];
}
ll query(ll si, ll ss, ll se, ll qs, ll qe){
    if(lazy[si]!= 0){
        ll dx = lazy[si];
        lazy[si] =0;
        tree[si] += dx * (se- ss + 1);
        if(ss != se)
            lazy[2*si] += dx, lazy[2*si+1] = dx;


    }
    if(ss > qe  || se < qs)
        return 0;
    if(ss >= qs && se <= qe){
        return tree[si];
    }
    int mid = (ss + se)/2;
    return query(2*si, ss, mid, qs, qe) + query(2*si + 1, mid+1, se, qs , qe); 
}

void update(ll si, ll ss, ll se, ll qs, ll qe, ll val){
    
     if(lazy[si]!= 0){
        ll dx = lazy[si];
        lazy[si] =0;
        tree[si] += dx * (se- ss + 1);
        if(ss != se)
            lazy[2*si] += dx, lazy[2*si+1] = dx;
    }

      if(ss > qe  || se < qs)
        return;
    if(ss >= qs && se <= qe){
    {
        ll dx = (se-ss + 1) * val;
        tree[si] += dx;
        if(ss!= se)
            lazy[2*si] += val, lazy[2*si+1] = val;
        return;
    }
    int mid = (ss + se)/2;
    update(2*si, ss, mid, qs, qe, val);
    update(2*si+1, mid+1, se, qs, qe, val);
    tree[si] += tree[2*si] + tree[2*si+1];


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}