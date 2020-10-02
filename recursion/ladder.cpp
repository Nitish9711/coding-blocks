#include<iostream>

using namespace std;


int answer(int n)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    
    
    return answer(n-1) + answer(n-2)+answer(n-3);
    
}
int main()
{
    int n;
    cin>>n;

    cout<<answer(n)<<endl;
    return 0;
}