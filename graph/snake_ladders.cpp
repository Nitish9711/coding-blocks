#include<bits/stdc++.h>
#include<queue>
#include<map>
#include<list>
using namespace std;

class Graph{
map<int,list<int> > l;
public:

void addEdge(int x,int y){
    l[x].push_back(y);
}

int bfs(int src,int dest){
    map<int,int> dist;
    queue<int> q;

    for(auto node_pair:l){
        int node=node_pair.first;
		dist[node]=INT_MAX;
    }

    q.push(src);
    dist[src]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(int nbr: l[node]){
            if(dist[nbr]==INT_MAX){
                q.push(nbr);
                dist[nbr]=dist[node]+1;
            }
        }

    }

    // for(int node_pair:l){
    //     cout<<node_pair.first<<" and dist "<<dist[node_pair.first]<<endl;
    // }
    return dist[dest];
}
};

int main(){
int t;
cin>>t;
while(t--){
int size,l,s;
cin>>size>>l>>s;

    int board[101]={0};
    while(l--){
        int x,y;
        cin>>x>>y;
        board[x]=y-x;
    }
    while(s--){
        int x,y;
        cin>>x>>y;
        board[x]=y-x;
    }
    
    Graph g;
    int j,i;
    for(i=0;i<=size;i++){
        for(int dice=1;dice<=6;dice++){
            j=i+dice;
            j+=board[j];
      //  }  should not be there 
        if(j<=size){
            g.addEdge(i,j);
        }
    }
}
    g.addEdge(size,size);

    cout<<g.bfs(0,size)<<endl;
    
}
return 0;
}