#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long int

ll answer(vector<ll> ar, ll n, ll ms)
{
  ll ans = -1;

  if (ar[0] == ms && ar[0] > ar[1])
    return 1;
  if (ar[n - 1] == ms && ar[n - 1] > ar[n - 2])
    return n;

  ll i = 1;
  while (i < n)
  {
    if (ar[i] == ms && ((ar[i] > ar[i - 1]) || (ar[i] > ar[i + 1])))
      return i + 1;
    i++;
  }
  return -1;
}
int main()
{
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;

  while (t--)
  {
    ll n;
    cin >> n;
    ll ms = 0;

    vector<ll> ar(n);
    for (auto &it : ar)
    {
      cin >> it;
      ms = max(ms, it);
    }
    cout << answer(ar, n, ms) << endl;
    // cout<<ms<<endl;
  }
  return 0;
}