// array containse a sub array whose sum is 0 or not

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class node{
    public:
    int a = 0;
    bool b = false;

};



int main()
{
    
    vector<int>ar;
   vector<int>cm;
    int ml  = 0;
    unordered_map<int, node>m;
    int cs = 0;
    for(int i =0;i<ar.size();i++){
        cs += ar[i];
        cm.push_back(cs);
        if(cs == 0){
            m[cs].b = true;
            m[cs].a = i;
            ml = max(ml, i+1);
        }
        else if(m[cs].b == true){
          ml = max(ml, abs(m[cs].a- i));
        //   break;
      }
       else{ 
           m[cs].b = true;
           m[cs].a = i;
       }
    }
    cout<<ml<<endl;
    return 0;
}