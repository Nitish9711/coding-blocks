#include <iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long 
#define null NULL
#define node vector<pair<int, int>>

bool compare(pair<int, int>p1, pair<int, int>p2){
  
    return p1.second < p2.second;

}

int solve(node v, int n){
    int ans = 1;
    int s = v[0].first;
    int e = v[0].second;
    
    for(int i = 1;i<n;i++){
        if(v[i].first >= e){
            ans++;
            e = v[i].second;
        }
    }


    
    return ans;

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
      int n;
      cin>>n;
      node v;
     int s, f ;
      for(int i = 0;i<n;i++){
          cin>>s>>f;
          v.push_back(make_pair(s, f));
      }
      sort(v.begin(), v.end(), compare);

    cout<<solve(v, n)<<endl;
    v.clear();
        
    }
    return 0;
}