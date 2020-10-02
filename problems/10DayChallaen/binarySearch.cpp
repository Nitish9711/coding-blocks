#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n], f, temp=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cin>>f;
    int i=0;
    while(i<n)
    {
        if(ar[i]==f)
            break;
        i++;
    }  
    if(i==0)
        cout<<"-1";
    else
        cout<<i;
    return 0;  
}