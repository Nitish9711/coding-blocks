#include<iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int t[T];
    int  count[T]={ };
    // entering the test cases
    for(int i=0; i<T; i++)
    {
       cin>>t[i];
       int ar[t[i]];
       for(int j=0; j<t[i]; j++)
       {
           cin>>ar[j];
       }
       // subarrays
       
        
        for(int x=0;x<t[i];x++)
        {
            
            for(int k=x;k<t[i];k++)
            {   int sum =0;
                for(int f=x; f<=k; f++)
                    sum= sum +ar[f];
                
                if(sum%t[i]==0)
                    count[i]++;
            }
            

        }
       

    }
    
    
    
    for(int i=0;i<T;i++)
    {
       cout<<count[i]<<endl;
       
    }


    return 0;
}