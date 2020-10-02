#include<iostream>

using namespace std;

bool sorted(int ar[], int n)
{
   if(n==0 || n==1)
        return true;
    
    if(ar[0] < ar[1] and sorted(ar+1, n-1))
    {
        return true;
    }
    return false;


}


int main()
{
    // int n;
    // cin>>n;

    int arr[] = {1, 2, 3, 14, 5};
    
    if(sorted(arr, 5))
        cout<<"yes"<<endl;
    else
    {
        cout<<"no"<<endl;
    }
    
    return 0;
}
