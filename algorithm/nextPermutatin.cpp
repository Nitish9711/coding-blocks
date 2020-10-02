#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {   
        int n;
        cin>>n;
        vector<int>v(n);
        for(int j =0;j<n;j++)
            cin>>v[j];
        

        next_permutation(v.begin(), v.end());
        for(int x:v){
                cout<<x<<" ";
        }
        cout<<endl;    
    }
    return 0;
}