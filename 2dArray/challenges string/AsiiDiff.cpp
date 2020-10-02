#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int size = str.length();
    vector<int>diff(str.length());
    for(int i =1;i<str.length();i++)
    {
        diff[i] = (int)str[i] - (int)str[i-1];
    }
    for(int i=0;i<((2*size)-1);i++)
    {
        if(i%2 == 0)
            cout<<str[i/2];
        else
            cout<<diff[(i/2)+1];        
    }
    

    
    return 0;
}