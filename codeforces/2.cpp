#include <iostream>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll n;
       cin>>n;
       ll *ar = new ll [n];
       ll *b = new ll [n];
       ll sum = 0;

       for(ll i =0;i<n;i++){
           cin>>ar[i];
           sum+= ar[i];
       }
    
        ll i = 0;
        while(i<n){
            if(ar[i]%ar[i+1] ==  || ar[i+1]%ar[i] == 0){
                i = i + 2;
                
            }
            else{
                
            }



        }
        for(ll i =0;i<n;i++){
            cout<<ar[i]<<" ";
        }
       

      
       cout<<endl;
    }
    return 0;
}