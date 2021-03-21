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
        // l[y].push_back(x);
    }
    T bfs(T src, T dest){
       
    }
    

};
int main()
{
    ReadCP();
    int board[50] = {0};
    board[5] = 2;
    board[2] = 13;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;
    for(int i =0;i<=36;i++){
        for(int dice = 1;dice<=6;dice++){
            int j = i + dice;
            j+= board[j];
            if(j<=36){
                g.addEdge(i, j);
            }
        }
    }
    // g.addEdge(0, 1);
    // g.addEdge(0,3);
    // g.addEdge(3, 2);
    // g.addEdge(1, 2);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);
    // g.bfs(0);
    g.addEdge(36, 36);
    cout<<g.bfs(0, 36)<<endl;


    return 0;
}