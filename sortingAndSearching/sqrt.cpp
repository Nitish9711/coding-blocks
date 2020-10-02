#include<iostream>

using namespace std;

int sqrt(int n)
{
    int ans = -1;
    int s = 0;
    int e = n-1;
    while(s<=e)
    {
        int mid = (s+e)>>1;

        if(mid*mid == n)
            ans = mid;
        if(mid*mid < n)
        {
            ans = mid;
            s = mid+1;
        }
        else 
        {
            e = mid-1;
        }
       
    }


    return ans;
}


int main()
{
    int n;
    cin>>n;
    
    cout<<sqrt(n);
    return 0;
}