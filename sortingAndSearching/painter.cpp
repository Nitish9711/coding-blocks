#include<bits/stdc++.h> 
using namespace std;


int check(int ar[], int n, int maxLen)
{
     int total = 0, numPainters = 1; 
    for (int i = 0; i < n; i++) { 
        total += ar[i]; 
       if (total > maxLen) { 
            // for next count 
            total = ar[i]; 
            numPainters++; 
        } 
    } 
    return numPainters; 
}

int main()
{
    int k,n;
    cin>>k>>n;
    
    int *ar = new int[n];
    int max_t =0;
    int min_t = 0;
    

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        max_t += ar[i];
        min_t = max(ar[i], min_t);
    }

    int s = min_t;
    int e = max_t;
    int ans = min_t;

    while(s<=e)
    {
        int mid = (s+e)/2;

        int required = check(ar, n, mid);
        if(required <= k)
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
        
    }
    cout<<ans%10000003;


    
    return 0;
}