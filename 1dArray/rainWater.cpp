#include<iostream>
#include<algorithm>

using namespace std;

int trapwater(int ar[], int n)
{
    int left[n], right[n];

    left[0] = ar[0];

    for(int i=1;i<n;i++)
        left[i] = max(ar[i], left[i-1]);

    right[n-1] = ar[n-1];
    for(int i =n-2;i>=0;i--)
        right[i] = max(ar[i], right[i+1]);

    
    int water =0;
    for(int i =0;i<n;i++)
    {
        water += min(left[i], right[i]) - ar[i];
    }

    return water;
}


int main()
{
    int n;
    cin>>n;

    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    cout<<trapwater(ar, n)<<endl;


    
    return 0;

}