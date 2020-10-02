#include<iostream>

using namespace std;
#define MAX 30000
int multiply(int x, int a[] , int res_size);
void fact (int a)
{
    int res[MAX];
    res[0] = 1;
    int res_size =1;

    for(int x =2;x<a;x++)
    {
        res_size = multiply(x, res, res_size);
    }
    for(int i = res_size-1; i>=0;i--)
        cout<<res[i];

}

int multiply(int x, int res[], int res_size)
{
    int carry =0;
    for(int i=0;i<res_size;i++)
    {
        int prod = res[i] * x + carry;
        carry = prod/10;
        res[i] = prod%10;
    }

    while(carry)
    {
        res[res_size] = carry%10;
        carry  = carry/10;
        res_size++;
    }
    return res_size;
}

int main()
{
    int a;
    cin>>a;
    fact(a);

    return 0;
}