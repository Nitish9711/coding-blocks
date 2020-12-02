#include <iostream>
#include <math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    vector<int>ar(n);
    for(auto &it: ar)
      cin>>it;
    
    while (ar.back() == 0)
    {
      ar.pop_back();
    }
    reverse(ar.begin(), ar.end());
    while (ar.back()==0)
    {
      ar.pop_back();
    }

    cout<<count(ar.begin(), ar.end(), 0)<<endl;
    

    
  }
  return 0;
}