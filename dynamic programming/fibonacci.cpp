#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

// recursion
int recFib(int n){
    if(n == 0 || n== 1)
        return n;

    int ans;
    ans = recFib(n-1) + recFib(n-2);

    return ans;
}


// top down dp
int topFib(int dp[],int n){
    if(n == 0 || n == 1)
    return n;

    if(dp[n]!= 0){
        return dp[n];
    }

    int ans;
    ans = topFib(dp, n-1) + topFib( dp, n-2);
    return dp[n] = ans;

}


// bottom up dp
int botFib( int n){
    int dp[100] =  {0};
    // dp[0] = 0;
    dp[1] = 1;

    for(int i =2;i<n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// bottom Up space optimization
int optbotFib( int n){
    // int dp[100] =  {0};
    // // dp[0] = 0;
    // dp[1] = 1;
    int a = 0;
    int b = 1;
    int c;
    for(int i =2;i<n;i++){
            c = a + b;
            a = b;
            b = c;
    }
    return c;
}


int main()
{
    int n;
    cin>>n;
    // cout<<recFib(n)<<endl;
    // cout<<topFib(dp, n)<<endl;
    // cout<<botFib(n)<<endl;
    cout<<optbotFib(n)<<endl;
    
    return 0;
}