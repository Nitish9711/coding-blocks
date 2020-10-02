#include<iostream>

using namespace std;

int merge(int ar[], int s, int e)
{
    int mid = (s+e)/2;
    int i =s;
    int j = mid+1;
    int k =s;
    
    int temp [10000] ;
    int cnt = 0;

    while (i<=mid && j<=e)
    {
        if(ar[i]<= ar[j])
        {
            temp[k] = ar[i];
            k++;
            i++;
        }
        else
        {
            temp[k++]  = ar[j++];;
                cnt += mid-i+1;
        }
        
    }
    // filling
    while(i<=mid)
    {
        temp[k++] = ar[i++];
    }
    while(j<=e)
    {
        temp[k++] = ar[j++];
    }

    for(int i=s;i<=e;i++)
    {
        ar[i] = temp[i];
    }
    
    return cnt;
}

int inversion_count(int ar[], int s, int e)
{
    if(s>=e)
        return 0;
    
    // merge sort
    int mid = (s+e)/2;
    int x = inversion_count(ar, s, mid);
    int y = inversion_count(ar, mid+1, e);

    int z = merge(ar, s,e);


    return x+y+z;

    
}

int main()
{
    int arr[] = {1, 5, 2, 6, 3, 0}; 
    int n = sizeof(arr)/sizeof(int);

    cout<<inversion_count(arr, 0, n-1)<<endl;
    return 0;
}