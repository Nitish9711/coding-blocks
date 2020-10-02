#include<iostream>

using namespace std;


int countSetBitsFast(int n)
{
    int ans = 0;
    while(n > 0)
    {
        // this step remove setbits one by one
        //  time complexity o(no of setbits) 
        n = n & (n-1);
        ans++;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        //  atmost no of bits in a number log(n) + 1
        cout<<countSetBitsFast(n)<<endl;
    }
    
    return 0;
}