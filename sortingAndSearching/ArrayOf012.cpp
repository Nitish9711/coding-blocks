#include<iostream>
#include<algorithm>
using namespace std;

//Dutch national Flag Algorithm

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];

    int mid = 0, left = 0, right = n-1;

    for(int i =0;i<n;i++)
        cin>>arr[i];
    while(mid<=right)
    {
        if(arr[mid] == 1)
            mid++;
        else if(arr[mid] == 0)
            {
              swap(arr[mid], arr[left]);
              left++;
              mid++;
            }
        else if(arr[mid] == 2)
            {
              swap(arr[mid], arr[right]);
              right--;
            }
    }
    for(int i =0;i<n;i++)
        cout<<arr[i]<<" ";
    
    
    return 0;
}