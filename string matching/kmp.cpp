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
vector<int>computeLPSArray(string pat){
    int n= pat.length();
    vector<int>lps(n);
    lps[0] = 0;
    int i =1;
    int j =0;
    while(i<n){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j == 0){
                lps[i] = 0;
                i++;
            }
            else{
                j =lps[j-1];
            }
        }
    }
    return lps;
}

void KMPSearch (string s, string pat){
    int m = pat.length();
    int n = s.length();

    vector<int>lps = computeLPSArray(pat);
    // for(auto x: lps)
    //     cout<<x<<" ";

    int i =0;
    int j =0;
    while(i<n){
        if(pat[j] == s[i]){
            j++;
            i++;
        }
        if(j == m){
            cout<<"patter found at "<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i<n && pat[j]!= s[i]){
            if(j!= 0)
                j = lps[j-1];
            else 
                i = i+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
   
    // vector<int>ar = computeLPSArray(pat);
    // for(auto x: ar)
    //     cout<<x<<" ";
    // string s;
    // cin>>s;
     string pat;
    cin>>pat;
     vector<int>ar = computeLPSArray(pat);
    for(auto x: ar)
        cout<<x<<" ";
    // KMPSearch(s, pat);

    
    return 0;
}