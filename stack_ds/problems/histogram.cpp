#include <iostream>
#include <stack>
using namespace std;
#define ll long int

ll solve(ll hist[], ll n)
{
    stack<ll> s;
    ll ca = 0, ma = 0;
    ll tp;
    ll i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
        {
            s.push(i++);
        }

        else
        {
            tp = s.top();
            s.pop();

            ca = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            ma = max(ma, ca);
        }
    }
    while (!s.empty())
    {
        tp = s.top();
        s.pop();

        ca = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        ma = max(ma, ca);
    }

    return ma;
}

int main()
{
    ll n;
    cin >> n;
    ll *ar = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    cout << solve(ar, n) << endl;

    return 0;
}