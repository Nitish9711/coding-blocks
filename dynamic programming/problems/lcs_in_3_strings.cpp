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

int lcs(string a, string b, string c){
    
    int l = a.length(),m =  b.length(), n = c.length();

    int ar[l+1][m+1][n+1];

    for(int i =0;i<=l;i++){

        for(int j=0;j<=m;j++){
            for(int k =0;k<=n;k++){

                if(i == 0 || j== 0 || k == 0)
                    ar[i][j][k] = 0;

                else if(a[i-1] == b[j-1]&& a[i-1]== c[k-1])
                    ar[i][j][k] = 1+ ar[i-1][j-1][k-1];


                else 
                    ar[i][j][k] = max(max(ar[i-1][j][k], ar[i][j-1][k]), ar[i][j][k-1]);



            }
        }
    }


    return ar[l][m][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ReadCP();
    string a, b, c;
    cin>>a>>b>>c;


    cout<<lcs(a, b, c)<<endl;
    return 0;
}