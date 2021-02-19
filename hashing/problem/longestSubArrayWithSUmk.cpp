#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL


class node{
    public:
    bool done = false;
    int val;
    int idx;
};
int main()
{
    int n,k;
    cin>>n >> k;
    vector<int>v;
    int s = 0;
    int e =0;
    int ml = 0;
    unordered_map<int, int>m;
    int cs = 0;
    int d;

    for(int i=0;i<n;i++){
        cin>>d;
        v.push_back(d);
        cs += d;
        if(cs == k){
            ml = max(i+1, ml);
            s = 0;
            e = i;
        }
        else if(m.find(cs-k)!= m.end()){
        //    ml = max(ml, i - m[cs-k]);
            int temp = i - m[cs-k];
            if(temp >ml){
                ml = temp;
                e = i;
                s = m[cs-k]+1;
            }
        }
        else{
            m[cs] = i;
        }

    }
    cout<<ml<<endl;
    
    for(int i = s;i<=e;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}