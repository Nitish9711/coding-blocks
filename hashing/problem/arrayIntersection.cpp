#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class node{
    public:
    ll cnt = 0;
    bool exist = false;
};
int main()
{
    ll n;
    cin>>n;
    vector<ll>ar;
    unordered_map<ll, node>m1;
    unordered_map<ll, node>m2;

    ll d;
    for(ll i =0;i<n;i++){
        cin>>d;
        ar.push_back(d);
        if(m1[d].exist== true){
            m1[d].cnt++;
            
        }
        else{
        m1[d].exist = true;
        m1[d].cnt++;
        }
    }

    for(ll i = 0;i<n;i++){
        cin>>d;
         if(m2[d].exist == true){
            m2[d].cnt++;
            
        }
        else{
        m2[d].exist = true;
        m2[d].cnt++;
        }
    }
    vector<ll>out;
    for(ll i =0;i<n;i++){
        node n1 = m1[ar[i]];
        node n2 = m2[ar[i]];
        if(n1.exist == true && n2.exist == true && n1.cnt != 0 && n2.cnt != 0){
            m1[ar[i]].exist = false;
            m2[ar[i]].exist = false;
            ll count = min(n1.cnt , n2.cnt);
            while(count--){
                out.push_back(ar[i]);
            }
            

        }
       
    }
    cout<<"[";
    for(ll i =0;i<out.size();i++){
        cout<<ar[i];
        if(i!= out.size()-1)
            cout<<", ";
    }
    cout<<"]";

    return 0;
}