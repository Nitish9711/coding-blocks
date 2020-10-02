#include<iostream>
#include<algorithm>
using namespace std;

void diplay(int a[][1000], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        
        cout<<endl;
    }

}

void rotate(int a[][1000], int n)
{
    // to reverse each row
    for(int i =0;i<n; i++)
    {
        int start_col = 0;
        int end_col = n-1;
        while(start_col < end_col)
        {
            swap(a[i][start_col], a[i][end_col]);
            start_col++;
            end_col--;
        }
    }
    // to transpose
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

void rotateSTL(int a[][1000], int n)
{
    for(int i=0;i<n;i++)
    {
        reverse(a[i],a[i]+n);
    }
     // to transpose
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }

}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    
    
    
    return 0;
}