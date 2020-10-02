#include<iostream>

using namespace std;

void replacedBits(int &n, int i, int j, int m)
{
    m = m<<i;
    int a = -1 << (j+1);
    int b = (1<<i) - 1;
    int mask = a | b;
    n = n & mask;
    n = n ^ m;

}
int main()
{
    int n, m, i, j;
    n = 15;
    i = 1;
    m = 2;
    j = 3;
    replacedBits(n, i, j, m);
    cout<<n;
    
    return 0;
}