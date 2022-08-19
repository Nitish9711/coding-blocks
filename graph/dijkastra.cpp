#include <bits/stdc++.h>
#include<unordered_map>
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

class node{
    public:
    int vertex, weight;
};

class comp{
    public:
     bool operator()(const node &lhs, const node &rhs) const {
        return lhs.weight > rhs.weight;
    }
};
template<typename T>
class Graph{
    unordered_map<T, list<pair<T, int>>>um;

    public:
    void addEdge(T u, T v, int dist, bool bidir = true){
        um[u].push_back(make_pair(v, dist));
        if(bidir)
            um[v].push_back(make_pair(u, dist));
    }
    void printAdj(){
       
        for(auto j:um){
            cout<<j.first<<" ";
            for(auto p : j.second){
                cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
            }
            cout<<endl;
        }

    }

    void dijsktra(T src){
        unordered_map<T, int>dist;
        for(auto j:um){
            dist[j.first] = INT_MAX;
        }


        set<pair<int, T>>s;
        dist[src] = 0;
        s.insert(make_pair(dist[src], src));
        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            for(auto child: um[node]){
                if(nodeDist + child. second < dist[child.first]){
                    T dest = child.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f!= s.end()){
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + child.second;
                    s.insert(make_pair(dist[dest], dest));
                }

            }

           

        }
         for(auto d: dist){
                cout<<d.first<<" is located  at a dist of "<<d.second<<endl;
            }

    }
    void disjktraPq(T src){
        priority_queue<node, vector<node>, comp>min_heap;
        unordered_map<T, int>dist;
        unordered_map<T, bool>done;
        unordered_map<T, int>parent;
        for(auto j:um){
            dist[j.first] = INT_MAX;
            done[j.first] = false;
            parent[j.first] = -1;
        }
        min_heap.push({src, 0});

        done[src] = true;

        while(!min_heap.empty()){
            node cur_node = min_heap.top();
            min_heap.pop();
            int u =cur_node.vertex;
            for(auto i: um[u]){
                int v = i.first;
                int wt  = i.second;
                if(!done[v] && (dist[u] + wt) < dist[v]){
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                    min_heap.push({v, dist[v]});
                }
            }
            done[u] = true;
        }
        

        for(auto node: um){
            if(node.first != src && dist[node.first] != INT_MAX ){
                cout << "Path (" << src << " —> " << node.first << "): Minimum cost = "
                << dist[node.first] << ", Route = [ ";
                int i = node.first;
                while(parent[i] != -1){
                    cout<<parent[i]<<" ";
                    i = parent[i];
                }
                cout << "]" << endl;
            }
        }

    }
};
int main()
{
    ReadCP();

    Graph<int> g;
    int n = 5;
    // int ar[][3] = {{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};
    int ar[][3] = {{1,3,1},{4,1,2},{7,3,4},{2,5,3},{5,6,1},{6,7,2},{7,5,3},{2,6,4}};



    for(int i =0;i<8;i++){
       g.addEdge(ar[i][0], ar[i][1], ar[i][2]);
    }
    // g.printAdj();
    g.dijsktra(7);
    g.disjktraPq(7);


    return 0;
}