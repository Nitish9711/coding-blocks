#include<iostream>

using namespace std;


int answer(int n)
{
    if(n<=3)
        return 1;
    
    return answer(n-1) + answer(n-4);
    
}
int main()
{
    int n;
    cin>>n;

    cout<<answer(n)<<endl;
    return 0;
}