#include<iostream>

using namespace std;


int answer(int n)
{
    
  
    if(n<=1)
        return 1;
    
   
    return answer(n-1) + (n-1)*answer(n-2);
    
}
int main()
{
    int n;
    cin>>n;

    cout<<answer(n)<<endl;
    return 0;
}