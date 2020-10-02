#include<iostream>
#include<string.h>
using namespace std;
bool check(string s)
{
    int low =0;
    int high = s.length()-1;
    while(low<high)
    {
        if(s[low]!=s[high])
            return false;
        low++;
        high--;
    }


    return true;
}


int main()
{
    string s;
    cin>>s;

    int q;
    cin>>q;

    
    for(int i=0;i<q;i++)
    {
        int a, b;
        cin>>a;
        cin>>b;
        char ch;
        cin>>ch;
        s[a] = ch;
        s[b] = ch;
        if(check(s))
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }
    return 0;
}