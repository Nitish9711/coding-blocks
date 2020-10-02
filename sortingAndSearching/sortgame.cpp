#include <iostream>
#include<algorithm>
using namespace std;


bool compare(pair<string, int>p, pair<string, int>q)
{
    if(p.second == q.second)
        return (p.first < q.first);
    
    return (q.second < p.second);
}

int main()
{
    int x;
    cin>>x;

    int n;
    cin>>n;

    pair<string, int>p[n];

    
    for(int i =0;i<n;i++)
        cin>>p[i].first>>p[i].second;

    
    sort(p, p+n, compare);
   
    for(int i=0;i<n;i++)
    {    if(p[i].second < x)
            continue;
        else
            cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    return 0;
}