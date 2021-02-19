#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int main()
{
    int t;
    cin >> t;

      ll x[40010] , y[40010];
    while (t--)
    {
       ll w, h, n;
       cin>>w>>h>>n;

      
       for(int i =0;i<n;i++){
           cin>>x[i]>>y[i];
       }
       sort(x, x+n);
       sort(y, y+n);

       ll dx = x[0]-1;
       ll dy = y[0]-1;

       for(int i =1;i<n;i++){
           dx = max(dx, (x[i]- x[i-1]-1));
           dy = max(dy, (y[i]- y[i-1]-1));

       }
       dx = max(dx, w-x[n-1]);
       dy = max(dy, h-y[n-1]);

       cout<<dx*dy<<endl;




    }
    return 0;
}