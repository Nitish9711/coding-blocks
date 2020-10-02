#include<iostream>

using namespace std;


int main()
{
    int n;
    cin>>n;
    int ar[n][n];
    for(int i= 0;i<n;i++)
    {
        for(int j =0;j<=i;j++)
        {
            if (j==0 ||j==i)
                ar[i][j] =1;
            else
                ar[i][j]=ar[i-1][j-1]+ar[i-1][j];
        }


    }
     for(int i= 0;i<n;i++)
    {
        for(int j =0;j<=i;j++)
        {   cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
