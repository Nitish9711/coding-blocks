#include<iostream>
#include<algorithm>
using namespace std;

//input
// 1 3 4 2 7 8
// output -  8 1 7 2 4 3

int main()
{
    int ar[] ={1,3,4,2,7,8};
    int len = sizeof(ar)/sizeof(ar[0]);
    
    for(int i=0;i<len;i=i+2)
    {
        if(i!=0 && ar[i] < ar[i-1])
            swap(ar[i], ar[i-1]);  
        if(ar[i] < ar[i+1] && i!= (len-1))
            swap(ar[i], ar[i+1]);  

    }

    for(auto x:ar)
        cout<<x<<" ";
    return 0;
}