// cycle detection in undirected graph

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

class Graph{
    int V;
    list<pair<int, int>>l;
    public:
    Graph(int V){
        this->V= V;
    }

    void addEdge(int x, int y){
        l.push_back({x, y});
    }

    int findSet(int i, int parent[]){
        if(parent[i] == -1)
            return i;

        return findSet(parent[i], parent);
    }


    void union_set(int x, int y, int parent[]){
        int s1 = findSet(x,parent);
        int s2 = findSet(y, parent);
        if(s1 == s2){
            return ;
        }
        else{
            parent[s1] = s2;
        }
    }

    bool contain_cycle(){   
        int *parent = new int[V+1];
        for(int i =0;i<V;i++){
            parent[i] = -1;
        }

        for(auto edge:l){
            int s1 = findSet(edge.first, parent);
            int s2 = findSet(edge.second, parent);

            if(s1 != s2){
                union_set(s1, s2, parent);
            }
            else{
                return true;
            }
        }

        delete [] parent;
        return false;
    }



};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ReadCP();
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    // g.addEdge(3, 0);
    cout << g.contain_cycle() << endl;
    return 0;
}