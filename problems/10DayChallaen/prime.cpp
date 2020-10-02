#include<iostream>
#include<algorithm>
using namespace std;
void isPrime(int n, int a, int b)
{
int fact = 1,i=1;
while(a!=0)
{
    fact = fact*i;
    i++;
    a--;
}

}

int main()
{
    int n;
    cin>>n;
    
    int t[n], a[n], b[n];
    for(int i=0; i<n; i++)
    {
        
    }
    

    return 0;
}
/*
Every prime number can represented in form of 6n+1 or 6n-1 except 2 and 3, where n is natural number.
Goldbach Conjecture: Every even integer greater than 2 can be expressed as the sum of two primes.
Wilson theorem says if a number k is prime then ((k-1)! + 1) % k must be 0.
Fermat’s Little Theorem: If n is a prime number, then for every a, 1 <= a < n,
a^(n-1) ≡ 1 (mod n)
 OR 
 a^(n-1)% n = 1 

*/