#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

bool cmpr(pair<int,int> l,pair<int,int> r){
return l.first > r.first;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll n;
       cin>>n;
       int flag = 0;
       ll ans = 0;
       vector<pair<ll, ll>>v;
       priority_queue<ll>pq;
       int d, f;
       for(ll i =0;i<n;i++){
           cin>>d>>f;
           v.push_back(make_pair(d, f));
       }
        sort(v.begin(), v.end(), cmpr);
        ll D, F;
        cin>>D>>F;

        for(ll i =0;i<n;i++){
            v[i].first = D - v[i].first;
        }

        ll prev = 0;
        ll x =0;
        while(x<n){
            if(F >= v[x].first - prev){
                F= F - (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }   

            else{
            
                if(pq.empty()){
                    flag = 1;
                    break;
                }

                F += pq.top();
                pq.pop();
                ans++;
                continue;
            }
            x++;

        }
        if(flag == 1){
            cout<<"-1"<<endl;
        }
        else{
            D = D - v[n-1].first;
            if(F >= D){
                cout<<ans<<endl;
                continue;
            }
            while(F<D){
                if(pq.empty()){
                    flag = 1;
                    break;
                }
                F += pq.top();
                pq.pop();
                ans++;
            }
            if(flag == 1){
                cout<<"-1"<<endl;
                continue;
            }
            cout<<ans<<endl;

        }       

    }
    return 0;
}