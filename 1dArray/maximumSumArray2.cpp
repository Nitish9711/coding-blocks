#include<iostream>

using namespace std;

int main()
{
    int a[1000], n, cumSum[1000]={0};
    cin>>n;
    
    int maxSum = 0;
    cin>>a[0];
    cumSum[0] = a[0];

    for(int i=1; i<n; i++)
    {
        cin>>a[i];
        cumSum[i] = cumSum[i-1] + a[i];
    }
                                        
   
    for(int i=0;i<n;i++)
    {
        
        for(int j=i; j<n;j++)
        {   
            int sum = 0;
            sum = cumSum[j] - cumSum[i-1];
            if(sum > maxSum)
                maxSum = sum;
               
        }
      
    }
 

    cout<<maxSum<<endl;

    return 0;
}