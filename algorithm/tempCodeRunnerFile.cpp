#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int activitySelection(vector<pair<int, int>>v, int n)
{
    

    int ms  = 1;
    for(int i =0;i<n;i++)
    {
        int cs = 1;
        for(int j=0;j<n;j++)
        {
            if(v[i].second == v[j].second && v[i].first == v[j].first)
                continue;
            else if((v[j].second<=v[i].first) ||(v[j].first>=v[i].second))
            {
                
                cs++;
                ms = max(ms, cs);
                v[i].second = v[j].second;
            }
        }
                cout<<i<<"   "<<cs<<endl;
    }
    return ms;
}

int main()
{
    int t;
    cin>>t;


    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>v(n);
        for(int i =0;i<n;i++)
          cin>>v[i].first>>v[i].second;
        
        // sort(v.begin(), v.end()+1)
        // cout<<activitySelection(v, n)<<endl;
        cout<<activitySelection(v,n)<<endl;
    }
    return 0;
}