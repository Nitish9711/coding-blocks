#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Graph{
    int V;
    list<ll> *adjList;
public:
    vector<ll> edgesInConnectedComponent;
    Graph(int V){
        this->V = V;
        adjList = new list<ll>[V];

    }
    int connectedComponents(){
        vector<bool> visited(V, false);
        int count  = 0, ct = 0;
        for(int i = 1 ; i < V ; i++){
            if(visited[i] == false){
                ct = 0;
                DFSUtil(i, visited,ct);
                count+=1;
                edgesInConnectedComponent.push_back(ct-1);
            }
        }
        return count;
    }
    void DFSUtil(int node , vector<bool>&visited, int &ct){
        visited[node] = true;
        ct+=1;
        for(auto n : adjList[node]){
            if(visited[n] == false)
            DFSUtil(n, visited, ct);
        }
        return ;
    }
    void addEdge(int u , int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
};
int main(){
    int t;
    cin >> t;
    ll s , d;
    ll n , m , a, b;
    while(t--){
        cin >> n >> m >> a >> b;
        Graph g(n+1);
        for(int i = 0; i < m ; i++){
            cin >> s >> d;
            g.addEdge(s, d);
        }
        int c = g.connectedComponents();
        //  temple is less 
        // each node gets its own temple
    ll ans = 0;
        if(a < b){
            ans = n*a;
        }else{
            ans  = c*a ;
            for(int i : g.edgesInConnectedComponent){
                ans+= (i*b);
            } 
        }
        cout << ans <<endl;
    }
}