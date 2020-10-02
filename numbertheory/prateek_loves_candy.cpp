#include<iostream>

using namespace std;
#define ll long long
#define size 1000002

ll p[size] = {0};
ll ans[size];

void sieve()
{
	  // first mark all odd number's prime
    for(ll i = 3;i<= size;i += 2)
        p[i] = 1;
    
    for(ll i = 3;i<size;i += 2)
    {
        if(p[i] == 1)
        {
            // mark all the multiples of i as not prime
            for(ll j = i*i;j<=size;j = j+i)
                p[j] = 0;
        }  
   }

    p[2] = 1;
    p[1] =0;
    p[0] = 0;

    ll j = 0;
    for(ll i=0;i<size;i++)
    {
        if(p[i])
        {
            ans[j] = i;
            j++;
        }
    }
}

int main()
{

	int t;
	cin>>t;
    sieve();
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<ans[n-1]<<endl;
	}
	return 0;
}