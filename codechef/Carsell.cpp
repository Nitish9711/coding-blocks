#include <bits/stdc++.h>
using namespace std;
#define m 1000000007

void update(long int ar[], long int n, long int i)
{
    for(long int j = i+1;j<n;j++)
        {
            if(ar[j] != 0)
                ar[j]--;
        }

        
}
long long int answer(long int ar[], long int n)
{
   long long int sum = 0;
   long int k = 0;
   for(long int i = 0;i<n;i++)
    {
        if(ar[i] != 0)
        {
            sum += ar[i]%m;
            update(ar, n, i);
        }
    }


    
    return sum;
    
}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        long int n;
        cin>>n;
        long int *ar = new long int[n];
        for(int j=0;j<n;j++)
            cin>>ar[j];
        cout<<answer(ar, n)<<endl;
        
    }


}