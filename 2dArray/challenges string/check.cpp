#include<iostream>


using namespace std;

int main()
{

    char a;
    a = getchar();
    if(a>='a'&& a<='z')
        cout<<"lowercase";
    else if(a>='A'&& a<='Z')
        cout<<"UPPERCASE";
    else
        cout<<"Invalid";
    
    return 0;
}