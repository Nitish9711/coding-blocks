#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define null NULL

bool minHeap = false;
 bool compare(int a, int b){
        
        if( minHeap)
            return 1;

        return b > a;
    }

int main()
{
   cout<<compare(12, 13)<<endl;
   
    return 0;
}