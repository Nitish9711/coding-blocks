#include<iostream>

using namespace std;



int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int n,q;
        cin>>n>>q;

        int f , d;
        int ans = 0;
        int cf = 0;
        for(int i=0;i<q;i++)
        {    
            cin>>f>>d;
            ans += abs(f - cf) + abs(d - f);
            cf = d;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}