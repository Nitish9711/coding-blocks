#include<iostream>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    int ar[r][c];
    int sr = 0, er = r-1, sc = 0, ec= c-1;
    // sr-start row
    // sc - start column
    // ec -end column
    // sc start column
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>ar[i][j];
    }
    while(sr <= er && sc<= ec)
    {
        for(int i=sc; i<=ec;i++)
            cout<<ar[sr][i]<<" ";
        sr++;
        for(int i =sr;i<=er;i++)
            cout<<ar[i][ec]<<" ";
        ec--;

        if(er>sr)
        {
            for(int i=ec;i>=sc;i--)
                cout<<ar[er][i]<<" ";
            er--;
        }
        
        if(ec>sc)
        {
            for(int i=er;i>=sr;i--)
                cout<<ar[sc][i]<<" ";
            sc++;
        }    

    }



    return 0; 
}