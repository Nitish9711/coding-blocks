#include<iostream>

using namespace std;
#define ll unsigned long long int

#define max_size 20000999

ll p[max_size] = {0};

void prime_sieve(ll n)
{
    // first mark all odd number's prime
    for(ll i = 3;i<= max_size;i += 2)
        p[i] = 1;
    
    for(ll i = 3;i<=max_size;i += 2)
    {
        if(p[i] == 1)
        {
            // mark all the multiples of i as not prime
            for(ll j = i*i;j<=max_size;j = j+i)
                p[j] = 0;
        }  
   }

    p[2] = 1;
    p[1] =0;
    p[0] = 0;


    ll temp = 0;
    for(ll i=0;i<=max_size;i++)
    {
        if(p[i]  == 1)
            temp++;
        if(temp >= n)
        {
                cout<<i;
                break;
        }
    }
}

int main()
{
    ll n;
    cin>>n;

    
    prime_sieve(n);

   
    
    return 0;
}