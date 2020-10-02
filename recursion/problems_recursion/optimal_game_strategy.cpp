#include<iostream>

using namespace std;

long long int ans = 0;

void solution(int ar[], int n, int turn)
{
    if(ar[0] == ar[n-1])
        return;
   
   if(turn%2 != 0)
    {
        if(ar[0] > ar[n-1])
        {
            ans += ar[0];
            solution(ar+1, n-1, turn+1);
        }
        if(ar[n-1] > ar[0])
        {
            ans += ar[n-1];
            solution(ar, n-1, turn+1);
        }
    }
    else
    {
        if(ar[0] > ar[n-1])
        {
            // ans += ar[0];
            solution(ar+1, n-1, turn+1);
        }
        if(ar[n-1] > ar[0])
        {
            // ans += ar[n-1];
            solution(ar, n-1, turn+1);
        }
    }
    
}

int main()
{
   int n;
   cin>>n;

   int*ar = new int[n];

   for(int i =0;i<n;i++)
        cin>>ar[i];
    
    solution(ar, n, 1);
    cout<<ans<<endl;
    return 0;
}