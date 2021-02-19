#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL
bool arraySortedOrNot(vector<ll> arr, ll n)
{
    
    if (n == 0 || n == 1)
        return true;
 
    for (ll i = 1; i < n; i++)
        if (arr[i - 1] < arr[i])
            return false;
 
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll n,k;
       cin>>n>>k;
       vector<ll>ar;
       vector<ll>p;
       ll d;
       for(ll i =0;i<n;i++){
           cin>>d;
           ar.push_back(d);
       }
       if(arraySortedOrNot(ar, n)){
            cout<<"-1"<<endl;
            continue;

       }

        ll ans = 0;
        bool flag = true;
        ll i =0;
        while (i<n-1 )
        {
            if(ar[i] < ar[i+1]){
                ll d = ar[i+1] - ar[i];
                if( d >= k){
                    k = 0;
                    ans = i+1;
                    flag = false;
                    break;
                }
                else{
                  k = k-d;
                }

                ar[i] += d;
                if(i!= 0)
                    i--;
                else{
                    i=0;
                }
                if(k == 0){
                   ans = i+1;
                    break;
                }
            }      
            else{
                i++;
            }
        }

       
       
        if(flag == true)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
        

       

    }
    return 0;
}