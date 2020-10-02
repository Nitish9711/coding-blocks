#include<iostream>

using namespace std;


int Pivot(int ar[], int n)
{
    int start = 0, end = n-1;
    while(start <= end)
    {
        int mid = (start + end) /2;
        // cout<<mid<<endl;
        if(ar[mid] < ar[mid-1] && mid>start)
            return mid-1;
        if(ar[mid] > ar[mid+1] && mid<end)
            return mid;
        if(ar[start] >= ar[mid])
            end = mid-1;
        else
            start = mid + 1;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int *ar = new int[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    cout<<Pivot(ar, n);
    return 0;
}