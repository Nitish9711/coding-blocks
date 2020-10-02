#include<iostream>


using namespace std;

int bitonic(int ar[], int n)
{  
    int m = 0;
    int inc[n], dec[n];
    inc[0] = 1;
    dec[n-1] = 1;
    for(int i = 1;i<n;i++)
        inc[i] = ar[i] >= ar[i-1] ? inc[i-1] + 1 : 1;
    for(int i = n-2;i>=0;i--)
        dec[i] = ar[i] >= ar[i+1] ? dec[i+1] + 1 : 1;  
    
    m = inc[0] + dec[0] - 1;  
    for (int i = 1; i < n; i++)  
        if (inc[i] + dec[i] - 1 > m)  
            m = inc[i] + dec[i] - 1;  
  
    return m;
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int j =0;j<n;j++)
            cin>>ar[j];
        cout<<bitonic(ar, n);
    }
    
    return 0;
}