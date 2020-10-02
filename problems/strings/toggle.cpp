#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

int main()
{
    string input;
    cin>>input;
    int len = input.length();

    for(int i=0;i<len;i++)
    {
        if(isupper(input[i]))
            input[i] = ::tolower(input[i]);
        else if(islower(input[i]))
            input[i] = ::toupper(input[i]);
    }

    cout<<input;
    return 0;
}