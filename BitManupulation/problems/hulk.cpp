#include<iostream>

using namespace std;

int steps(int n)
{
    int ans = 0;

    while(n>0)
    {
        n = n & (n-1);
        ans++;
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;

        cout<<steps(n)<<endl;
    }
    return 0;
}