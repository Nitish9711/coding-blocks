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



class DSU{
    int *parent;
    int *rank;
    int ele;
    public:
        DSU(int n){
            ele = n;
            parent = new int[n];
            rank = new int[n];
            for(int i =0;i<n;i++){
                parent[i] = -1;
                rank[i] = 1;
            }
        }

        // find function
        int find(int i){
            if(parent[i] ==-1){
                // cout<<parent[i]<<" "<<i<<endl;
                return i;
            }

            return parent[i] = find(parent[i]);
        }

        //union by rank

        void unite(int x, int y){
            int s1= find(x);
            int s2 = find(y);
            if(s1!= s2){
                if(rank[s1]<rank[s2]){
                    parent[s1] = s2;
                    rank[s2]+= rank[s1];
                }
                else{
                    parent[s2] = s1;
                    rank[s1]+= rank[s2];
                }
            }
        }
        void display(){
            
            for(int i=0;i<ele;i++){
                cout<<"( "<<parent[i]<<" ,"<<i<<" )";
            }
            cout<<endl;
        }

};




class Graph{
    vector<vector<int>> edgelist;  
    int V;

    public:
        Graph(int V){
            this->V= V;
        }

        void addEdge(int x, int y, int w){
            edgelist.push_back({w, x, y});
        }

        int kruskal_mst(){
             // 1.sort all the edges on the base of weight

            sort(edgelist.begin(), edgelist.end());
            int ans = 0;
            DSU s(V);
            // s.display();
            for(auto edge: edgelist){
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];
                
                if(s.find(x)!= s.find(y)){
                    s.unite(x, y);
                    ans+= w;
                    // s.display();
                    // cout<<x<<" "<<y<<" "<<endl;
                }

            }
            return ans;

        }
};
int main()
{
    ReadCP();

    int n, m;
    cin>>n>>m;

    Graph g(n);
    for(int i=0;i<m;i++){
        int x, y, k;
        cin>>x>>y>>k;
        g.addEdge(x-1, y-1, k);

    }
    
  
    cout<<g.kruskal_mst()<<endl;

    return 0;
}