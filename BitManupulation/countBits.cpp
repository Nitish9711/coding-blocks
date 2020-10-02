#include<iostream>

using namespace std;


int countSetBitsfirst(int n)
{
    int ans = 0;
    while(n > 0)
    {
        // time complextity O(logn)
        ans += n & 1;
        n = n>>1;
    }
    return ans;
}
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
    int n;
    cin>>n;
    //  atmost no of bits in a number log(n) + 1
    cout<<countSetBitsfirst(n)<<endl;
    cout<<countSetBitsFast(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;
    return 0;
}