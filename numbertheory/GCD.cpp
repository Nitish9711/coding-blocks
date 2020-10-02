#include<iostream>

using namespace std;

int GCD(int a, int b)
{
    if(b == 0)
        return a;  
    return GCD(b, a%b);
}


int main()
{
    // Eculid's algorithm
    // GCD(a, b) = GCD(b, a%b)
    // GCD(a, 0) = a
    // Gcd * Lcm = a*b

    int a, b;
    cin>>a>>b;

    cout<<GCD(a, b);

    return 0;
}