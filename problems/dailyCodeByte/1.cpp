#include<iostream>

using namespace std;
#define ll  long int



int main()
{
   
        ll n;
        cin>>n;
        ll *ar= new ll[n];

        ll sum = 0;
        for(ll i=0;i<n;i++)
        { 
            cin>>ar[i];
            sum+= ar[i];
        }
        

        ll req = ((n+1)*(n+2))/2;

        cout<<req-sum<<endl;
        
        // out<<sum<<endl;
        // cout<<req<<endl;c


           
       
    return 0;
}