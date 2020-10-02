#include<iostream>

using namespace std;
#define ll long int

void answer(ll ar[], ll low, ll high, ll n)
{
    ll l = 0;
    ll r = n-1;
    ll i = 0;

    for (int i=0; i<=r;) 
    {
        if(ar[i] < low)
        {
            swap(ar[i], ar[l]);
            i++;
            l++;
        }
        else if(ar[i] > high)
        {
            
            swap(ar[i], ar[r]);
            r--;
        }
        else
        {
             i++;
        }
      
    }

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll *ar= new ll[n];

        for(ll i=0;i<n;i++)
            cin>>ar[i];
        
        ll low, high;
        cin>>low>>high;

        answer(ar, low, high, n);

        for(int i=0;i<n;i++)
            cout<<ar[i]<<" ";

    }
    return 0;
}