#include<iostream>

using namespace std;

int main()
{
    int n, ar[1000][1000], i, j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>ar[i][j];
        
    }
    for(i = n-1; i>=0;i--)
    {
        for(j=0;j<n;j++)
            cout<<ar[j][i]<<" ";
        cout<<endl;
    }


    return 0;
}