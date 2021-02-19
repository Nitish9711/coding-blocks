#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int main()
{
    ll n, d;
    cin>>n>>d;

    ll *l = new ll[n];

    for(ll i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l, l+n);
    ll ans = 0;
    int i =0;
    while(i<n){
        if(l[i+1] - l[i] <=d){
            i+=2;
            ans++;
        }
        else{
            i++;
        }
        if(i >= n-1)
            break;
    }
    cout<<ans<<endl;
    return 0;
}