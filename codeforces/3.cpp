#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

bool check(string s, string p, int n){
    if(s == p)
        return true;
    
    int s_ones =0;
    int p_ones =0;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            s_ones++;
        }
        if(p[i] == '1'){
            p_ones++;
        }
    }
    if(s_ones != p_ones)
        return false;
    
    return true;
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int n;
       cin>>n;
       string s,p;
       cin>>s>>p;
       if(check(s, p, n)){
           cout<<"Yes"<<endl;
       }
       else
       {
           cout<<"No"<<endl;
       }
       
    }
    return 0;
}