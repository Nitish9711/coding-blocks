#include<iostream>

using namespace std;

void print(int ar[], int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<endl;
}
void linearSort(int ar[], int n)
{
    int l =0;
    int h = n-1;
    int mid = 0;
    while(mid<=h)
    {
        if(ar[mid] ==  0)
        {
            swap(ar[mid], ar[l]);
            l++;
            mid++;
        }
        else if(ar[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(ar[mid], ar[h]);
            h--;
        }
        
    }
    print(ar, n);
}


int main()
{
    int n;
    cin>>n;
    int*ar = new int[n];

    for(int i=0;i<n;i++)
        cin>>ar[i];

    linearSort(ar, n);
    
    return 0;
}