#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int different(vector<char>a, vector<char>b){
    unordered_set<char>us;
    for(auto x: a){
        us.insert(x);
    }
    for(auto x: b){
         us.insert(x);
    }
    return us.size();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int n;
       cin>>n;
       int ans = 0;
       unordered_map<string, vector<char>>um;
       unordered_set<string>v;
        string str;
        for(int i =0;i<n;i++){
         cin>>str;
            string s = str.substr(1);
            um[s].push_back(str[0]);
            v.insert(s);
         }

         for(auto x =v.begin();x!= v.end();x++){
             auto y  = x;
             ++y;
			for(;y != v.end();y++){
                int temp = different(um[*x], um[*y]);
                ans += (temp - um[*x].size()) * (temp - um[*y].size());
            }
			 
         }
         cout<<ans*2<<endl;
    }
    return 0;
}