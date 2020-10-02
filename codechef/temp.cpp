#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i =0;i<t;i++)
    {
        int k,n;
        cin>>n>>k;
        
        int*ar = new int[n];
        for(int j=0;j<n;j++)
            cin>>ar[i];

        if(check(ar, n,k))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}