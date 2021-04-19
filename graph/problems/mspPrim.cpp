#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<ll, ll>

#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

class Graph
{
private:
    unordered_map<ll, list<pii>> adjList;
    ll V;

public:
    Graph(ll n)
    {
        V = n;
        for (ll i = 1; i <= n; i++)
        {
            adjList[i];
        }
    }

    void addEdge(ll u, ll v, ll w)
    {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    ll Prims(ll src)
    {
        unordered_map<ll, bool> visited;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        unordered_map<ll, ll> dist;
        unordered_map<ll, ll> parent;

        for (ll i = 1; i <= V; i++)
        {
            dist[i] = INT64_MAX;
            parent[i] = i;
        }

        dist[src] = 0;
        parent[src] = src;
        pq.push({0, src});

        while (!pq.empty())
        {
            pii p = pq.top();
            pq.pop();

            ll node = p.second;
            ll nodeDist = p.first;

            if (visited[node])
            {
                continue;
            }

            // cout << "node = " << node << "      nodeDist=" << nodeDist << endl;

            visited[node] = true;

            for (pii child : adjList[node])
            {
                int v = child.first;
                int wt = child.second;
                if (!visited[v] && dist[v] > wt)
                {
                    dist[v] = wt;
                    pq.push({dist[v], v});
                    parent[v] = node;
                }
            }
        }

        // cout << endl;

        ll mstWeight = 0;

        for (ll i = 0; i < V; i++)
        {
            // cout << x.first << "-" << x.second << endl;
            mstWeight += dist[i];
        }

        return mstWeight;
    }
};

int main()
{
    sync;
    ll V, E;
    cin >> V >> E;

    Graph g(V);

    while (E--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    ll ans = g.Prims(0);
    cout << ans << endl;

    return 0;
}