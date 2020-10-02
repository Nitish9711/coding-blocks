#include<iostream>

using namespace std;
void counting_sort(int arr[], int n)
{
    int largest = -1;

    for(int i=0;i<n;i++)
    {
        largest = max(largest, arr[i]);
    }
    int *fre = new int[largest+1]{0};

    for(int i=0;i<n;i++)
    {
        fre[arr[i]]++;
    }

    int j=0;
    for(int i=0;i<=largest;i++)
    {
        while(fre[i] > 0)
        {
            arr[j] = i;
            fre[i]--;
            j++;
        }
    }


}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(int);

    counting_sort(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    
    
  
    return 0;
}