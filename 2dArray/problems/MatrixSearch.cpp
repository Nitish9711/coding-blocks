#include<iostream>
#include<vector>

using namespace std;




int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
            cin>>a[i][j];
    }
    int find;
    cin>>find;
    int i = 0,j =0;
    int t =0;
    while(1)
    {
        if(i == n || j == -1)
            break;
        if(a[i][j] > find)
            j++;
        else if(a[i][j] < find)
            i--;
        else if(a[i][j] == find)
            {
                t = 1;
                break;
            }
    }

    if(t==1)
        cout<<t;
    else
    {
        cout<<"0";
    }
    
    return 0;
}