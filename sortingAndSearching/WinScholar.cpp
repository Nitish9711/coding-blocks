#include<iostream>

using namespace std;
#define ll long int
int main()
{
    ll n, m, x, y;
    cin>>n>>m>>x>>y;

    ll min_s = 0;
    ll max_s = n;
    ll ans = 0;

    while (min_s <= max_s)
    {
        ll mid = (min_s + max_s)/2;
        if((mid*x) <= (m + (n-mid)*y))
        {
            ans = mid;
            min_s = mid+1;
        }
        else
        {
            max_s = mid-1;
        }
    }
    cout<<ans;
    
    return 0;
}