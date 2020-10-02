#include<iostream>
#include<algorithm>
using namespace std;

int lower(int ar[], int n, int key)
{
    int ans = -1;
    int s=0;
    int e = n-1;
    while(s<=e)
    {
        int mid = (s+e)/2;

        if(( mid == 0 || key > ar[mid-1]) && ar[mid] == key)
        {
           return mid;
        }
        if(ar[mid] < key)
        {
            s= mid+1;
        }
        else
        {
            e = mid-1;
        }
        
        
    }
    return ans;
}

int upper(int ar[], int n, int key)
{
    int ans = -1;
    int s=0;
    int e = n-1;
    while(s<=e)
    {
        int mid = (s+e)/2;

        if(ar[mid] == key)
        {
            if(ar[mid + 1] != key)
                return mid;
            else
                s = mid+1;
        }
        if(ar[mid] > key)
        {
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
        
        
    }
   
    return ans;
}
int main()
{
    int n;
    cin>>n;

    int *ar = new int[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int key;
        cin>>key;
        cout<<lower(ar, n, key)<<" "<<upper(ar, n, key)<<endl;
    }
    return 0;
}