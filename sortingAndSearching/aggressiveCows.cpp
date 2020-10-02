#include<iostream>
#include<algorithm>
using namespace std;

bool cowsValid(long int ar[], long int n, long int c, long int min_sep)
{
    long int last_cow = ar[0];
    long int cnt = 1;
    for(long int i=1;i<n;i++){
        if(ar[i]- last_cow >= min_sep)
        {
            last_cow = ar[i];
            cnt++;
            if(cnt == c)
                return true;
        }
    }

    return false;
}

long int answer(long int ar[], long int n, long int c)
{
    long int s  = 0;
    long int e =  ar[n-1] - ar[0];

    long int ans = 0;
    while (s <= e)
    {
        long int mid = (s+e)/2;
        
        bool Valid = cowsValid(ar, n, c, mid);
        if(Valid)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid -1;
        }
        
    }
    

    return ans;
}

int main()
{
    
   
        long int n, c;
        cin>>n>>c;

        long int *ar = new long int[n];
        for(long int i=0;i<n;i++)
            cin>>ar[i];
        sort(ar, ar+n);
        cout<<answer(ar, n, c)<<endl;
    
    return 0;
}