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
       ll n;
       cin>>n;
       ll d;
       vector<pair<ll, ll>>ar;
       vector<pair<ll, ll> >s;
        for(ll i=0;i<n;i++){
            cin>>d;
            ar.push_back({i+1, d});
        }
        s.push_back(ar[0]);
        s.push_back(ar[1]);
        ll len = s.size();
        ll ans = 1;
        for(ll i=2;i<n;i++){
            
            while (s.size()>=2)
            {
               double s1 = ((double)s[len-1].second - (double)s[len-2].second)/((double)s[len-1].first - (double)s[len-2].first);
               double s2 = ((double)ar[i].second - (double)s[len-1].second)/((double)ar[i].first - (double)s[len-1].first);

               if(s1<= s2){
                   s.pop_back();
                   len--;
               }
               else
                break;
            }
            s.push_back(ar[i]);
            len++;
            ans = max(ans, s[len-1].first - s[len-2].first);
            

        }
        cout<<ans<<endl;

    }
    return 0;
}