// adjancey list graph with hashmap
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
    unordered_map<string, list<pair<string, int>>>um;

    public:
    void addEdge(string x, string y, bool bidir, int wt){
        um[x].push_back(make_pair(y, wt));
        if(bidir){
            um[y].push_back(make_pair(x, wt));
        }

    }

    void print(){
        for(auto p: um){
            string city = p.first;
            list<pair<string, int>>nbrs = p.second;
            cout<<city<<" -> ";
            for(auto nbr: nbrs){
                string dest = nbr.first;
                int dist = nbr.second;
                cout<<"( "<<dest<<" "<<dist<<" ), ";

            }
            cout<<endl;
        }
    }
};
int main()
{
    ReadCP();
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "D", false, 50);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 30);
    g.addEdge("B", "D", true, 40);
    g.print();

    return 0;
}