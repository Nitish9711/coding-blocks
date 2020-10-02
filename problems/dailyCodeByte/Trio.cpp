#include<iostream>

using namespace std;


int findWays(char ar[][15], int n)
{   int f =0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<15;j++)
        { if(ar[i][j] == 'a' || ar[i][j] == 'e' ||ar[i][j] =='i'||ar[i][j]=='o'||ar[i][j]=='u')
            {
                
            }

        }

    }

    return f;
}

int main()
{
    int T;
    cin>>T;
    //int ans[T];
    while(T--)
    {
        int n;
        cin>>n;

        char ar[n][15];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        
        cout<<findWays(ar, n)<<endl;
 
    }
    return 0;
}