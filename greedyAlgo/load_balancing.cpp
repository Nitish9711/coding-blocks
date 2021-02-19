#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int main()
{
   while(1){
       ll n;
       cin>>n;
        if(n == -1){
            break;
        }
        ll total = 0;
        ll *ar = new ll[n];
        memset(ar, 0, sizeof(ar));
        ll d;
        cin>>ar[0];
        total = ar[0];
        for(ll i=1;i<n;i++){
            cin>>d;
            ar[i] = ar[i-1] + d;
            total += d;
        }
        if(total%n !=0){
            cout<<"-1"<<endl;
            break;
        }

        ll req = total/n;
        ll temp = INT_MIN;
        for(ll i =0;i<n;i++){

            temp = max(temp, abs(ar[i]- (req*(i+1))));
        }
        cout<<temp<<endl;


   }
    return 0;
}