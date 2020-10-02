#include<iostream>

using namespace std;
#define ll long int

ll answer(ll n)
{
    ll ans = 0;
   while(n>1)
   {
       if(n%2 == 0)
       {
           ans++;
           n = n/2;
       }
       else if(n%3 == 0)
       {
           ans++;
           n = n - (n/3);
       }
       else
       {
           ans++;
           n = n-1;
       }     
   }

    // ans += n;
   return ans;
}

int main()
{
    ll n;
    cin>>n;

    cout<<answer(n);
    return 0;
}