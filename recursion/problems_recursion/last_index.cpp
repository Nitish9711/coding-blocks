#include<iostream>

using namespace std;
#define ll long long int



int last_index (ll ar[], int n, ll m)
{
    if(n < 0)
        return -1;
    
    if(ar[n] == m)
        return n;
    
    
    return last_index(ar, n-1,m);

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

    ll m;
    cin>>m;

    cout<<last_index(ar, n-1, m);
    
    return 0;
}