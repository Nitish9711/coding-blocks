#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n],m;
    
    for(int i=0;i<n;i++)
        cin>>ar[i];

    cin>>m;
    for(int i=0;i<n;i++)
    {
        if(ar[i]==m)
            cout<<i<<" ";
    }
    return 0;
}