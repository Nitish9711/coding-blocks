#include<iostream>

using namespace std;

int first_occurence(int ar[], int  n, int key)
{
    int s = 0;
    int e = n-1;

    int ans = -1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(ar[mid] ==  key)
        {
            ans = mid;
            // explore the left part of the array
            e = mid -1;
        }
        else if(ar[mid] > key)
        {
            e = mid -1;
        }
        else
        {
            s = mid + 1;
        }
        

    }
    return ans;

}
int last_occurence(int ar[], int  n, int key)
{
    int s = 0;
    int e = n-1;

    int ans = -1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(ar[mid] ==  key)
        {
            ans = mid;
            // explore the right part of the array
            s = mid + 1;
        }
        else if(ar[mid] > key)
        {
            e = mid -1;
        }
        else
        {
            s = mid + 1;
        }
        

    }
    return ans;

}




int main()
{
    int arr[] = {1, 2, 5, 8, 8, 9, 9, 10, 10, 12, 15, 20};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    cout<<first_occurence(arr, n, key)<<endl;
    cout<<last_occurence(arr, n, key)<<endl;

    return 0;
}