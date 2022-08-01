
#include <iostream>
#include<vector>
using namespace std;


int maxD = -1 , maxNode = -1 ;

int vis[300];
int parent[300];
int ran[300];

int findSet(int i){
    if(parent[i] == -1)
        return i;
    return parent[i] = findSet(parent[i]);
}
void unionSet(int x, int y){
    int s1 = findSet(x);
    int s2 = findSet(y);
      if (s1 == s2)
        {
            return;
        }
        else
        {
            if (ran[s1] < ran[s2])
            {
                parent[s1] = s2;
                ran[s2] += ran[s1];
            }

            else
            {
                parent[s2] = s1;
                ran[s1] += ran[s2];
            }
        }
}
bool contain_cycle( vector<vector<int>>& graph, int V){
    	for(int i=1;i<=V;i++){

				for(auto y: graph[i]){
					     if( i < y){
					     	// cout<<i<<" "<<y<<endl;
							int s1 = findSet(i);
							int s2 = findSet(y);
							if(s1!=s2)
								unionSet(s1, s2);
							else
								return true;
					     }	
					}
			}
    return false;
}

void DFS( vector<vector<int>>& graph , int node , int d )
{
    // marking the node as visited
    vis[node] = 1 ;
    // if the distance from root is greater then maximum Distance then updating the maximum value of distance
    // also storing the maxNode no. as this node is now at the farthest distance
    if( d > maxD )
    {
        maxNode = node ;
        maxD = d ;
    }

     // applying the standard dfs 
    for( auto x : graph[node] )
    {
        if( vis[x] == 0 )
        {
            DFS( graph , x , d+1 ) ;
        }
    }
}





int main()
{


    int n;
    cin>>n;
    vector<string>vec(n+1);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        vec[i] = s;
    }
    vector<vector<int>>graph(n+1);

    for(int i=1;i<=n;i++){
        string s= vec[i];
        for(int j =0;j<n;j++){
            if(s[j] == '1'){
                graph[i].push_back(j+1);
            }
        }
    }
    // int cnt =1;
    // for(int i =1;i<=n;i++){
    //     cout<<cnt<<" -> ";
    //     vector<int>x;
    //     x = graph[i];
    //     for(auto y: x)
    //         cout<<y<<" ";
    //     cout<<endl;
    //     cnt++;
    // }
    
    maxD = -1;
    maxNode = -1;
     for( int i = 0 ; i<=299; i++ )
     {
         vis[i] = 0 ;
         parent[i] = -1;
         ran[i] = 1;
     }
    if(contain_cycle(graph, n)){
        cout<<"-1"<<endl;
    }
    else{

    
     DFS( graph , 1 , 1 ) ;

     maxD = -1 ;

     for( int i = 0 ; i<=299; i++ )
     {
         vis[i] = 0 ;
     }
     
     DFS( graph , maxNode , 1  ) ;
     cout<<maxD<<endl;
     }
    return 0;
}




