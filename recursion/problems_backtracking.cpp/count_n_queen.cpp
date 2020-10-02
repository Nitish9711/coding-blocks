#include<iostream>

using namespace std;
int cnt = 0;

bool safe(int board[][12], int i, int j, int n)
{
    for(int k =0;k<i;k++)
    {
        if(board[k][j] == 1)
            return false;
    }

    int x= i;
    int y = j;

    while (x>=0 && y>=0)
    {
        if(board[x][y] == 1)
            return false;

        x--;
        y--;
    }
     x= i;
     y = j;

    while (x>=0 && y<n)
    {
        if(board[x][y] == 1)
            return false;

        x--;
        y++;
    }
    return true;
    
}

bool solveNQueen(int board[][12], int i , int n)
{
    if(i == n)
    {
        cnt++;
        return false;
    }

    for(int j = 0;j<n;j++)
    {
        if(safe(board, i, j,n))
        {
            board[i][j] = 1;
            bool nextQueenRakhPaye = solveNQueen(board, i+1, n);
                if(nextQueenRakhPaye)
                    return true;
        }
        board[i][j] = 0;
    }


    return false;

}


int main()
{
    int n;
    cin>>n;

    int board[12][12] = {0};
    solveNQueen(board, 0, n);
    cout<<cnt;
    return 0;
}