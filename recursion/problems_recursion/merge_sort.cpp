#include<iostream>

using namespace std;
#define ll long int

void merge(ll ar[], ll s, ll e)
{
    ll mid = s + (e-1)/2;
    
    ll i =s;
    ll j = mid+1;
    ll k= s;
    ll temp[1000000];    


    while(i<=mid && j<=e)
    {
        if(ar[i] <= ar[j])
            temp[k++] = ar[i++];
        else
            temp[k++] = ar[j++];
    }

    while(i<= mid)
    {
        temp[k] = ar[i];
        k++;
        i++;
    }
    while(j<= e)
    {
        temp[k] = ar[j];
        k++;
        j++;
    }

    for(int i = s;i<=e;i++)
        ar[i] = temp[i];


}



void merge_sort(ll ar[], ll s, ll e)
{
    if(s < e)
    {

        ll mid = s + (e-1)/2;

        merge_sort(ar, s, mid);
        merge_sort(ar, mid+1, e);

        merge(ar, s,  e);
    }

}



int main()
{
    ll n;
    cin>>n;

    ll* ar = new ll[n];
    for(ll i=0;i<n;i++)
        cin>>ar[i];

    merge_sort(ar, 0, n-1);

    for(ll i=0;i<n;i++)
        cout<<ar[i]<<" ";


    return 0;
}