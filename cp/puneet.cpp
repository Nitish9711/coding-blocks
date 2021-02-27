#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL
bool compare(pair<ll,ll>a, pair<ll, ll>b){
    if(a.second > b.second)
        return true;
    
    
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll n;
       cin>>n;
    //    ll *ar = new ll[n];
       vector<pair<ll, ll>>ar;
       ll d;

       for(ll i=0;i<n;i++){
            cin>>d;
            ar.push_back(make_pair(i, d));
       }
       sort(ar.begin(), ar.end(), compare);

       ll *v = new ll[n+1];

       for(ll i=0;i<n;i++){
           v[ar[i].first] =i;
       }
       for(ll i =0;i<n;i++){
           cout<<v[i]+1<<" ";
       }
       cout<<endl;
    //    delete v;
        // ar.clear();
    }
    return 0;
}