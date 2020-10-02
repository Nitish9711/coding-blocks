#include<iostream>
#include<math.h>
using namespace std;
#define ll long long int
ll root(ll n, ll k)
{
    ll ans = -1;
    
    ll s =0;
    ll e = n;

    while(s<=e)
    {
        ll mid = (s+e)/2;

        if(pow(mid, k) == n)
            return mid;
        if(pow(mid, k) < n)
        {
            ans = mid;
            s = mid+1;
        }
        else 
        {
            e = mid-1;
        }
    }
    return ans;

}
int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        ll n,k;
        cin>>n>>k;
        cout<<root(n,k)<<endl;
    }
    return 0;
}