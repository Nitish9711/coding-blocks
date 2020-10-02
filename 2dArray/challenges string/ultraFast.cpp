#include<iostream>
#include<string.h>

using namespace std;

void ans(string a, string b)
{
    
    string c;
    for(int i=0;i<a.length();i++)
    {
        if(a[i] == b[i])
            c[i] = '0';
        else
            c[i] = '1';
    }
    for(int i=0;i<a.length();i++)
        cout<<c[i];
}

int main()
{
    int t;
    cin>>t;
    string a[t], b[t];
    for(int i=0;i<t;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<t;i++)
       { ans(a[i], b[i]);
            cout<<endl;
       }
    return 0;
}