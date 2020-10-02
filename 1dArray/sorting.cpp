#include<iostream>

using namespace std;
void print(int ar[], int);
void selection_sort(int ar[], int n)
{
    for(int i=0;i<n;i++)
    {   
        int min_index = i;
        for(int j=i;j<n;j++)
        {
            if(ar[j]<ar[min_index])
                min_index =j;
        }
        swap(ar[min_index], ar[i]);
    }
    print(ar, n);
}
void bubble_sort(int ar[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(ar[j]>ar[j+1])
                swap(ar[j], ar[j+1]);
        }
    }
    print(ar, n);
}

void insertion_sort(int ar[], int n)
{   
    for(int i=1;i<n;i++)
    {
        int e = ar[i];
        int j = i-1;
        while(j>=0 && ar[j]>e)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = e;
    }
    print(ar, n);
}
void print(int ar[], int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    selection_sort(ar, n);
    bubble_sort(ar, n);
    insertion_sort(ar, n);
    return 0;
}