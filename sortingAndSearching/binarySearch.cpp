#include<iostream>

using namespace std;
int binary_search(int ar[], int n, int f)
{
    int start = 0;
    int end = n-1;
    while(start<=end)
    {
        int mid = (start+end)/2;

        if(ar[mid] == f)
            return mid;
        else if(ar[mid] > f)
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int f;
    cin>>f;
    cout<<binary_search(ar, n, f);
    return 0;
}