// We can also solve this problem in bottom-up manner. In the bottom-up approach, we solve smaller sub-problems first, then solve larger sub-problems from them. The following bottom-up approach computes , for each and , which is true if subset with sum j can be found using items up to first i items. It uses value of smaller values i and j already computed. It has the same asymptotic run-time as Memoization but no recursion overhead.


#include <iostream>
using namespace std;

bool subsetSum(int *arr, int n, int target) {
    bool **dp = new bool*[n+1];
    for(int i=0;i<=n;i++) {
        dp[i] = new bool[target+1];
    }
    dp[0][0] = true; // If sum is zero and no element is taken ans is true
    for(int i=1;i<=n;i++) { // If sum is zero ans is always true
        dp[i][0] = true;
    }
    for(int i=1;i<=target;i++) { // If no element is chosen and sum is not zero ans is false
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=target;j++) {
            if(j<arr[i-1]) {
                dp[i][j] = dp[i-1][j];
            } 
            if(j>=arr[i-1]) {
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][target];

}

int main(int argc, char const *argv[])
{
    int n, target;
    cin>>n>>target;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    if(subsetSum(arr, n, target)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
