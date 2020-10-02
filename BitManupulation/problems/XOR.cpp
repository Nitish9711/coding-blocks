#include<iostream>

using namespace std;

int solution(int L, int R) 
{ 
    // get xor of limits 
    int LXR = L ^ R; 
  
    //  loop to get msb position of L^R 
    int msbPos = 0; 
    while (LXR) 
    { 
        msbPos++; 
        LXR >>= 1; 
    } 
    cout<<msbPos<<endl;
    // construct result by adding 1, 
    // msbPos times 
    int maxXOR = 0; 
    int two = 1; 
    while (msbPos--) 
    { 
        maxXOR += two; 
        two <<= 1; 
        
    } 
  
    return maxXOR; 
} 
int main()
{
    int x, y;
    cin>>x>>y;

    cout<<solution(x, y)<<endl;
    return 0;
}