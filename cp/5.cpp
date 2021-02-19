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
       unordered_map<string, int>um;

        ll n;
        string str;
        cin>>n;
        for(ll i =0;i<n;i++){
            cin>>str;
            um.insert(make_pair(str, 1));
        }

        for(ll i =0;i<um.size();i++){

            for(ll  j = 0;j<um.size();j++){
                if(i!= j ){
                    ll w1 = um.
                }
            }
        }
    }   
    return 0;
}