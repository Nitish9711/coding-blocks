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
   int N;
   map<T, list<T>>l;
   public:
   Graph(int n){
       N = n;
   }
   void addEdge(int x,int y){
       l[x].push_back(y);
       l[y].push_back(x);
   }

   void bfs(T src){
       map<T, bool>dist;
       queue<T>q;
       q.push(src);
        for(auto node: l){
            dist[node.first] = INT_MAX;
        }
        dist[src] = 0;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(auto nbr: l[node]){
                if(dist[nbr] == INT_MAX){
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }


        for(auto node_pair: l){
            T node =node_pair.first;
            int d  = dist[node];
            cout<<"node "<<node<<" "<<" dist from the src "<<d<<endl;
        }

   }

};
int main()
{
    ReadCP();
    Graph<int> g(6);
    g.addEdge(0, 1);
    g.addEdge(0,3);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);


    return 0;
}