#include<iostream>

using namespace std;

int main()
{
     int n;
    cin>>n;
    int ar[n];
    int maxSum=0;
    for(int i=0;i<n;i++)
        cin>>ar[i];


    for(int i=0;i<n;i++)
    {
        
        for(int j=i; j<n;j++)
        {   
            int sum=0;
            for(int k=i;k<=j;k++)
                sum += ar[k];
            if(sum > maxSum)
                maxSum = sum;
        }
      
    }
    cout<<maxSum<<endl;

    return 0;
}