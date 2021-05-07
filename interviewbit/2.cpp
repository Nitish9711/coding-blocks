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
    void solve(ll n)
    {
        if(n<=2)
        {
            cout<<"-1"<<endl;
            return;
        }
     
        if(n == 3){
            cout<<"2 9 7"<<endl;
            cout<<"4 6 3"<<endl;
            cout<<"1 8 5"<<endl;
            return;
        }
        
        ll e = 2;
        ll o =1;
        vector<vector<ll>>ar(n, vector<ll>(n,0));
        for(ll i=0;i<n/2;i++){
            ar[0][i] = e;
            e+=2;
        }
        for(ll i = n/2;i<n;i++)
        {
            ar[0][i] = o;
            o+=2;
        }
        for(ll i =1;i<n;i++){
            for(ll j =0;j<n;j++){
                ar[i][j] += ar[i-1][j] + n;;
            }
            // cout<<endl;
        }
        for(ll i =0;i<n;i++){
            for(ll j =0;j<n;j++){
                cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }
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
            solve(n);
        }
        return 0;
    }