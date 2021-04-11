// optimizing union and path function

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

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Graph
{
    int V;
    list<pair<int, int>> l;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y)
    {
        l.push_back({x, y});
    }

    int findSet(int i, int parent[])
    {
        if (parent[i] == -1)
            return i;
        // path compression optimisation
        return parent[i] = findSet(parent[i], parent);
    }

    void union_set(int x, int y, int parent[], int rank[])
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if (s1 == s2)
        {
            return;
        }
        else
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }

            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    int pairing()
    {
        int *parent = new int[V + 1];
        int *rank = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        int ans = 0;
        for (auto edge : l)
        {
            int s1 = findSet(edge.first, parent);
            int s2 = findSet(edge.second, parent);

            union_set(s1, s2, parent, rank);
           
        }

        for(int i = 0;i<V;i++){
            ans += V- rank[findSet(i, parent)];
        }

        delete[] parent;
        delete[] rank;
        return ans/2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    
    int n, m;
    cin>>n>>m;
    Graph g(n);
    for(int i =0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g.addEdge(x, y);
    }
    cout<<g.pairing()<<endl;

    return 0;
}