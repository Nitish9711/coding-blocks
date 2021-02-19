// Given an array arr of n length. You will be given Q queries for the array. Each query contains a number N.You have to determine whether a number exist in the array or not

// Input Format
// First line of input contains number of test cases T. First line of each case contains an integer L denoting the length of the array. The next line contains L space separated integers. The next line contains an integer Q denoting the number of queries. The next Q lines contains a number N to be searched in the array.


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class node{
    public:
    bool exist = false;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll l;
       cin>>l;
       vector<ll>ar;
       ll d;
        unordered_map<ll, node>um;
       for(ll i =0;i<l;i++){
           cin>>d;
           um[d].exist = true;
       }

        ll q;
        cin>>q;
        for(ll i =0;i<q;i++){
            cin>>d;
            if(um[d].exist == true){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}