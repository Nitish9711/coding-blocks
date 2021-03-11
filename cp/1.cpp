#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

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
        vector<ll>ar;
        ar.push_back(0);
        ll d;
        for(ll i =0;i<n;i++){
            cin>>d;
            ar.push_back(d);
        }


        
    }
    return 0;
}