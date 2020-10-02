#include<iostream>
#include<string.h>
using namespace std;

void filterChars(int n, char a[])
{
    int j =0;
    while (n > 0)
    {
        int last_bit = n & 1;
        if(last_bit)
        {
            cout<<a[j];
        }
        j++;
        n = n>>1;
    }
    cout<<endl;
}
int main()
{   
    char a[100];
    cin>>a;

    int n = strlen(a);
    for(int i=1;i< (1<<n); i++)
    {
        
        filterChars(i, a);
    }
    return 0;
}