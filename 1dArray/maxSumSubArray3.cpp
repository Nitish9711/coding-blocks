#include<iostream>

using namespace std;
/*kadane's algorithm*/


int main()
{
     int t;
    cin>>t;

    int cs[t] = {0}, ms[t] ={0};
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;

        int ar[n];
        for(int j=0;j<n;j++)
        {
            cin>>ar[j];
            cs[i] += ar[j];
            if(cs[i] < 0)
                cs[i] = 0;
            ms[i] = max(ms[i], cs[i]);
            
        }
        cout<<ms[i]<<endl;
    }
     

  

    return 0;
}