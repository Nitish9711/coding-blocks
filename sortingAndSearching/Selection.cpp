#include<iostream>

using namespace std;

void print(int ar[], int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<endl;
}
void selectionSort(int ar[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index = i;
        for(int j =i+1;j<n;j++)
        {
            if(ar[j] < ar[min_index])
                min_index = j;
        }
        swap(ar[i], ar[min_index]);
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

    selectionSort(ar, n);
    
    return 0;
}