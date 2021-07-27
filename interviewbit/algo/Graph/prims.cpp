#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Graph{
    int V;
    vector<pair<int, int>> *l;
    public:
    Graph(int n){
        V = n;
        l = new vector<pair<int, int>>[n];
    }
    void addEdge(int x, int y, int w){
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }


    int mst_prim(){
        int ans =0;
        // x -> y with wt w
        // then pq will have (w, y)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<bool>visited(V, 0);

        pq.push({0, 0});
        while(!pq.empty()){
            auto best = pq.top();
            pq.pop();
            int to = best.second;
            int wt = best.first;
            if(visited[to])
                continue;
            
            ans += wt;
            visited[to] = 1;
            for(auto x: l[to]){
                if(visited[x.first] == 0){
                    pq.push({x.second, x.first});
                }
            }


        }

        return ans;
    }
};
int main()
{
    ReadCP();

    int n, m;
    cin>>n>>m;

    Graph g(n);

    for(int i=0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;

        g.addEdge(x-1,y-1, w);
    }

    cout<<g.mst_prim()<<endl;
    return 0;
}