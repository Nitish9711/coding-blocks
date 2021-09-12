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

/*prims algo
weighted undirected graph
greedy algorithm

TERMS
1. MST set =[] all the nodes that have been implemented in mst till now
2. active edge = edge from a vertex in MST to V;
3. MST edge - AN edge that has been included in MST so far


algo steps
1. start from any source vertex.
2. find the active edges from that source
3. out of all active edges , pick the one with the smallest weight.
    - select Y in MST
    - add edges starting from y in active edge list
    repeat above steps until all vertices are covered*/

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