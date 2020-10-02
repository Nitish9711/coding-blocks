#include<iostream>
#include<vector>
using namespace std;

void sieve_method(int n)
{
    vector<int>factors;
    vector<int>prime;
    int p[100] = {0};
    factors.clear();
    // first mark all odd number's prime
    for(int i = 3;i<= 100;i += 2)
        p[i] = 1;
    
    for(int i = 3;i<=100;i += 2)
    {
        if(p[i] == 1)
        {
            // mark all the multiples of i as not prime
            for(int j = i*i;j<=100;j = j+i)
                p[j] = 0;
        }  
   }

    p[2] = 1;
    p[1] =0;
    p[0] = 0;


    for(int i=0;i<=100;i++)
    {
        if(p[i])
            prime.push_back(i);
            // cout<<i<<endl;
    }
   int i =0;
   int j = prime[i];

   while(j*j<= n)
   {
       if(n%j ==0)
       {
           factors.push_back(j);
           while(n%j == 0)
            {
                n = n/j;
            }
       }
       i++;
       j = prime[i];
   }
   if(n != 1)
    {
        factors.push_back(n);
    }
    for(int i=0;i<factors.size();i++)
    {
        cout<<factors[i]<<endl;
    }

}


void optimized(int n)
{
    vector<pair<int, int>>factor;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            int cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n = n/i;
            } 
            factor.push_back(make_pair(i, cnt));
        }
    }
    if(n != 1)
    {
        factor.push_back(make_pair(n, 1));
    }
    
    for(auto p: factor)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }

}

int main()
{
    int n;
    cin>>n;

    // optimized(n);

    sieve_method(n);
    return 0;
}