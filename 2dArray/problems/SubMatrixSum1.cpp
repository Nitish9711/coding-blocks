#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int ar[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            ar[i][j] = 0;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>ar[i][j];
            ar[i][j] += ar[i][j-1];
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ar[i][j] += ar[i-1][j];
        }
    }

    int sum =0;
    for(int li=1;li<=n;li++)
    {
        for(int lj=1;lj<=n;lj++)
        {
            for(int bi=li;bi<=n;bi++)
            {
                for(int bj=lj;bj<=n;bj++)
                    sum += ar[bi][bj] - ar[li-1][bj] - ar[bi][lj-1] + ar[li-1][lj-1];
            }
        }
    }
    cout<<sum<<endl;
   

    
    


    
    return 0;
}