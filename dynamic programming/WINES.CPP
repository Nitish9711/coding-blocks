#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

#define N 1000 
  

// int sell[N][N]; 

// top down
int maxProfit(int wines[],int i , int j, int y, int dp[][100]){
    // base class
    if(i>j)
        return 0;

    if(dp[i][j]!= 0){
        return dp[i][j];
    }

    int op1 = wines[i]*y + maxProfit(wines, i+1, j, y+1, dp);
    int op2 = wines[j]*y + maxProfit(wines,i , j-1, y+1, dp);

    return dp[i][j] = max(op1, op2);
}


// bottom up
int profit(int bottle[], int n ){
int dp[100][100] = {0};
int year = n;
int start = 0;
int end = n-1;
    dp[start][start] = year*bottle[start];

    for(int j=start+1; j<=end; j++)
    {
        for(int i=j; i>=0; i--)
        {
            int m = year-(j-i);
            int x = m*bottle[j] + dp[i][j-1];
            int y = m*bottle[i] + dp[i+1][j];
            dp[i][j] = max(x,y);
        }
     }
      for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

     return dp[start][end];
}


int main()
{
   
        // int dp[100][100] ={0};
        // int price[] = {2, 3, 5, 1, 4};
        int price[] = { 2, 4, 6, 2, 5 }; 

        int n = sizeof(price) / sizeof(price[0]);

        // int ans = maxProfit(price, 0,n-1, 1, dp);
        int ans = profit(price,n);

        cout << ans << endl;
    
    return 0;
}