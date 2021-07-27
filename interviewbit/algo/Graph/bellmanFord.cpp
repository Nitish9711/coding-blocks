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


vector<int> bellman_ford(int V, int src, vector<vector<int>>edges){

    vector<int>dist(V+1, INT_MAX);
    dist[src] = 0;
    for(int i =0;i<V-1;i++){
        for(auto edge : edges){
            int u = edge[0] ,v = edge[1] , wt = edge[2]; 
            if(dist[u] + wt < dist[v] && dist[u] != INT_MAX){
                dist[v] = dist[u]  + wt;
            }
        }
    }

     for(auto edge:edges){
        int u = edge[0], v = edge[1], wt = edge[2];

            if(dist[u] + wt < dist[v] && dist[u]!= INT_MAX){
                cout<<"NEGative"<<endl;
                exit(0);
            }
                // 
    }



    return dist;
}

int main()
{
    ReadCP();

    int n, m;
    cin>>n>>m;

    vector<vector<int>>edges;  //(x, y, wt);

    for(int i =0;i<m;i++){
        int u, v, wt;
        cin>>u>>v>>wt;

        edges.push_back({u, v, wt});
    }

    // bellmanford algorithm
    vector<int>dist = bellman_ford(n, 1, edges);
    for(int i =1; i<=n;i++){
        cout<<"Node "<<i<<" is at dist "<<dist[i]<<endl;
    }

    return 0;
}