#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    v.reserve(100);

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    v.pop_back();
    sort(v.begin(),v.end());
    cout<<v.capacity()<<endl;


    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<v.max_size()<<endl;
   return 0;
}