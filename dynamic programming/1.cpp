#include <iostream>
#include<vector>
#include<utility>
using namespace std;
#define ll long long 
#define null NULL

int answer(string a, string b, int m, int n){
    int dp[m+1][n+1];

    for(int i =0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] =0;
            }
            else if(a[i-1]== b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            }
        }
    }


}




int main()
{
    string a, b;
    cin>>a>>b;
    int n1 = a.length();
    int n2 = b.length();
    vector<vector<int>>dp(n1, vector<int>(n2, -1));

    
    return 0;
}