#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

    ll dp[1000][1000];
    ll ar[1000];


ll sum(ll s, ll e){
    ll ans = 0;
    for(ll i = s;i<=e;i++){
        ans += ar[i];
        ans %= 100;
    }
    return ans;
}
ll solve(ll i, ll j){

    if(i>=j){
        return 0;
    }

    if(dp[i][j]!= -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k = i;k<=j;k++){
        dp[i][j] = min(dp[i][j], solve(i, k)+ solve(k+1,j) + sum(i, k)*sum(k+1, j));
    }


    return dp[i][j];
}
int main()
{
    
       ll n;
       while(cin>>n)
       {
        for(int i =0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j] = -1;
        }
    }
    //    vector<ll>ar;
       for(int i=0;i<n;i++){
           cin>>ar[i];
       }
       cout<<solve(0, n-1)<<endl;
    }
    return 0;
}