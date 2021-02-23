#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL



// top down method

int minCoins(vector<int>&coins, int amount, int dp[]){
    if(amount == 0){
        return 0;
    }
    int T = coins.size();

    if(dp[amount]!= INT_MAX){
        return dp[amount];
    }
    int ans = INT_MAX;
    for(int i=0;i<T;i++){
        if(amount-coins[i] >=0){
            int subProb = minCoins(coins, amount-coins[i], dp);
            ans = min(ans, subProb+1);
        }
    }
    dp[amount] = ans;
    return dp[amount];
  
}



int main()
{
    vector<int>coins{9, 6, 5, 1};
    // int coins[] =  {9, 6, 5, 1};/
    // int m = coins.size();
    int V = 11;
    int dp[V+1] = {INT_MAX};
    cout << "Minimum coins required is "
         << minCoins(coins, V,dp);
    return 0;
}