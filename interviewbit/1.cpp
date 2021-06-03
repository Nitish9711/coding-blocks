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
#define vp vector<pair<ll, ll>>

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// vector<pair<bool, bool>> ar;

bool ar[3][100005] = {true};
map<ll, bool>rowBlock;
bool solve(ll r, ll c, ll n, ll q){
    if(ar[2][n] == false)
        return false;
    
    ar[r][c] = ar[r][c] == true ? false: true;
    
    
    if(ar[1][c] == false && ar[2][c] == false)
    {
        rowBlock[c] = true;
    }
    



    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
   
        ll n, q;
        cin>>n>>q;
        // vp ar;
        // rowBlock.resize(n+1);
        // digBlock.resize(n+1);
        // cout<<n<<q<<endl;
        for(int i =0;i<=n;i++){
            ar[0][i] =true;
            ar[1][i] = true;
            ar[2][i] = true;
        }
        // cout<<n<<q<<endl;
            // cout<<x<<y<<endl;
        while(q--){
            ll x, y;
            cin>>x>>y;
            if(solve(x, y, n, q))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

        }
    
    return 0;
}