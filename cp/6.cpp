
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
ll solve(ll l, ll r){
    if(l == r)
        return 0;
    ll start = l, end = r;
    ll ans =0;
    while(start<=end){
        ll mid = (start + end)/2;
        if(mid + mid-1 <=r){
            ans = max(ans, mid-1);
            start = mid;
        }
        else{
            end  = mid;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin>>l, r;

        cout<<solve(l, r)<<endl;
    }
    return 0;
}
