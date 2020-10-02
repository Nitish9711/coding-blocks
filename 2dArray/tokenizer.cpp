#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;

int main()
{
    char str[] = {"Hi, my name is Nitish"};
    char * ptr;

    ptr = strtok(str, " ");//strtok is a static variable which stores the state the state of string in the previous function call
    //cout<<ptr<<endl;

    while(ptr!= NULL)
    {
        cout<<ptr;
        ptr = strtok(NULL, " ");//NULL parameter signifies extract string from the original state
    }



    return 0;
}