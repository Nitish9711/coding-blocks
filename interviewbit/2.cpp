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
ll countDigit(ll x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans++;
        x = x / 10;
    }
    return ans;
}
void solve(ll xx1, ll xx2, ll pp1, ll pp2)
{

    string a = to_string(xx1);
    string b = to_string(xx2);
    string c = "";
    for(ll i =0;i<pp1;i++){
        c += "0";
    }
    a += c;
    c = "";
    for(ll i=0;i<pp2;i++){
        c += "0";
    }
    b+= c;

    if(a > b)
        cout<<">"<<endl;
    else if(a == b)
        cout<<"="<<endl;
    else if(a < b)
        cout<<"<"<<endl;

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
        ll x1, p1, x2, p2;
        cin >> x1 >> p1;
        cin >> x2 >> p2;
        solve(x1, x2, p1, p2);
    }
    return 0;
}