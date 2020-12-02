#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define ll long int

ll abc(ll a, ll b)
{
  if (a >= b)
  {
    return (a - b);
  }
  return (b - a);
}

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {

    ll n, k, count = 0, left = 1, right = 1;
    cin >> n >> k;
    ll i, j;

    char str[n + 1];
    while (right <= n)
    {
      cin >> str[right];

      queue<int> ma;
      queue<int> ir;

      if (str[right] == 'M')
        ma.push(right);

      if (str[right] == 'I')
        ir.push(right);

      if (str[right] == 'X')
      {
        while (!ir.empty() && !ma.empty())
        {
          i = ir.front();
          j = ma.front();

          ll sheet = 0;
          if (i < j)
          {
            for (ll x = i; x <= j; x++)
            {
              if (str[x] == ':')
                sheet++;
            }
          }
          else
          {
            for (ll x = j; x <= i; x++)
            {
              if (str[x] == ':')
                sheet++;
            }
          }
          ll p = k + 1 - abc(j, i) - sheet;
          if (p > 0)
          {
            count++;
            ir.pop();
            ma.pop();
          }
          else
          {
            if (i > j)
            {
              ma.pop();
            }
            else
            {
              ir.pop();
            }
          }
        }
      }
    }

    right++;
    cout << count << endl;
  }

  return 0;
}
