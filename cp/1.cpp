#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

void ReadCP(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
        ll r, c,x;
        cin>>r>>c>>x;
        ll d,v;

        vector<vector<ll>>ar;
        vector<vector<ll>>br;
        for(ll i=0;i<r;i++){
            for(ll j = 0;j<c;j++){
                cin>>d;
                ar[i].push_back(d);
            }
        }
        for(ll i=0;i<r;i++){
            for(ll j = 0;j<c;j++){
                cin>>d;
                br[i].push_back(d);
            }
        }
        for(ll i=0;i<r;i++){
            for(ll j =0;j<=c-x;j++){
                if(ar[i][j] == br[i][j])
                    continue;
                ll v = br[i][j] - ar[i][j];
                ll k = j, temp = x;
                while(temp--){
                    ar[i][j] += v;
                }
            }
            for(ll j = c-x+1;j<c;j++){
                ll v = br[i][j] - ar[i][j];
                
                
            }
        }
       
    }
    return 0;
}