#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
vector<vector<int>> g;
vector<int> longest;
vector<bool> flag;
int f(int v){
    if(flag[v]) return longest[v];
    int ret = 0;
    for(auto nv: g[v]){
        ret = max(ret, f(nv) + 1);
    }
    flag[v] = 1;
    return longest[v] = ret;
}
int main(){
    int N, M; cin >> N >> M;
    g.resize(N);
    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    longest.resize(N, -1);
    flag.resize(N, 0);
    int ans = -1;
    rep(i, N){
        ans = max(ans, f(i));
    }
    cout << ans << endl;
}