#include<iostream>

using namespace std;

int answer(int ar[], int n, int key)
{
    
    int s= 0;
    int e = n-1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(ar[mid] == key)
            return mid;
        else if(ar[mid] >= ar[s])
        {
            if(ar[mid] >= key && ar[s] <= key)
                e = mid-1;
            else
                s = mid+1;
        }
        else
        {
            if(ar[mid] <= key && ar[e] >= key)
                s = mid+1;
            else
                e = mid-1;
         }
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;
    int *ar = new int[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    int key;
    cin>>key;
    cout<<answer(ar, n, key);
    return 0;
}