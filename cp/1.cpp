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

bool isTranspose(vector<ll>m1, vector<ll>m2){

    if(m1[0] != m2[0])
        return false;
    if(m1[3]!= m2[3])
        return false;

    if(m1[1] != m2[2])
        return false;

    if(m1[2]!= m2[1])
        return false;
    
    return true;
}
bool solve(ll n, ll m, vector<vector<ll>>ar){
    if(m%2!= 0)
        return false;

    bool transpose = false;
    for(ll i=0;i<n;i++){
        for(int j =0;j<n;j++){
            // if(i == j)
            //     continue;
            // cout<<"checking ";
            // for(auto x: ar[i])
            //     cout<<x<<" ";
            // cout<<" with ";
            // for(auto x: ar[j])
            //     cout<<x<<" ";
            // cout<<endl;
            if(ar[i][1] == ar[j][2] && ar[i][2] == ar[j][1])
            {
                // cout<<"found "<<endl;
                transpose = true;
                break;
            }
        }
        if(transpose)
            break;
    }

    bool same = false;
    for(ll i=0;i<n;i++){
        if(ar[i][1] == ar[i][2]){
            same = true;
            // cout<<"found 2"<<endl;
            break;
        }
    }
    
    if(same == true && transpose == true)
        return true;

    return false;
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
        ll n, m;
        cin>>n>>m;
        vector<vector<ll>>ar;
        //  top left, top right, bottom left, bottom right;
        for(int i=0;i<n;i++){
            int tl , tr, bl, br;
            cin>>tl>>tr>>bl>>br;
            ar.push_back({tl, tr, bl, br});

        }

        if(solve(n, m, ar)){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}