#include<iostream>
#include<limits.h>
using namespace std;



bool answer(int ar[], int n, int i ,int sum , int cnt)
{
    if(i == n)
    {
        if(sum == 8 && cnt > 0)
        return true;
        else 
            return false;
    }

    return answer(ar, n, i+1, sum + ar[i], cnt+1)  || answer(ar, n, i+1, sum, cnt);
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int * ar = new int[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        
        if(answer(ar, n, 0,0, 0))
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}