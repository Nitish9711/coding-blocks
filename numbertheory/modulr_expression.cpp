#include<iostream>

using namespace std;
#define ll unsigned long long

ll answer(ll a, ll b, ll c)
{
	ll ans = 1;

    a = a % c;
   
    if(a == 0)
        return 0;

    
    while(b > 0)
    {
        int last_bit = b&1;

        if(last_bit)
            ans = (ans*a)%c;
        
        a = (a*a)%c;
        b= b>>1;
    }
    
 
    return ans;
}

int main()
{
    ll a, b, c;
    cin>>a>>b>>c;
    
    
    cout<<answer(a, b, c)<<endl;
	
	return 0;
}