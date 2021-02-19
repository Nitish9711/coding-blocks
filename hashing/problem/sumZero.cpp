// array containse a sub array whose sum is 0 or not

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL



int main()
{
    
    vector<int> ar{6, -1, 2, -1, 2, -1};
    vector<int>cm;
    unordered_map<int, bool>m;
    int cs = 0;
    for(int i =0;i<ar.size();i++){
        cs += ar[i];
        cm.push_back(cs);
         if(m[cs] == true || cs == 0 ){
          cout<<" zero sum"<<endl;

          break;
      }
       else{ m[cs] = true;
       }
    }

    return 0;
}