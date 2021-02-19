// LOngest consecutive subsequence


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

int main()
{
    int n;
    cin>>n;

     vector<int>ar;
    unordered_map<int, int>m;
    int cs = 0;

    for(int i=0;i<n;i++){
        cin>>cs;
        ar.push_back(cs);
        m[cs] = i;
    }

    int ml  = 0;
    for(int i =0;i<n;i++){

        if(m.find(ar[i]-1) == m.end()){
            int count = 0;
            int j = ar[i]+1;
            while(m.find(j) != m.end()){
                count++;
                j++;
            }
            ml = max(count+1, ml);
        }
    }
   
   cout<<ml<<endl;
    return 0;
}