#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
int R, C;

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// /W N E S
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, 1};
void floodFill(char mat[][50], int i, int j, char ch, char color){
    // base case
    // matrix bound
    if(i <0 || j< 0 || i>= R || j>= C){
        return;
    }

    // boundry condtion for figure
    if(mat[i][j]!= ch){
        return;
    }

    // recu call
    mat[i][j] = color;
    for(int k = 0;k<4;k++){
        floodFill(mat, i+dx[k], j + dy[k], ch, color);

    }
}
void printMat(char input[][50]){
    
    for(int i=0;i<R;i++){
        for(int j = 0;j<C;j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    ReadCP();

    
    cin>>R>>C;
    char input[15][50];
    for(int i =0;i<R;i++){
        for(int j =0;j<C;j++){
            cin>>input[i][j];
        }
    }
    printMat(input);
    floodFill(input,8, 13, '.', 'r');
    printMat(input);

    return 0;
}