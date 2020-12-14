#include <iostream>
#include<math.h>
using namespace std;
#define ll long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
      ll n, k;
      cin>>n>>k;

       if(n == k){
           for(ll i =0;i<n;i++)
            cout<<i<<" ";
       }
       else{
           if((n%2 == 0 && k<=n/2) || (n%2!= 0 && k<n/2)){
               for(ll i=1;i<=2*k;i++){
                   if(i%2 == 0){
                       cout<<i<<" ";
                   }
                   else{
                       cout<<-i<<" ";
                   }
               }
               for(ll i = 2*k+1;i<=n;i++)
                cout<<-i<<" ";
           }
           else{

               ll extra = k - n/2;
               ll x = n - extra*2;
               for(ll i =1;i<=x;i++){
                     if(i%2 == 0){
                       cout<<i<<" ";
                   }
                   else{
                       cout<<-i<<" ";
                   }
               }
               for(ll i = x+1;i<=n;i++)
                    cout<<i<<" ";
           }

       }

    cout<<endl;

    }
    return 0;
}