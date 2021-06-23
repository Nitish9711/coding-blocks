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

    ll n, k, x;
    cin >> n >> k >> x;
    vl ar(n);
    for (ll i = 0; i < n; i++)
        cin >> ar[i];

    sort(ar.begin(), ar.end());
    if(n == 1)
    {
        cout<<1<<endl;
        return 0;
    }
    int grp = 1;
    int i = 1;
    while (i < n)
    {
        if (ar[i] - ar[i - 1] <= x)
            i++;
        else
        {
            ll req = 0;
            int j =i-1;
            int temp =ar[j];
            while(temp< ar[i]-x){
                temp = temp+x;
                req++;
                if(temp == ar[i]-x)
                    break;
            }
            if (k >= req)
            {
                cout<<"req "<<i<<" "<<req<<endl;
                i++;
                k = k - req;
                // continue;
            }
            else{
                cout<<i<<endl;
                grp++;
                i++;
            }
        }
    }
    cout<<grp<<endl;

    return 0;
}