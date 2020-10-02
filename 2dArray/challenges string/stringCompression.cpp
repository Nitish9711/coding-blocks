#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    
    cout<<s[0];
    int temp =1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i] == s[i-1])
        {
            temp++;
        }
        else
        {
            if(temp!=1)
                cout<<temp;
            
            cout<<s[i];
            temp = 1;
        }
        
    }
    cout<<temp;
    return 0;
}