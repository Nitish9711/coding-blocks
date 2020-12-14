#include <iostream>
#include <math.h>
#include<vector>
using namespace std;
#define ll long long int

ll set_bits(ll n)
{
    ll k = (ll)(log2(n));
    ll ans = (ll)(pow(2, k));
    return ans;
}

int main()
{
    int t, k = 30;
    cin >> t;
    
    while (t--)
    {
        bool flag = false;
        ll n, x;
        cin >> n >> x;
        ll *ar = new ll[n];
        vector<vector<ll>> index(k+1);
        for (ll i = 0; i <n; i++)
        {
            cin >> ar[i];
            for(ll j = k; j>=0;j--){
                if(ar[i] & (1LL<<j)){
                    index[j].push_back(i);
                }
            }
        }
       vector<ll>count(k+1, 0);
       for(ll i = 0;i<n-1;i++){

           if(x == 0){
               break;
           }

           for(ll j = k;j>=0;j--){
               if(x==0){
                   break;
               }
               ll mask = 1LL<<j;
               if((ar[i]&mask) == 0){
                    continue;
               }
               flag = true;
    
                x--;
                ar[i] = ar[i]^mask;
                count[j]++;
                ll d;
                if(count[j]  < index[j].size()){

                    d = index[j][count[j]];
                    count[j]++;

                } 
                else{
                    d = n-1;
                    index[j].push_back(n-1);
                }
                ar[d] = ar[d] ^ mask;
                
           }
       }
     if(n<3){
         flag =false;
     }

        if(x%2 == 1 && flag == false){
            ar[n-2] = 1 ^ ar[n-2];
            ar[n-1] = 1 ^ ar[n-1];
        }

        for(ll i=0;i<n;i++){
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}