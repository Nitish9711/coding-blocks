#include<iostream>

using namespace std;

bool check(int ar[], int beg, int end)
{
    if(beg>=end)
        return true;
    else if(ar[beg]==ar[end])
        return check(ar, beg+1, end-1);
    else
        return false;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    if(check(ar, 0, n-1)==1)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    
    return 0;
}