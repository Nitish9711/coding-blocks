#include<iostream>
//#include<cstring>
#include<string.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(isupper(s[i]))
        {
            cout<<"\n"<<s[i];
        }
        else
        {
            cout<<s[i];
        }
        
    }

    return 0;
}