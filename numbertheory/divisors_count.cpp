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

    int ans = 1;
    
   while(j*j<= n)
   {
       if(n%j ==0)
       {
           int cnt = 0;
           factors.push_back(j);
           while(n%j == 0)
            {
                n = n/j;
                cnt++;
            }
            ans = ans*(cnt+1);
       }
       i++;
       j = prime[i];
   }
   if(n != 1)
    {
        factors.push_back(n);
        ans = ans*2;
    }
    
    cout<<ans<<endl;
    

}




int main()
{
    int n;
    cin>>n;

    // optimized(n);

    sieve_method(n);
    return 0;
}