#include <bits/stdc++.h>
using namespace std;
#define m 1000000007

long long int answer(long int ar[], long int n)
{
   long long int sum = 0;
   long int k = n-1;
   long int a = 0;
   sort(ar, ar+n);
   for(long int i = 0;i<n;i++)
    {
        if(ar[i] - k<=0)
        {
            k--;
        }
        else
        {
            sum += ar[i]%m - a;
            a++;
            k--;
        }
        
    }



    return sum%m;
    
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