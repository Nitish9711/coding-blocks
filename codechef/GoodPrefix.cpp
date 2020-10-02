#include<iostream>
#include<string>

using namespace std;

bool isValid(string sub, int k, int x)
{

    return true;
}

int goodPrefix(string s, int k, int x)
{
    int len = s.length();
    int ans = 0;

    int i =0;
   while(k)
   {
      string sub = s.substr(0, i);
      if(isValid(sub, k, x))
      {
          ans++;
          
      }
   }
    return ans;
}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        int k,x;
        cin>>k>>x;

        cout<<goodPrefix(s, k, x);
    }
    return 0;
}