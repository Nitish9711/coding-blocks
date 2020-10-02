#include<iostream>
#include<algorithm>
using namespace std;
#define ll long int




ll answer(ll n,ll ar[] )
{
    ll ans = 1;
    ll cs = 1;
    ll temp;
    for(ll i=1;i<=n/2;i++)
    {
        temp = ar[i];
        // cout<<temp<<" "<<i<<endl;
        ll p = 2;
        ll j = i*p;
        while(j<=n)
        {
            // cout<<"j"<<j<<ar[j]<<endl;
            if(ar[j] > temp)
            {
                cs++;
                temp = ar[j];
            }
            p++;
            j = j* p;
            // cout<<endl;
        }

      ans = max(ans, cs);
    }

    return ans;
}


int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        ll n, k;
        cin>>n;
        ll *ar = new ll[n+1];
        for(int j =1;j<=n;j++)
            cin>>ar[j];
        cout<<answer(n, ar)<<endl;
    }
    return 0;
}