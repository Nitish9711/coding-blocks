#include<iostream>
#include<cstring>
using namespace std;

string s2 = "";


void convert (int i, string str, int n)
{
    if(i== n)
        return;

    s2 += str[i];

    if(str[i] == str[i+1] && i!= n-1)
        s2 += "*";
    
    convert(i+1, str, n);
}

int main()
{
    string str;
    cin>>str;

    convert(0, str, str.length());
    cout<<s2;
    
    return 0;
}