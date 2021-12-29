#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<vector<ll>>ar(n, vector<ll>(3, 0));
        vector<bool>done(n+1, false);
        vector<bool>temp(n+1, false);
        temp[0] = true;
        done[0] =true;
        ll full = 0;
        for(ll i =0;i<n;i++){
            cin>>ar[i][0];
            cin>>ar[i][1];
            temp[ar[i][0]] = true;
            temp[ar[i][1]] = true;
            if(ar[i][0] == ar[i][1]){
                ar[i][2] = ar[i][0];
                done[i] = true;
            }
            if(ar[i][0] == 1 && ar[i][1] == n)
                full = i;
        }

        for(ll i =0;i<=n;i++){
            if(temp[i] == false){
                done[i]  = true;
                ar[full][2] = i;
                break;
            }
        }

        
        
        for(ll i =0;i<n;i++){
            cout<<ar[i][0]<<" "<<ar[i][1]<<" "<<ar[i][2]<<endl;
        }
    }
    return 0;
}