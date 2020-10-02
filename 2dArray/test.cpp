#include <iostream>
#include<string>
#include<string.h>
using namespace std;
int main() {
       string s = "hello my name is nitish";
       char a[]={} ;
       strcpy(a, s.c_str());
       cout<<a;
        
    return 0;
}
