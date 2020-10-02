#include<iostream>
#include<algorithm>
using namespace std;

bool valid(int ar[], int p, int l, int ct)
{
    int sum = 0;
    for(int i=0;i<l;i++)
    {
        int j=1;
       
        while((j*(j+1)/2) <= (ct/ar[i]))
        {
            sum++;
            j++;
        }
       
        
        if(sum >= p)
        {
            return true;
        }
    }
    return false;
}

int answer(int ar[],  int p, int l)
{
    int ans = 0;
    int maxt = ar[0]*(p*(p+1)/2);
    int mint = 0;
    
    while(mint <= maxt)
    {
        int mid = (mint + maxt)/2;
        if(valid(ar, p, l, mid))
        {
            ans = mid;
            // cout<<"\n"<<mid<<endl;
            maxt = mid-1;
        }
        else
        {
            mint = mid+1;
        }
        
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int p, l;
        cin>>p>>l;

        int *ar = new int[l];
        for(int j=0;j<l;j++)
            cin>>ar[j];
        sort(ar, ar+l);

        cout<<"Time = "<<answer(ar, p, l)<<endl;

    }
    return 0;
}


