// adjeancy list 
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

class Graph{
   int V;
   list<int>*l;
   public:
   Graph(int V){
       l = new list<int>[V];
       this->V = V;
   }
   void addEdge(int x, int y){
       l[x].push_back(y);
       l[y].push_back(x);
   }

    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<"vertex "<<i<<" ->";
            for(auto nbr: l[i])
                cout<<nbr<<" ,";
            cout<<endl;

        }
    }


};
int main()
{
    ReadCP();

    Graph g(4);
    g.addEdge(3, 2);
    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.printAdjList();

    return 0;
}