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
void solve(vl ar, ll n)
{
    sort(ar.begin(), ar.end());
    set<ll>s;
   
    
    for(auto x: ar){
        if(x < 0)
        {
            cout<<"NO"<<endl;
            return;
        }
        s.insert(x);
    }
       
    auto i = s.begin();
    // auto j = s.end();
    // j--;
    // for(auto x: s)
    //     cout<<x<<" ";
    // cout<<endl;
    // cout<<*j<<endl;
    // cout<<*i<<endl;
    while(i != s.end() && s.size() <=300){
        auto j = s.end();
        j--;
        while(j != i && s.size() <=300){
            ll d= abs(*i - *j);
            cout<<d<<" "<<*i<< " "<<*j<<endl;
            if(s.find(d) != s.end()){
                j--;
                continue;
            }

            else{
                s.insert(d);
                j--;
            }
        }
        i++;
    }

    if(s.size()>300)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<s.size()<<endl;
       for(auto x: s)
        cout<<x<<" ";
    cout<<endl;
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
        cin >> n;
        vl ar(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> ar[i];
        }

        solve(ar, n);
        // cout<<t<<endl;
    }
    return 0;
}