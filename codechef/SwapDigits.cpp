#include<iostream>

using namespace std;

int swapDigit(int a,int b)
{
    int cs;
    int ms = a+b;

    int q1 = a/10;
    int q2 = b/10;
    int r1 = a%10;
    int r2 = b%10;

    cs = (q1*10)+r2+(q2*10)+r1;
    ms = max(cs, ms);


    cs = (r2*10) + r1 +(q2*10) + q1;
    ms = max(cs, ms);

    cs = (q1*10) + q2 + (r1*10) + r2;
    ms = max(cs, ms);

    cs = (q2*10) + r1 +(q1*10) + r2;
    ms = max(cs, ms);
    
    return ms;
}

int main()
{
    int t;
    cin>>t;
    
    int a[t];
    int b[t];

    for(int i= 0;i<t;i++)
    {
        cin>>a[i]>>b[i];
        cout<<swapDigit(a[i], b[i])<<endl;
    }
    return 0;
}