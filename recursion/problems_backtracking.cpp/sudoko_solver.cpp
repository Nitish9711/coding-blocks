#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int number)
{
    for(int x = 0;x<n;x++)
    {
        if(mat[x][j] == number || mat[i][x] == number)
        {
        // cout<<"dfjdf";
            return false;
        }
    }
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x = sx;x<sx+rn;x++)
    {
        for(int y = sy; y<sy+rn;y++)
            if(mat[x][y] == number)
                return false;
    }

    return true;
    
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{
    if(i == n)
    {
    
        return true;
    }

    if(j==n)
        solveSudoku(mat, i+1, 0, n);
    
    if(mat[i][j]!= 0)
    {
        return solveSudoku(mat, i, j+1, n);
      
    }

    for(int number = 1;number<=n;number++)
    {
        if(canPlace(mat, i, j, n, number))
        {
            mat[i][j] = number;
            bool couldSolve = solveSudoku(mat, i, j+1, n);
            if(couldSolve)
                return true;

        }
        // backtrack
    }
    mat[i][j] = 0;
    
    return false;
    
}

int main()
{
    int mat[9][9];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    solveSudoku(mat, 0, 0,n);
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
    }

    return 0;
}