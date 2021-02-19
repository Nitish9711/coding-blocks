#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL




int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
    ll arr[100000] = {0};
    //    memset(arr, 0, sizeof arr);
       string name;
       cin>>n;
       ll rank;
      for(ll i =1;i<=n;i++){
          cin>>name>>rank;
          arr[rank]++;
      }

      ll actual_rank = 1;
      ll sum = 0;
      for(ll i = 1;i<=n;i++){
          while(arr[i]){
              sum += abs(actual_rank-i);
              arr[i]--;
              actual_rank++;
          }
      }
      cout<<sum<<endl;


    }
    return 0;
}