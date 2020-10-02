#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n],t,temp;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cin>>t;
    
    sort(ar, ar+n);
    
    for(int i=0;i<n;i++) 
    {  
        int *left = &ar[i+1];
        int *right = &ar[n-1];
         while(left < right)
        {
            int temp = *left + *right + ar[i];
            if(temp > t)
                right--;
            else if(temp < t)
                left++;
            else
            {   cout<<ar[i]<<", "<<*left<<" and "<<*right<<endl;
                left++;
            }    
        }
    }
    
    return 0;
}