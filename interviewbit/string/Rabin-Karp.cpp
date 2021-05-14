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
#define d 256 
void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// Rabin-Karp algorithm is O(n+m),
//  but its worst-case time is O(nm). 
// Worst case of Rabin-Karp algorithm occurs when all characters of pattern and 
// text are same as the hash values of all the substrings of txt[] match with hash 
// value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.
// prime number to be used for hashing

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

void search(char pat[], char txt[], int q) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0; 
    int t = 0;
    int h = 1; 
    for (i = 0; i < M - 1; i++) 
        h = (h * d) % q; 

    for (i = 0; i < M; i++) 
    { 
        p = (d * p + pat[i]) % q; 
        t = (d * t + txt[i]) % q; 
    } 
 
    for (i = 0; i <= N - M; i++) 
    { 
        if ( p == t ) 
        { 
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
  
            if (j == M) 
                cout<<"Pattern found at index "<< i<<endl; 
        } 
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
            if (t < 0) 
            t = (t + q); 
        } 
    } 
} 
  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
     string s;
    getline(cin, s);
     string pat;
    cin>>pat;
    vector<int>ar = rabin_karp(s, pat);
    for(auto x: ar)
        cout<<x<<" ";
    return 0;
}