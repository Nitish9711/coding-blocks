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

bool solve(vl ar){
    if((ar[0]< ar[2] && ar[0] < ar[3]) && (ar[1]< ar[2] && ar[1]<ar[3])){
        return false;
    }
    if((ar[2]< ar[0] && ar[2] < ar[1]) && (ar[3]< ar[0] && ar[3]<ar[1])){
        return false;
    }
    return true;

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
        vl ar(4);
        cin>>ar[0]>>ar[1]>>ar[2]>>ar[3];

        if(solve(ar))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;


    }
    return 0;
}