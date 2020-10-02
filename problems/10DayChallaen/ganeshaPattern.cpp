#include<iostream>

using namespace std;
int main()
{
    int n, z;
    cin>>n;
    z = (n/2) ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==z)
                cout<<"*";
            else if(i<z)
                if(i==0)
                    if(j==0 || j>=z)
                        cout<<"*";
                    else
                        cout<<" ";
                else
                    if(j==0 || j==z)
                        cout<<"*";
                    else
                        cout<<" ";        
            else if(i>z && i!=n-1)
                if(j==z || j==n-1)
                    cout<<"*";
                else
                    cout<<" ";
            else
                if(j<=z || j==n-1)
                    cout<<"*";
                else
                    cout<<" ";
                
                
        }
        cout<<endl;
    }
    return 0;
}