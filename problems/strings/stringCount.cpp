#include<iostream>
#include<string>

using namespace std;

bool Ispalindrome(string s)
{
    if(s.length()==1)
        return true;
    else
    {
        int len = s.length();
        for(int i=0;i<len/2;i++)
            {
                if(s[i]!= s[len-i-1])
                    return false;
            }
    }
    return true;
}


int main()
{
    string s;
    
    getline(cin, s);
    int len = s.length();
    int ans =0;
    for(int i=0;i<len;i++)
    {
        for(int j=1;j<=(len-i);j++)
           {
                if(Ispalindrome(s.substr(i, j)))
                    ans++;

           }
    }
    cout<<ans;
    return 0;
}