#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

// topdown
int optimalStrategyOfGame(int ar[],int i, int j , int dp[][100]){

    if(i> j){
        return 0;

    }

    if(dp[i][j]!= 0)
        return dp[i][j];

    int op1 = ar[i] + min(optimalStrategyOfGame(ar, i+2, j, dp), optimalStrategyOfGame(ar, i+1, j-1,dp));
    int op2 = ar[j] + min(optimalStrategyOfGame(ar, i, j-2, dp), optimalStrategyOfGame(ar, i+1, j-1,dp));

    return dp[i][j] = max(op1, op2);
}   

// bottom up
int answer(int ar[], int n){
    int dp[100][100] = {0};
    
}


int main()
{
    int dp[100][100] ={0};
    int arr1[] = { 8, 15, 3, 7 }; 
    int n = sizeof(arr1) / sizeof(arr1[0]); 
    printf("%d\n", 
           optimalStrategyOfGame(arr1, 0, n-1, dp)); 
    

    // int arr2[] = { 2, 2, 2, 2 }; 
    // n = sizeof(arr2) / sizeof(arr2[0]); 
    // printf("%d\n", 
    //        optimalStrategyOfGame(arr2, n)); 
  
    // int arr3[] = { 20, 30, 2, 2, 2, 10 }; 
    // n = sizeof(arr3) / sizeof(arr3[0]); 
    // printf("%d\n", 
    //        optimalStrategyOfGame(arr3, n)); 
  
    // return 0; 
    return 0;
}