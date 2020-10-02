#include<iostream>
#include<string.h>
#define MAX 256
using namespace std;

int main()
{
    int count[MAX]={0};
    string s;
    cin>>s;
    int max =0;
    char result;
    for(int i =0;i<s.length();i++)
    {
        count[s[i]]++;
        if(max < count[s[i]])
        {
            max = count[s[i]];
            result = s[i];
        }
    }
    cout<<result;
    

    return 0;
}