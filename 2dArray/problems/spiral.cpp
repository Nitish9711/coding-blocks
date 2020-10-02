#include<iostream>
using namespace std;


int main()
{
    int m,n;
    cin>>m>>n;
    int ar[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>ar[i][j];
    }
    

    int k = 0, l =0;
    int cnt =0;
    int total = m*n;
    while(k<m && l<n)
    {
        if(cnt == total)
            break;

        //print the first column from the remaining column
        for(int i =k;i<m;i++)
        {
            cout<<ar[i][l]<<", ";
            cnt++;
        }   
        l++;
        if(cnt == total)
            break;
        
        //print the last row from the remaining row
        for(int i=l;i<n;i++)
        {
            cout<<ar[m-1][i]<<", ";
            cnt++;
        }
        m--;
        if(cnt == total)
            break;
        
        //print the last column from the remaining columns

        if(k<n)
        {
            for(int i = m-1;i>=k;i--)
            {
                cout<<ar[i][n-1]<<", ";
                cnt++;
            }
            n--;
        }
        if(cnt == total)
        {
            break;
        }
        if(l<n)
        {
            for(int i = n-1;i>=l;i--)
            {
                cout<<ar[k][i]<<", ";
                cnt++;
            }
            k++;
        }

    

    }
    cout<<"END";

    
    return 0;
}