#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);

    for(int i=0;i<n;i++)
        cin>>a[i];
    
    int m;
    cin>>m;
    vector<int>b(m);
    
    
    for(int j=0;j<m;j++)
        cin>>b[j];
    
    if(n!=m)
    {
        for(int i=0;i<abs(n-m);i++)
        {
            if((n-m)<0)
                a.insert(a.begin(), 0);
            else
                b.insert(b.begin(),0);
        }
    }
    int  carry =0;
    for(int i =a.size()-1;i>=0;i--)
    {
        a[i] = a[i] + b[i] + carry;
        carry = a[i]/10;
        if(i!=0)
            a[i] = a[i]%10;
    }
    if(a[0] >= 10)
    {
        
        int temp = a[0];
        a.erase(a.begin());
        while(temp != 0)
        {
            a.insert(a.begin(), temp%10);
            temp = temp/10;
        }
        
    }

    for(int i =0;i<a.size();i++)
        cout<<a[i]<<", ";

    cout<<"END";

    return 0;
}