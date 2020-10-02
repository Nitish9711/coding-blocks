#include<iostream>
#include<cstring>
using namespace std;
#define ll long long int



ll convert (string str, int n)
{
    if(n== 0)
        return 0;

    int digit = str[n-1] - '0'; 
    ll smallans = convert(str, n-1);

    return smallans*10 + digit;

}

int main()
{
    string str;
    cin>>str;

    cout<<convert(str, str.length());
    
    return 0;
}