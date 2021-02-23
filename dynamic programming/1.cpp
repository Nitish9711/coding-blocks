#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL


ll answer(ll n, ll x, ll y, ll z){
    ll dp[n+1] = {0};

    ll i =1;
    dp[1] = 0;

    for(int i =2;i<=n+1;i++){
        if(i%2 == 0){
            dp[i] = min(dp[i/2] + x, dp[i-1] + y);
        }
        else{
            dp[i] = min(dp[i-1] + y, dp[(i+1)/2]+ x + z );
        }

    }
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll n;
       cin>>n;
       ll x, y, z;
       cout<<answer(n, x, y, z)<<endl;
    }
    return 0;
}