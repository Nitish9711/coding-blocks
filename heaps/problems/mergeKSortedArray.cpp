#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL
#define node pair<ll, pair<ll, ll>> 


void mergeArray(vector<vector<ll>>v, ll n,ll k){

    vector<ll>result;

    priority_queue<node, vector<node>, greater<node>>pq;
    for(ll i =0;i<v.size();i++){
        node p = make_pair(v[i][0] , make_pair(i, 0));
        pq.push(p);
    }

    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        ll ele = current.first;
        ll x = current.second.first;
        ll y = current.second.second;

        result.push_back(ele);

        if(y+1 < v[x].size()){
            node p = make_pair(v[x][y+1], make_pair(x, y+1));
            pq.push(p);
        }

    }
    



     for(int x: result){
         cout<<x<<" ";
     }


}
int main()
{
    int k,n;
    cin>>k>>n;
    vector<vector<ll>>arr(k,vector<ll>(n));//Storing k sorted arrays in a 2d vector
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }

    // cout<<" ds"<<endl;

    mergeArray(arr, n, k);
   
    return 0;
}