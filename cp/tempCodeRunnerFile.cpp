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
void solve(ll x1, ll x2, ll p1, ll p2)
{


    if (x1 > x2 && p1 < p2)
    {
        // cout<<"a"<<endl;
        while (countDigit(x1) > countDigit(x2) && p2 != 0)
        {
            p2--;
            x2 = x2 * 10;
        }
    }
    else if (x1 < x2 && p1 > p2)
    {
        // cout<<"b"<<endl;

        while (countDigit(x1) < countDigit(x2) && p1 != 0)
        {
            p1--;
            x1 = x1 * 10;
        }
    }

    // cout<<x1<<" "<<p1<<endl;
    // cout<<x2<<" "<<p2<<endl;

    if (p1 == p2 && x1 == x2)
        cout << "=" << endl;

    else if ((x1 > x2 && p1 == p2) || (x1 > x2 && p1 > p2) || (x1 == x2 && p1 > p2))
        cout << ">" << endl;
    else
        cout << "<" << endl;
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