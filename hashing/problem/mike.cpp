#include <iostream>
#include<map>
#define ll long long int
using namespace std;
int main() {
    map<ll,ll> mp;
    map<ll,ll> ans;
    ll n;
    cin>>n;
    ll arr[n];
    ll val=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(mp.count(arr[i]))
        {
            mp[arr[i]]=val++;
        }
        else
        mp[arr[i]]=val++;
    }

    for(auto it =mp.begin();it!=mp.end();it++)
    {
        ans[it->second]=it->first;
    }
    for(auto it =ans.begin();it!=ans.end();it++)
    {
        cout<<it->second<<endl;
    }


}
