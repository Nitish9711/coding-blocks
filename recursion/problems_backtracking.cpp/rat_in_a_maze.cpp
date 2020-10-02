#include<iostream>
#include<string>
using namespace std;

bool ratInMaze(char maze[][1005], int soln[][1005], int i, int j, int m, int n)
{
    if(i==m && j==n)
    {
        soln[i][j] = 1;

        for(int row=0;row<=m;row++)
        {
            for(int col =0;col<=n;col++)
                cout<<soln[row][col]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    // rat should be inside the grid
    if(i>m || j>n)
    {
        return false;
    }
    if(maze[i][j] == 'X')
        return false;
    
    //assume  solution exist
    soln[i][j] = 1;

    bool rightSucess = ratInMaze(maze, soln, i, j+1, m,n);
    if(rightSucess)
    {
        return true;
    }
    bool downSucess = ratInMaze(maze, soln, i+1, j, m,n);
    if(downSucess)
    {
        return true;
    }
    // backtracking
    soln[i][j] = 0;

    return false;


}
int main()
{
   int n;
   int m;
   cin>>m>>n;

   char maze[1005][1005];

   int sol[1005][1005]={0};

    for(int i=0;i<m;i++)
    {
        for(int j =0;j<n;j++)
            cin>>maze[i][j];
    }

    bool ans = ratInMaze(maze, sol, 0, 0, m-1, n-1);

    if(ans == false)
        cout<<"-1";

    return 0;
}