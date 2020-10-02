#include<iostream>

using namespace std;
#define ll long long

ll p[1000005] = {0};
ll csum[1000005] = {0};

void prime()
{
    for(ll i= 3;i<=1000000; i+=2)
        p[i] =1;
    
    for(ll i = 3;i<=1000000;i+=2)
    {
        if(p[i] ==1)
        {
            for(ll j = i*i; j<=1000000; j += i)
            {
                p[j] = 0;
            }
        }
    }
    p[0] =  0;
    p[1] = 0;
    p[2] = 1;


}
int main()
{
    prime();
    
    for(ll i = 1;i<=1000000;i++)
    {
        csum[i] = csum[i-1] + p[i];
    }

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        ll a, b;
        cin>>a>>b;

        cout<<csum[b] - csum[a-1]<<endl;
    }
    return 0;
}