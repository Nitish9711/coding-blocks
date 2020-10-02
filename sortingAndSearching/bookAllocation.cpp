#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int ar[], int n, int m, int curr_min)
{
    int studentUsed = 1;
    int pages_reading = 0;
    for(int i=0;i<n;i++)
    {
        if(pages_reading + ar[i] > curr_min)
        {
            studentUsed++;
            pages_reading = ar[i];
            if(studentUsed >m)
                return false;
        }
        else{
            pages_reading += ar[i];
        }
    }
    return true;
}
int findPage(int ar[], int n, int m)
{
    long long sum =0;

    if(n<m){
        return -1;
    }

    for(int i=0;i<n;i++)
        sum += ar[i];
    // count the no of pages
    int s = ar[n-1];
    int e = sum;
    int ans = INT_MAX;

    while (s<=e)
    {
        int mid = (s+e)/2;
        
        if(isPossible(ar,n,m, mid))
        {
            ans = min(ans, mid);
            e = mid-1;
        }
        else
        {
            // it is not possible to divide the array at x
            s = mid+1;
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
        int n, m;
        cin>>n>>m;
        int ar[1000];
        for(int j=0;j<n;j++)
            cin>>ar[j];
        cout<<findPage(ar, n, m)<<endl;
    }

    return 0;
}