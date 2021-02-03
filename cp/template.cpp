#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

bool isLucky(ll n, ll d){
    while(n> 0){
        ll temp = n%10;
        if(temp ==d )
            return true;
        n = n/10;
    }
    return false;
}

bool solve(ll n, ll d){
    if(isLucky(n, d) || n%d == 0){
        return true;
    }


}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll q, d;
       cin>>q>>d;
       ll n;
       for(ll i =0;i<q;i++){
           cin>>n;
           if(solve(n, d)){
               cout<<"YES"<<endl;
           }
           else
            cout<<"NO"<<endl;
       }
    }
    return 0;
}