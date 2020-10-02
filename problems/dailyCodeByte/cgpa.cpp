#include<iostream>

using namespace std;
#define ll long int

// function to find repeating elements 
ll printRepeating( ll arr[], ll n) 
{ 
    // First check all the values that are 
    // present in an array then go to that 
    // values as indexes and increment by 
    // the size of array 
    for (int i = 0; i < n; i++) 
    { 
        int index = arr[i] % n; 
        arr[index] += n; 
    } 
  
    // Now check which value exists more 
    // than once by dividing with the size 
    // of array 
    for (int i = 0; i < n; i++) 
    { 
        if ((arr[i]/n) > 1) 
            cout << i << " "; 
    } 
} 
int main()
{
    int n;
    cin>>n;
    ll ar[1005] ;
    ll tm = 0;
    
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        tm = min(ar[i], tm); 
    }



    return 0;
}