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
#define vp vector<pair<int, in#include <bits/stdc++.h>
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

int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 

   return K[n][W]; 
}

int knapsack(int n, int s, vector<int>wt, vector<int>p){

    vector<vector<int>>dp(n+1, vector<int>(s+1, 0));


    for(int i = 1;i<=n;i++){

        for(int w = 1;w<=s;w++){
            if(wt[i-1] <= w)
            dp[i][w] =  max(dp[i-1][w], dp[i-1][w-wt[i-1]]+ p[i-1]);

            else
                dp[i][w] = dp[i-1][w];
        }

    }


    
    return dp[n][s];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    int n, s;
    cin>>n>>s;

    vector<int>wt;
    vector<int>p;

        int d;
    for(int i=0;i<n;i++){
        cin>>d;
        wt.push_back(d);
    }
    for(int i=0;i<n;i++){
        cin>>d;
        p.push_back(d);
    }
    cout<<knapsack(n, s, wt, p)<<endl;


        
    
    return 0;
}

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}