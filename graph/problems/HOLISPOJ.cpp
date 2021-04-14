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
    list<pair<int,long long int>> *l;
    public:
        Graph(int n)
        {
            V = n;
            l = new list<pair<int,long long int>>[V+1];
        }
    void add_edge(int u,int v,long long int weight)
    {
        l[u].push_back(make_pair(v,weight));
        l[v].push_back(make_pair(u,weight));
    }
    int dfs_helper(int source,bool *visited,int *nodeCount,long long int &ans)
    {
        visited[source] = true;
        nodeCount[source] = 1;
        for(auto itr:l[source])
        {
            if(!visited[itr.first])
            {   nodeCount[source]+=dfs_helper(itr.first,visited,nodeCount,ans);
                ans+= 2*min(nodeCount[itr.first],V-nodeCount[itr.first])*itr.second;
            }
        }
        return nodeCount[source];
    }
    long long int dfs()
    {
        bool *visited = new bool[V+1]{0};
        int *nodeCount = new int[V+1]{0};
        long long int ans = 0;
        dfs_helper(1,visited,nodeCount,ans);
        return ans;
        // cout<<ans<<endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    int t;
    cin >> t;
    for(int test  = 1;test<=t;test++)
    {
        // int n;
        // cin >> n;

        int n;
        cin>>n;
        Graph g(n);
        while(n>1)
        {
            n--;
            int i,j;
            int k;
            cin>>i>>j>>k;
            g.add_edge(i,j,k);
        }
        // g.dfs();
        // Case #1: 18

        cout <<"Case #"<<test<<": "<<g.dfs() << endl;
    }
    return 0;
}