#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>ar[i][j];
    }

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum += ar[i][j]*((i+1)*(j+1)*(n-i)*(n-j));
        }
    }
    cout<<sum<<endl;
    return 0;
}