#include<iostream>

using namespace std;

int Count_Set(int n)
{
    int bits = 0;
    while(n > 0)
    {
       n = n & (n-1);
       bits++;
    }
    return bits;
}

int answer(int a, int b)
{
    int ans = 0;
    for(int i = a; i<=b;i++)
    {
        ans += Count_Set(i);
    }
    return ans;
}

int main()
{
    int q;
    cin>>q;
    int *ar = new int[q];

    for(int i=0;i<q;i++)
    {
        int a, b;
        cin>>a>>b;
        cout<<answer(a, b)<<endl;

    }
    
    return 0;
}