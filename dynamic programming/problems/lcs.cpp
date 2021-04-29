#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string LCSrecursion(string a, string b){
           int m = a.length();
    int n = b.length();
    int dp[m+1][n+1];
    for(int i =0;i<=m;i++){
        for(int j =0;j<=n;j++){
            if(i==0 || j== 0)
                dp[i][j] = 0;

            else if(a[i-1] == b[j-1])
                dp[i][j] =1+ dp[i-1][j-1];

            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans = "";

    int index = dp[m][n];

    int i = m, j =n;
    while(i> 0 && j>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else 
            j--;
    }

    // cout<<ans<<endl;
    return ans;


}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
   string a, b;
   cin>>a>>b;


   string ans = LCSrecursion(a, b);
//    for(int i=ans.length()-1;i>=0;i--){
//        cout<<ans[i];
//    }
reverse(ans.begin(), ans.end());
cout<<ans<<endl;
    return 0;
}