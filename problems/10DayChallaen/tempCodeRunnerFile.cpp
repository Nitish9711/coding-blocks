#include<iostream>

using namespace std;

int main()
{
    int n, ar[1000], i, j;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>ar[i][j];
        
    }
    for(i = 0; i<n;i++)
    {
        for(int j=n;j>=0;j++)
            cout<<ar[j][i]<<" ";
        cout<<endl;
    }


    return 0;
}