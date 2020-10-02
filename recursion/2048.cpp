#include<iostream>

using namespace std;

char words[][10] = {"zero", "one", " two", "three", "four", "five", "six", "seven", "eight","nine"};
void number(int n)
{
    if(n==0)
        return ;

    number(n/10);

    int digit = n%10;
    cout<<words[digit]<<" ";

}



int main()
{
    int n;
    cin>>n;

    number(n);
    return 0;
}