#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL


bool check(string s, int i  , int j, int n){
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       string s;
       cin>>s;
       int n = s.length();

       for(int i =0;i<n;i++){
           for(int j = i+1; j<n;j++){
               bool isPalin = check(s, i, j, n);
               if(isPalin){
                   
               }
           }
       }

    }
    return 0;
}