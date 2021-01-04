#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

ll solve(string s)
{
    ll ans = 0;

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll fre[27] = {0};
        ll n = s.length();
        if (n <= 2)
        {
            cout << "0" << endl;
        }
        else
        {
            for (ll i = 0; i < n; i++)
            {
                fre[s[i] - 96]++;
            }
            ll ans = 0;
            for (int i = 1; i <= 26; i++)
            {
                if(fre[i]%2 == 0 && fre[i]!=0){
                    n = fre[i] - fre[i]/2; 
                    ans += fre[i]/2;
                }   
                if(fre[i]%3 == 0 && fre[i]!= 0)
                {
                    n = n-fre[i]/3;
                    ans += fre[i]/3;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}