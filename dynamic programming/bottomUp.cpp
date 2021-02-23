#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL


int minCoins(vector<int>&coins, int amount){
      // bottom-up DP
        vector<int> dp(amount + 1, amount + 1); // size and values initially filled
        dp.at(0) = 0;
        
        for(int i = 1; i < amount + 1; i++){
            for(int j = 0; j < coins.size(); j++){
                if(coins.at(j) <= i)
                    dp.at(i) = min(dp.at(i), dp.at(i - coins.at(j)) + 1);
            }
        }
        
        if(dp.back() > amount) return -1;
        return dp.back();
}
int main()
{
   
   vector<int>coins{9, 6, 5, 1};
    // int coins[] =  {9, 6, 5, 1};/
    // int m = coins.size();
    int V = 11;
    // int dp[V+1] = {INT_MAX};
    cout << "Minimum coins required is "
         << minCoins(coins, V);
    return 0;
}