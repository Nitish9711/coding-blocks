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
    int *left = &ar[0];
    int *right = &ar[n-1];
    while(left<right)
    {
        int temp = *left + *right;
        if(temp>t)
            right--;
        else if(temp < t)
            left++;
        else
            {cout<<*left<<" and "<<*right<<endl;
                left++;
                right--;
            }
    }
    return 0;
}