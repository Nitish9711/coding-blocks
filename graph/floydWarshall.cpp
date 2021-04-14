#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

#define INF 10000
void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<vector<int>>floyd_warshall( vector<vector<int>>graph){
    vector<vector<int>>dist(graph);
int V = graph.size();
    for(int k = 0;k<V;k++){
        for(int i =0;i<V;i++){
            for(int j =0;j<V;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;

}
int main()
{
    ReadCP();

    vector<vector<int>>graph = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}
    };


    auto result = floyd_warshall(graph);
    for(int i=0;i<result.size();i++){
        for(int j =0;j<result.size();j++){
            cout<<result[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}