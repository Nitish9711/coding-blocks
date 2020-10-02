#include<iostream>

using namespace std;

int main()
{
    int q;
    cin>>q;
    int temp;

    int ans = 0;
    for(int i=0;i<q;i++)
    {
        cin>>temp;
        ans = ans ^ temp;
    }
    cout<<ans<<endl;
    return 0;
}