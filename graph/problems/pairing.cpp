#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph
{
  unordered_map<int,list<int>> l;
public:
  void insert(int x,int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }
  long long int dfs1(int key,unordered_map<int,int> &m)
  {
    m[key]=1;
    long long int z=0;
    for(auto c:l[key])
    {
      if(!m.count(c))
      {
         z+=dfs1(c,m);
      }
    }
    return z+1;
  }
  long long int  dfs(int n)
  {
    unordered_map<int,int> m;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
      if(!m.count(i))
      {
        long long int e=dfs1(i,m);
        long long int y=n-e;
        cout<<y<<endl;
        sum=sum+e*y;
      }
    }
    return sum;
  }
};
int main()
{
  int x,y;
  cin>>x>>y;
  graph g;
  for(int i=0;i<y;i++)
  {
  int a,b;
  cin>>a>>b;
  g.insert(a,b);
  }
int sum= g.dfs(x);
cout<<sum/2;
return 0;
}

