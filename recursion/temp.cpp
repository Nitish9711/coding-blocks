#include<iostream>

using namespace std;

void print(int ar[], int n)
{
    static int step = 1;
    cout<<"\n"<<step<<endl; 
   
   for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    
    step++;
}

void merge2(int arr[], int l, int r) 
{ 
    int m  = (l+r)/2;
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


void merge_sort(int ar[], int s, int e)
{
    if(s>=e)
        return;

    // 1. Divide
    int mid = (s+e)/2;

    // recursively sorts arrays- s, mid and mid+1, e
    merge_sort(ar, s, mid);
    merge_sort(ar, mid+1, e);
    
    // merge the two parts

    merge2(ar, s, e);
    print(ar, e);

}


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(int);

    merge_sort(arr, 0, n-1);

    
    cout<<endl;
    cout<<"Sorted"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}