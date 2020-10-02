#include <iostream> 
#include<unordered_set>
using namespace std;

#define ll long int

bool answer(int n, int k, int x, int y)
{
  unordered_set<int>s;
  int c_city = x;
  s.insert(x);
  if( x==y)
    return true;
  
  while(1){
    c_city = (x+k)%n;
    x = (x+k)%n;
    if(c_city == y){
      return true;
    }
     
    if(s.find(c_city) == s.end()){
      s.insert(c_city);
    }
    else
    {
      return false;
      break;
    }
    // unordered_set<int> :: iterator itr;
    // for (itr = s.begin(); itr != s.end(); itr++) 
    //     cout << (*itr) << " ";
    
  }
  return true;

}

int main()

{
    ll t;
    cin>>t;

   
    while(t--)
    {
      int n, k, x, y;
      cin>>n>>k>>x>>y;


      if(answer(n, k, x, y))
        cout<<"YES"<<endl;

      else
        cout<<"NO"<<endl;   
    }

        
        
    
    return 0;
}