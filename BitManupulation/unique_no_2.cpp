#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *ar  = new int[n];

    int no;
    int Xor = 0;
    for(int i=0;i<n;i++)
    {  
        cin>>ar[i];
        Xor = Xor ^ ar[i];
    }

    int temp = Xor;
    int pos = 0;
    while((temp & 1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }

    // the first set bit in Xor is at pos;
    int mask  = 1<<pos;
    //  find those number which contain set bit at position pos

    int x = 0;
    int y =0;
    for(int i=0;i<n;i++)
    {
        if((ar[i]& mask) > 0)
            x = x ^ ar[i];
    }

    y = Xor ^ x;
    cout<<min(x, y)<<" "<<max(x, y)<<endl;
    
    return 0;
}