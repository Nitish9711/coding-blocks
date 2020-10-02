#include<iostream>

using namespace std;

int countBits(int a)
{
    int count =0;
    int temp;
    while(a!=0)
    {
        temp = a%2;
        if(temp ==1)
            count++;
        
        a = a/2;
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++)
    {
        cin>>a[i];

        cout<<countBits(a[i])<<endl;
    }
    return 0;
}