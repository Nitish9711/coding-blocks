#include<iostream>

using namespace std;

bool arraySortedOrNot(long int arr[], long int n) 
{ 
    // Array has one or no element 
    if (n == 0 || n == 1) 
        return true; 
  
    for (long int i = 1; i < n; i++) 
    {    // Unsorted pair found 
        if (arr[i - 1] > arr[i]) 
            return false; 
    }
    return true; 
} 
bool check(long int ar[], long int n, long int k)
{

    for(long int i = k;i<n;i++)
    {
        if(ar[i] < ar[i-k])
            swap(ar[i], ar[i-k]);
    }
    if(arraySortedOrNot(ar, n))
        return true;

    return false;
}
int main()
{
    int t;
    cin>>t;

    for(long int i =0;i<t;i++)
    {
        long int k,n;
        cin>>n>>k;
        
        long int*ar = new long int[n];
        for(long int j=0;j<n;j++)
            cin>>ar[j];

        if(check(ar, n,k))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}