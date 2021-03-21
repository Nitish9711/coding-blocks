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
#define psi pair<string , int>
#define pis pair<int, string>

void ReadCP(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
       ll n;
       cin>>n;
       vl c;
       ll d;
       c.push_back(0);
        for(ll i =1;i<=n;i++){
            cin>>d;
            c.push_back(d);
        }
        ll s0  = c[1], s1 = c[2], mn0= c[1], mn1 = c[2];
        ll ans = (c[1] + c[2])*n;
        for(ll i = 3;i<=n;i++){
            if(i&1){
                s0 += c[i] ;  mn0 = min(c[i], mn0);
            }
            else{
                s1 += c[i]; mn1 = min(c[i], mn1);
            }
            //  cout<<ans<<" "<< s0 + mn0 * (n - (i + 1) / 2) + s1 + mn1 * (n - i / 2)<<endl;

            ans = min(ans, s0 + mn0 * (n - (i+1)/2)  + s1 + mn1*(n - i/2));

        }
        cout<<ans<<endl;

        
    }
    return 0;
}