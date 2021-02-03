#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL




 

int main()
{
	int t;
	cin >> t;
	ll P[11];
    P[0] = 1;
    for(ll i = 1; i <= 10; i++) 
    {
        P[i] = 10*P[i-1];
    }

	while (t--)
	{
	  ll n;
	  cin>>n;
	  if(n<10){
		  cout<<n<<endl;
		  continue;
	  }
	  ll m = n;
	  ll x = n;
	  ll d =0;
	  ll y = 0;
	  while(x > 0)
	  {
		  x = x/10;
		  d++;
	  }

	  for(ll i =0;i<d;i++){
		  y = n/P[i+1];
		  y *= P[i];
		  y += n%P[i];
		m = min(m, y);
	  }
	  cout<<m<<endl;
	  
	}
	return 0;
}