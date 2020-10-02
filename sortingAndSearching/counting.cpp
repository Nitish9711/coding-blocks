#include<iostream>

using namespace std;

void counting_sort(int ar[], int n)
{
    int largest = -1;

    for(int i =0;i<n;i++)
    {
        largest = max(largest, ar[i]);
    }

    int *freq = new int [largest + 1]{0};

    for(int i=0;i<n;i++)
        freq[ar[i]]++;
    
    int j =0;
    for(int i=0;i<= largest;i++)
    {
        while(freq[i]>0)
        {
            ar[j] = i;
            freq[i]--;
            j++;
        }
    }

}

int main()
{
    int n;
    cin>>n;

    int *ar = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];

    }

    counting_sort(ar, n);
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";

    }
    
}