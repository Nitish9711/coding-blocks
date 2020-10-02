#include<iostream>

using namespace std;
#define ll long int

ll good_subarray(ll ar[], ll n)
{
	
}

int main()
{

	int t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;
		ll *ar = new ll[n];
		for(ll i=0;i<n;i++)
			cin>>ar[i];
		
		cout<<good_subarray(ar, n)<<endl;
	}
	return 0;
}