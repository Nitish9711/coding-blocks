#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

class fun{
    public:
        void operator() (string s){
            cout<<"heaving fun inside operator() "<<s;
        }
};

int main()
{

    fun f; 
    f("c++"); // functor since it is an object but behaving like a function    
    return 0;
}