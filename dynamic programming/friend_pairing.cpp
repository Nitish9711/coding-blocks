#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int countFriendsPairings(int n){
    int dp[n+1] = {0};

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i =3;i<=n;i++){ 
        dp[i] = dp[i-1] + dp[i-2]*(i-1); 
    }
    return dp[n];
}

int main()
{
     int n = 4; 
    cout << countFriendsPairings(n);     
    return 0;
}