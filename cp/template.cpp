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
ll j = 0;

        while(k>1){
            for(ll i =j;i<n-1;i++){
                if(ar[i]  < ar[i+1]){
                    p.push_back(i+1);
                    ar[i]++;
                    if(i==0)
                         j ==0;
                    else
                         j = i-1;
                    break;
                }
            }
            k--;
        }
        bool flag = true;
         for(ll i =j;i<n-1;i++){
                if(ar[i]  < ar[i+1]){
                    p.push_back(i+1);
                    flag = false;
                    ar[i]++;
                    break;
                }
            }
        if(flag == true)
            cout<<"-1"<<endl;
        else
            cout<<p[k-1]<<endl;
        

       

    }
    return 0;
}