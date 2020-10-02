#include<iostream>

using namespace std;
#define ll  int



int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        int ar[1005];

        ll e = 0;
        ll o =0;
 
        for(ll i=0;i<n;i++)
        { 
            cin>>ar[i];
            if(ar[i]%2 == 0)
                {
                    // cout<<"e"<<" "<<ar[i]<<endl;
                     e++;
                }
            else
            {
                // cout<<"o"<<" "<<ar[i]<<endl;
                o++;
            }
            
           
        }
        // cout<<e<<" "<<o<<endl;
        cout<<e*o<<endl;
    }    
    return 0;
}