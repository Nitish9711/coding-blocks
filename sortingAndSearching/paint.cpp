#include<iostream>
#include<algorithm>
using namespace std;
#define ll unsigned long long
#define mod 10000003
bool valid(ll ar[], ll n, ll k, ll t, ll mid)
{   
    ll painter_used = 1;
    ll board_painted = 0;
    for(ll i=0;i<n;i++)
    {
        if(board_painted + ar[i] > mid)
        {
            painter_used++;
            board_painted = ar[i];
            if(painter_used > k)
                return false;
            
        }
        else
        {
            board_painted += ar[i];
        }
    }
    return true;
}

int main()
{
    ll n, k, t;
    cin>>n>>k>>t;

    ll * ar = new ll[n];
 
    ll tm = 1;
    ll sum = 0;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        ar[i] = temp*t;
        sum += ar[i];
        tm = max(temp, tm);
    }

    ll min_t = tm*t;
    ll max_t = sum;
    ll ans = 0;
    while(min_t<= max_t)
    {
        ll mid = (max_t+min_t)/2;

        // cout<<mid<<endl;
        if(valid(ar, n, k, t, mid))
        {
            ans = mid;
            max_t = mid-1;
        }
        else
        {
            min_t = mid + 1;
        }
        
    }
    cout<<ans%mod<<endl;
    return 0;
}