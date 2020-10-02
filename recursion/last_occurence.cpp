#include<iostream>

using namespace std;

void allOcc(int *ar, int i, int n, int key)
{
    if(i==n)
        return;
    if(ar[i] == key)
    {
        cout<<i<<",";
    }
    allOcc(ar, i+1, n, key);
}
int last(int ar[], int n, int key)
{
    if(n== 0)
        return -1;

    int i = last(ar+1, n-1, key);
    if(i == -1)
    {    
        if(ar[0] == key)
        return 0;
        else
        {
            return -1;
        }
    }
    
    return i+1;
}

int main()
{
    int arr[] = { 1, 2,7, 7, 4 ,5 , 6 ,7, 10};
    int key = 7;

    int n = sizeof(arr)/sizeof(int);

    cout<<last(arr, n, key)<<endl;
    allOcc(arr,0, n, key);
    return 0;
}