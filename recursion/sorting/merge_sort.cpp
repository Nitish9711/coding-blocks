#include<iostream>

using namespace std;

void print(int ar[], int n)
{
    static int step = 1;
    cout<<"\n"<<step<<endl; 
   
   for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    
    
}

void merge(int ar[], int s, int e)
{
    int mid = (s+e)/2;

    int i =s;
    int j = mid+1;
    int k = s;

    int temp[100];

    while(i<=mid && j<= e)
    {
        if(ar[i]< ar[j])
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
        temp[k++] = ar[j++];
    }


    for(int i = s;i<=e;i++)
        ar[i] = temp[i];


}
void merge_sort(int arr[], int s, int e)
{
    if(s>= e)
        return ;

    int mid = (s+e)/2;
    merge_sort(arr, s , mid);
    merge_sort(arr, mid+1 , e);

    merge(arr, s, e);
    

}

int main()
{
    int arr[] = {5,3, 6, 4 ,1, 2}; 
    int n = sizeof(arr)/sizeof(int);

    merge_sort(arr, 0, n-1);

    
    cout<<endl;
    cout<<"Sorted"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

   
    return 0;
}