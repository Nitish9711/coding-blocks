#include<iostream>

using namespace std;
#define ll long long int



bool asorted (ll ar[], ll n)
{
    if(n==0 || n== 1)
        return true;
    
    if(ar[n-1] < ar[n-2])
        return 0;
    
    return asorted(ar, n-1);

}

int main()
{
    int n;
    cin>>n;

    ll *ar = new ll[n];
    for(int i =0;i<n;i++)
    {
        cin>>ar[i];
    }

    if(asorted(ar, n))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    
    return 0;
}