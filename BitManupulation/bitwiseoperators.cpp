#include<iostream>

using namespace std;

bool isOdd(int n)
{
    if(n & 1)
        return true;
    return false;
}


int getbit(int n, int i){
    int mask = (1<<i);
    int bit = (n & mask) > 0 ?1: 0;
    return bit;
}

int setBit(int &n , int i){
    int mask = (1<<i);
    int ans = n|mask;
    return ans;
}

int clearBit(int &n, int i)
{
    int mask = ~(1<<i);
    int ans = n & mask;
    return ans;
}

void updateBit(int &n, int i, int v)

{
    int mask = ~(1<<i);
    int cleared_n = n& mask;
    n = cleared_n|(v<<i); 
}


int main()
{
    // operators 
    // &, |, ~, ^ , << , >>
    // ^ exclusive or if only one is true then return true
    // xor elminates the duplicate
    // a^b^c^a^c = b 
    // 0^ a = a
    // and or not xor left shift, right shift
    // a = a<<1  = a * 2
    // a = a<<2 = a*2*2
    // a = a<<1 = a/2
    // a = a>>2 = a/(2*2)

    // common bit operations

    // finding even and odd 

    int n = 5;
    cout<<isOdd(n)<<endl;

    // extract i-th bit
    int i = 5;
    cout<<getbit(i, 2)<<endl;

    // set i-th bit;
    cout<<setBit(n, 1)<<endl;

    // clear i-th bit
    cout<<clearBit(n, 2)<<endl;

    // update i-th bit
    updateBit(n, 1, 1);
    cout<<n<<endl;
    updateBit(n, 3, 1);
    cout<<n<<endl;

    return 0;
}