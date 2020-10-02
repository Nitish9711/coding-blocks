#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

int main()
{
    string input;
    cin>>input;
    int len = input.length();

    int temp = 0;
    for(int i=0;i<len/2;i++)
    {
       if(input[i] != input[len-i-1])
        {
            temp++;
            break;
        }
    }
    if(temp == 0)
        cout<<"true";
    else
        cout<<"false";

    
    return 0;
}