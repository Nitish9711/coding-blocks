#include<iostream>
#include<algorithm>


using namespace std;



int kaden(int ar[], int n)
{
    int cs = 0, ms = 0;
    for(int i=0;i<n;i++)
    {
        cs += ar[i];
        if(cs<0)
            cs = 0;
        ms = max(cs, ms);
    }
    return ms;
}

int maxSum(int ar[], int n)
{
    int c1 = kaden(ar, n);
    
    int sum = 0;
    for(int i =0;i<n;i++)
    {
        sum += ar[i];
        ar[i] = -ar[i];
    }
    cout<<kaden(ar,n)<<endl;
    sum = sum + kaden(ar, n);

    return  max(c1, sum);
}




int main()
{
    /*int a[] = {11, 10, -20, 5, -3, -5, 8, -13, 10};  
    int n = sizeof(a)/sizeof(a[0]);  
    cout << "Maximum circular sum is " << maxSum(a, n) << endl;*/

    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int j =0;j<n;j++)
            cin>>ar[j];
        
        cout<<maxSum(ar, n)<<endl;
    }
    
    
    return 0;

}