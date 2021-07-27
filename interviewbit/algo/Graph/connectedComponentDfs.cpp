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
template<typename T>
class Graph{
    map<T, list<T>>l;
    public:
    void addEdge(T x, T y ){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool>&visited){
        cout<<src<<" ";
        visited[src] = true;
        for(auto nbr: l[src]){
            if(!visited[nbr])
                dfs_helper(nbr, visited);
        }
    }
    void dfs(){
        map<T, bool>visited;
        for(auto p: l){
            visited[p.first] = false;
        }
        int cnt =0;
        for (auto p: l){
             T src = p.first;
             if(!visited[src]){
                cout<<"component "<<cnt<<" ->";
                 cnt++;
                 dfs_helper(src, visited);
                 cout<<endl;
             }
        }
    }
};
int main()
{
    ReadCP();
   

    Graph<int> g;
   
    g.addEdge(0, 1);
    g.addEdge(0,3);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(6, 5);
    g.addEdge(7, 6);

    g.addEdge(8, 9);

    g.dfs();
   


    return 0;
}