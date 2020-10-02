#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int>output;


void indices (int i, int ar[], int m, int size)
{
    if(i == size)
        return;

    if(ar[i] == m)
        output.push_back(i);
    
    indices(i+1, ar, m, size);
}

int main()
{
   int n;
   cin>>n;
   int *ar = new int[n];
   
   for(int i = 0;i<n;i++)
        cin>>ar[i];

    int m;
    cin>>m;  
    indices(0, ar, m, n);

    for(auto x: output)
        cout<<x<<" ";


    return 0;
}