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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin>>n>>m;
        ll cnt =0;
        set<pair<ll, ll>>s;
        for(ll i=1;i<=n;i++){
            for(ll j =i+1;j<=n;j++){
                if((m%i)%j == (m%j)%i)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}