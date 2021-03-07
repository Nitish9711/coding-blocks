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
    int V;
    list<int>*l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
}

    void addEdge(int x, int y){
        l[x].push_back(y);
    }
    void top_sort(){
        int *indegree = new int[V];
        for(int i=0;i<V;i++){
            indegree[i] = 0;
        }
        for(int i =0;i<V;i++){
            for(auto y: l[i]){
                indegree[y]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            for(auto nbr: l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        
    }

   

};
int main()
{
    ReadCP();
   

    Graph<int> g(6);
   
  
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 5);
    


    g.top_sort();
   


    return 0;
}