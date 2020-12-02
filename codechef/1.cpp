#include<iostream>
#include<vector>
using namespace std;
#define ll long int

int main(){
  int t;
  cin>>t;

  while(t--){
    ll n, m;
    cin>>n>>m;
    ll *ar = new ll[n];
    ll sum = 0;
    for(ll i =0;i<n;i++)
    {
        cin>>ar[i];
        sum+= ar[i];
    }
    if(sum == m)
      cout<<"YES"<<endl;
    else
    {
      cout<<"NO"<<endl;
    }
    
    
    

    

  }
  return 0;
}