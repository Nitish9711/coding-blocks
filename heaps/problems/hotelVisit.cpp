#include <iostream>
#include<queue>
#include<utility>
using namespace std;
#define ll long long 
#define null NULL



int main()
{
    int t, k;
    cin>>t>>k;

    priority_queue<ll>pq;
    while( t--){
        int type;

        cin>>type;
        if(type == 1){
            ll x, y;
            cin>>x>>y;
            ll distance = x*x + y*y;

            if(pq.size() < k){
                pq.push(distance);
            }
            else if(pq.top()> distance){
                pq.pop();
                pq.push(distance);
            }
        }   
        else{
            cout<<pq.top()<<endl;
        }
                


    }
    
    return 0;
}