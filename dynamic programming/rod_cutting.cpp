#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL


// recursion bruteforce(o(n power(n)))
int answer(int price[], int n){
    if(n == 0)
        return 0;

    int max_value = INT_MIN;

    for(int i =1;i<=n;i++){
        int cost = price[i-1] + answer(price, n-i);
        if(cost > max_value){
            max_value = cost;
        }
    }
    return max_value;
}

// dp bottom up
// O(N2)
int answer2(int price[], int n){
    if(n == 0)
        return 0;

    int dp[n+1] ={0};

    for(int i =1;i<=n;i++){

        for(int j =1;j<=i;j++){
            dp[i] = max(dp[i],price[j-1] + dp[i-j]);
        }
    }
    
    return dp[n];
    
}

// dp top down
int t[9][9]; 
int un_kp(int price[], int length[],  
                    int Max_len, int n) 
{ 
  
    // The maximum priceue will be zero, 
    // when either the length of the rod 
    // is zero or price is zero. 
    if (n == 0 || Max_len == 0)  
    { 
        return 0; 
    } 
  
    // If the length of the rod is less 
    // than the maximum length, Max_lene will 
    // consider it.Now depending  
    // upon the profit, 
    // either Max_lene  we will take  
    // it or discard it. 
    if (length[n - 1] <= Max_len)  
    { 
        t[n][Max_len] 
            = max(price[n - 1] 
                      + un_kp(price, length, 
                           Max_len - length[n - 1], n), 
                  un_kp(price, length, Max_len, n - 1)); 
    } 
  else 
    { 
        t[n][Max_len] 
            = un_kp(price, length,  
                              Max_len, n - 1); 
    } 
  
    // Max_lene Max_lenill return the maximum 
    // value obtained, Max_lenhich is present 
    // at the nth roMax_len and Max_lenth column. 
    return t[n][Max_len]; 
} 

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int dp[size+1] = {0};
    cout<<answer(arr, size)<<endl;
    // cout<<answer3(arr, size, dp)<<endl;
    return 0;
}