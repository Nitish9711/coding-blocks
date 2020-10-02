#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int k;
    cin>>k;
    string a;
    cin>>a;
    int left=0, ans=0;
    int count[2] ={0,0};
    for(int i=0;i<a.length();i++)
    {
        count[a[i]-'a'];
        if(min(count[0], count[1]) > k)
        {
            count[a[left]- 'a']--;
            left++;
        }
        else
        {
            ans++;
        }
        
    }
    return 0;
}