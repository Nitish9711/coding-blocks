#include<iostream>

using namespace std;
#define m 998244353
int answer(int ar[], int n)
{
    int c = m;
}

int main()
{
    int t;
    cin>>t;

    for(int i =0;i<t;i++)
    {
        int n;
        cin>>n;
        
        int*ar = new int[n];
        for(int j=0;j<n;j++)
            cin>>ar[i];

        cout<<answer(ar, n)<<endl;
    }
    return 0;
}