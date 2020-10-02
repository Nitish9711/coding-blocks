#include<iostream>

using namespace std;

int first(int ar[], int n,int key)
{
   if(n== 0)
        return -1;

    if(ar[0] == key)
        return 0;
   
   int i = first(ar+1, n-1, key);
   if(i == -1)
        return -1;
    
    return i+1;


}

int linearSearch(int ar[], int i, int n, int key)
{
    if(i == n)
        return -1;

    if(ar[i] == key)
        return i;
    
    return linearSearch(ar, i+1, n, key);
}


int main()
{
    int arr[] = { 1, 2,7, 7, 4 ,5 , 6 ,7, 10};
    int key = 7;

    int n = sizeof(arr)/sizeof(int);

    cout<<first(arr, n, key);
    return 0;
}