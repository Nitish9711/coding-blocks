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


// minimum size of tree 4n (approx)
void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vl tree(400005);
vl ar(100005);
void buildTree(ll si , ll ss  , ll se){
    if(ss == se){
        tree[si] = ar[ss];
        return;
    }
    ll mid = (ss + se)/2;
    buildTree(2*si, ss, mid);
    buildTree(2*si+1, mid+1, se);
    tree[si] = min(tree[2*si], tree[2*si+1]);
}

int answer(ll si, ll ss, ll se, ll qs, ll qe){
    // completley outside
    if(qs > se || qe < ss)
        return INT_MAX;
    
    // completly inside curent node
    if(ss >= qs &&  se <= qe)
        return tree[si];
    
    int mid = (ss + se)/2;
    //partially
    return min(answer(2*si, ss, mid,qs, qe) , answer(2*si + 1, mid+1, se, qs , qe));    
}
void update(int si, int ss, int se, int qi){
    if(ss == se)
    {
        tree[si] = ar[ss];
        return;
    }


    int mid = (ss + se)/2;
    // left side
    if(qi <=mid)
        update(2*si, ss, mid, qi);
    else  // right side
        update(2*si + 1, mid+1, se, qi);    
    tree[si] = min(tree[2*si], tree[2*si+1]);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ReadCP();
    ll n;
    cin>>n;
    // ar.clear();
    for(ll i=1;i<=n;i++){
        cin>>ar[i];
    }

    buildTree(1, 1, n);
    ll q;
    ll x; ll y;
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<answer(1, 1, n, x+1, y+1)<<endl;
    }
    
    return 0;
}