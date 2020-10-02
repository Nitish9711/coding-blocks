#include<iostream>
#include<algorithm>


using namespace std;

int main()
{   long long int n;  
    cin>>n;
    long long int m =0, p =1, q=1, ar[n],temp = 0,t2=0;
    for(long long int i =0 ;i<n;i++)
    {   cin>>ar[i];
        if(ar[i] == 0)
            temp++;
        
    }

    for(long long int i=0;i<n;i++)
    {
        if(ar[i]<0)
        {
            q = q * ar[i];
            
        }
        else if(ar[i]>0)
        {
            p = p * ar[i];
            q = q *  ar[i];
        }
        else
        {
            p =1;
            q=1;
            
        }
        m = max(max(p, q), m);
        
    }
    long long int f =0;
      for(long long int i=n-1;i>=0;i--)
    {
        if(ar[i]<0)
        {
            q = q * ar[i];
            
        }
        else if(ar[i]>0)
        {
            p = p * ar[i];
            q = q *  ar[i];
        }
        else
        {
            p =1;
            q=1;
            
        }
        f = max(max(p, q), f);
        
    }
    if(temp == n)
        cout<<"0";
    else
    {
        cout<<max(m,f);
    }
    
    // 8
   // 10 1 2 0 2 -10 -8 0
    return 0;
}