#include<iostream>

using namespace std;


void bubble_sort(int ar[], int n)
{
    if(n==1)
        return;
    
    for(int j=0;j<n-1;j++)
    {
        // cout<<ar[j];
        if(ar[j] > ar[j+1])
        {
            swap(ar[j], ar[j+1]);
            // cout<<ar[j]<<" "<<ar[j+1];
        }
    }

    bubble_sort(ar, n-1);
}
void bubble_sort_2(int ar[], int j,int n)
{
    if(n==1)
        return;
    
    if(j== n-1)
    {
        return bubble_sort_2(ar, 0, n-1);
    }

    if(ar[j] > ar[j+1])
    {
        swap(ar[j], ar[j+1]);
    }

    return bubble_sort_2(ar, j+1, n);
}


int main()
{
    int arr[] = { 5, 4, 3, 1, 2};
    int n = sizeof(arr)/sizeof(int);

    bubble_sort_2(arr, 0, n);
    for(auto x: arr)
        cout<<x<<endl;

        
    return 0;
}