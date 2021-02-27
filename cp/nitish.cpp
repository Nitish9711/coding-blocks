#include<bits/stdc++.h>

using namespace std;

#define pi 3.1415926536
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bs binary_search
#define int long long
#define float double
#define mii map<int,int>
#define mci map<char,int>
#define msi map<string,int>
#define mss map<string,string>
#define mcc map<char,char>
#define mpi map<pair<int,int>,int>
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define ss set<string>
#define sc set<char>
int const max1= 1e5+5;
int const mod = 1e9+7;
int inf = 1e18;

int32_t main(){
ios::sync_with_stdio(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
cin.tie(0);
int t=1;
//cin>>t;
while(t--){
    int D,I,S,F,V;
    cin>>D>>I>>S>>V>>F;
    map<int,vs> street;
    for(int i=0;i<S;i++){
        int b,e,l;
        cin>>b>>e;
        string s;
        cin>>s;
        cin>>l;
        street[e].pb(s);
    }
    map<string, int> total;
    for(int i=0;i<V;i++){
        int p;
        cin>>p;
        for(int j=0;j<p;j++){
            string s;
            cin>>s;
            if(j==0){
                total[s]++;
            }
        }
    }
    cout<<I<<endl;
    for(int i=0;i<I;i++){
        cout<<i<<endl;
        cout<<street[i].size()<<endl;
        int denom = 0;
        for(int j=0;j<street[i].size();j++){
                string x = street[i][j];
                denom+=total[x];
        }
        if(denom ==0){
            denom++;
        }
        for(int j=0;j<street[i].size();j++){
            string x = street[i][j];
            cout<<x<<" "<<(1|total[x])*D/denom<<endl;
        }
    }
}
}