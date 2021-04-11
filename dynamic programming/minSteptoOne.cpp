#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

// topDown
int minStep(int n, vector<int>dp)
{
    if (n == 1)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if (n % 3 == 0)
    {
        op1 = minStep(n / 3, dp) + 1;
    }
    if (n % 2 == 0)
    {
        op2 = minStep(n / 2, dp) + 1;
    }

    op3 = minStep(n - 1, dp) + 1;
    int ans = min(min(op1, op2), op3);
    return dp[n] = ans;
}

// bottom up
int minStepbu(int n)
{
    int dp[100] = {0};
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        if (n % 3 == 0)
        {
            op1 = dp[i / 3];
        }
        if (n % 2 == 0)
        {
            op2 = dp[i / 2];
        }
        op3 = dp[i - 1];
        dp[i] = min(min(op1, op2), op3) + 1;
    }

    return dp[n];
}

 

int main()
{

    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int>dp(n+1, 0);
        cout <<"case "<<i<<": "<< minStepbu(n) << endl;
        i++;
    }

    return 0;
}