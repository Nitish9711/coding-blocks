#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL
#define mod 1000000007


ll solve(ll ar[], ll n){
    ll ans = 0;
    unordered_set<ll> s;
    ll j = 0;ans =0;

    for(ll i =0;i<n;i++){

        while(j<n && s.find(ar[j]) == s.end()){
            s.insert(ar[j]);
            j++;
        }

        ans += (j-i)*(j-i+1)/2;
        // ans = ans % mod;
        s.erase(ar[i]);
    }

    return ans;
}
int main()
{
    ll n;
    cin>>n;
    ll *ar = new ll[n];
    for(ll i =0;i<n;i++){
        cin>>ar[i];
    }

    cout<<solve(ar, n)<<endl;
    return 0;
}