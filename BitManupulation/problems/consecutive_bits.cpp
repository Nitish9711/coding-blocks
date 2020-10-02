#include<iostream>

using namespace std;
#define ll long int
#define size 100005
ll bits[100005] = {0};
ll cnt[100005] = {0};

bool valid(ll n) 
{ 
    return (n & (n >> 1)); 
} 
void consecutive()
{

    for(ll i=1;i<size;i++)
    {
        if(bits[i] == 0)
        {
            if(valid(i))
            {
                for(ll j = i;j<size;j = j*2)
                    bits[i] = 1;
            }
        }
    }

   


  
}

int main()
{
    int t;
    cin>>t;

    consecutive();
    for(ll i =1;i<size;i++)
    {
        bits[i] += bits[i-1];
    }
    while(t--)
    {
      ll n;
      cin>>n;
      cout<<n-bits[n]+1<<endl;
    }
    return 0;
}