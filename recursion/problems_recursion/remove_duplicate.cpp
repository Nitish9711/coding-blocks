#include<iostream>
#include<cstring>
using namespace std;

string s2 = "";


void duplicate_remove (int i, string str, int n)
{
    if(i == n)
        return;

    s2 += str[i];
    if(str[i]== str[i+1] && i!= n-1)
    {   
        s2.pop_back();
    }
    
    duplicate_remove(i+1, str, n);
}

int main()
{
    string str;
    cin>>str;

    duplicate_remove(0, str, str.length());
    cout<<s2;
    
    return 0;
}