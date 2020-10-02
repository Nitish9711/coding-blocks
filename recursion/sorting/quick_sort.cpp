#include<iostream>

using namespace std;
#define ll long int
ll  partition(ll ar[], ll s, ll e)
{
    //  inplace can't take extra array
    ll i = s-1;
    ll j = s ;

    ll pivot = ar[e];

    for(;j<=e-1;)
    {
        if(ar[j] <= pivot)
        {
            // merge the smaller element in the region
            i = i+1;
            swap(ar[i], ar[j]);
        }
        // expand the larger region
        j = j+1;
    }

    // inplace the pivot element in the correct index
    swap(ar[i+1], ar[e]);

    return i+1;

}

void quick_sort(ll ar[], ll s, ll e)
{
    if(s>=e)
        return;

    ll p = partition(ar, s, e);

    quick_sort(ar, s, p-1);

    quick_sort(ar, p+1, e);

}




int main()
{
    ll n;
    cin>>n;

    ll* ar = new ll[n];
    for(ll i=0;i<n;i++)
        cin>>ar[i];

    quick_sort(ar, 0, n-1);

    for(ll i=0;i<n;i++)
        cout<<ar[i]<<" ";


    return 0;
}