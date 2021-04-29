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
#define endl "\n"
void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll prime[11] = {
    0, 3, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};

ll countDigit(long long n)
{
    ll count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

ll power[11];
void power10()
{

    power[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        power[i] = power[i - 1] * 10;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    // ll a = 110033;
    // ll b = 110055;
    power10();

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == b && a == c)
        {
            cout << prime[c] * 3 << " " << prime[c] * 5 << endl;
        }
        else
        {
            ll x = prime[c] * power[a - c] + prime[c] * 3;
            ll y = prime[c] * power[b - c] + prime[c] * 5;
            cout << x << " " << y << endl;
        }
    }

    return 0;
}