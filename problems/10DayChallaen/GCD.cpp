#include<iostream>

using namespace std;

int gcd(int a, int b) 
{   cout<<a<<" "<<b<<endl;
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main()
{   int a, b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
/* this problem can be efficiently by using Euclidean algorithms according to which 
If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change. 
So if we keep subtracting repeatedly the larger of two, we end up with GCD.
Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.
*/