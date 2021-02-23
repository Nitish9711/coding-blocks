#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

// recursive approach
int answer(string s1, string s2, int i , int j, vector<vector<int>>&dp) {
        if(i == s1.length() || j == s2.length()){
            return 0;
        }

        if(dp[i][j]!= -1){
            return dp[i][j];
        }


        if(s1[i] == s2[j])
            return dp[i][j] = 1 + answer(s1, s2, i+1, j+1,dp);

        int op1 = answer(s1, s2, i+1, j, dp);
        int op2 = answer(s1, s2, i, j+1,dp);

        return  dp[i][j] = max(op1, op2);

}


// top down
 int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        
        int** memo;
        memo = new int*[n+1];
        for(int i = 0; i <= n; i++)
            memo[i] = new int[m + 1];
        
        //upper will be 0
        for(int i = 0; i <= n; i++) {
            memo[i][0] = 0;
        }
        for(int i = 0; i <= m; i++) {
            memo[0][i] = 0;
        }
        
           
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1]) memo[i][j] = 1 + memo[i - 1][j - 1];
                else {
                    memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
                }
            }
        }
        return memo[n][m];
    }


    // bottom up
    int** memo;
    int lcs(string text1, string text2, int n, int m) {
        if(memo[n][m] != -1) return memo[n][m];
        if(n == 0 || m == 0) memo[n][m] = 0;
        else {
            if(text1[n - 1] == text2[m - 1]) memo[n][m] = 1 + lcs(text1, text2, n - 1, m - 1);
            else {
                memo[n][m] = max(lcs(text1, text2, n, m - 1), lcs(text1, text2, n - 1, m));
            }
        }
        return memo[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        
        memo = new int*[n+1];
        for(int i = 0; i <= n; i++)
            memo[i] = new int[m+1];
        
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                memo[i][j] = -1;
        
        return lcs(text1, text2, n, m);
    }

int main()
{
    string a = "ABCDGH";
    string b = "AEDFHR";
    int n1 = a.length();
    int n2 = b.length();
    vector<vector<int>>dp(n1, vector<int>(n2, -1));

    // cout<<answer(a, b,0, 0)<<endl;
    return 0;
}