#include<iostream>

using namespace std;

int cnt = 0;
bool safe(int board[][13], int i, int j, int n)
{
    for(int k = 0;k<i;k++)
    {
        if(board[k][j] == 1)
            return false;
    }

    int x = i;
    int y = j;
    while(x >=0 && y>=0)
    {
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }
   x = i;
   y = j;
    while(x >=0 && y<n)
    {
        if(board[x][y] == 1)
            return false;
        x--;
        y++;
    }

    return true;
}

bool solveNQueen(int board[][13], int i, int n)
{
    if(i == n)
    {
        // successfully placed the queen
        // print the board
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(board[i][j] == 1)
        //             cout<<"Q ";
        //         else
        //         {
        //             cout<<"_ ";
        //         }      
        //     }
        //     cout<<endl;
        // }

        // cout<<endl<<endl;
        cnt++;
        return false;
    }

    for(int j =0;j<n;j++)
    {
        // if it is safe to place the queen
        if(safe(board, i, j, n))
        {
            board[i][j] = 1;
            bool nextQueenRakhPaye = solveNQueen(board, i+1, n);
                if(nextQueenRakhPaye)
                    return true;
        }
        board[i][j] = 0; // backtrack
        
    }

    return  false;

}
int main()
{
    int n;
    cin>>n;

    int board[13][13] = {0};
    solveNQueen(board, 0, n);
    cout<<cnt;
    return 0;
}