#include<iostream>

using namespace std;

int  partition(int ar[], int s, int e)
{
    //  inplace can't take extra array
    int i = s-1;
    int j = s ;

    int pivot = ar[e];

    for(;j<=e-1;)
    {
        if(ar[j] <= pivot)
        {
            // merge the smaller element in the region
            i = i+1;
            swap(ar[i], ar[j]);
        }
        // expand the larger region
        j = j+1;
    }

    // inplace the pivot element in the correct index
    swap(ar[i+1], ar[e]);

    return i+1;

}

void quick_sort(int ar[], int s, int e)
{
    if(s>=e)
        return;

    int p = partition(ar, s, e);

    quick_sort(ar, s, p-1);

    quick_sort(ar, p+1, e);

}




int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(int);

   quick_sort(arr, 0, n-1);
    cout<<"Sorted"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}