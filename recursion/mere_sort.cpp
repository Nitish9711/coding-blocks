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

void merge(int ar[], int s, int e)
{
    int mid = (s+e)/2;

    int i =s;
    int j = mid+1;
    int k = s;

    int temp[100] ;

    while(i<=mid && j<=e)
    {
        if(ar[i] < ar[j])
        {
           temp[k++] = ar[i++];
        }   
        else
        {
            temp[k++] = ar[j++];
        }

        
        
    }

        while(i<=mid)
        {
            temp[k++] = ar[i++];
        }
        while(j<=e)
        {
            temp[k++]= ar[j++];
        }
    //  copy all the elements is original arrays

    for(int i=s;i<=e;i++)
    {
        ar[i] = temp[i];
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

    merge(ar, s, e);
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