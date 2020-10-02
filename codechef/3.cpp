#include <iostream> 
#include<algorithm>
using namespace std;

#define ll long int


void answer(char ar[], int n, int k)
{
    
}

int main()

{
    ll t;
    cin>>t;

   
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        char str[n];
        cin>>str;

        sort(str, str+n);
        
        answer(str,n, k);
        
        
    }

        
        
    
    return 0;
}