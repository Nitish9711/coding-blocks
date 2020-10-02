#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


vector<vector<int>> ans;
set<vector<int>> mp;
int b;

void solve(vector<int> &a, int i , int req, vector<int>st)
{
    if(i>a.size() || req<0)
        return;
    
    if(req == 0)
    {
        if(!st.empty() && mp.find(st) == mp.end())
        {
            mp.insert(st);
            ans.push_back(st);
        }
    }
    if(i == a.size())
        return;
    
    st.push_back(a[i]);
    solve(a, i+1, req-a[i], st);
    st.pop_back();

    solve(a, i+1, req, st);

    vector<int> s2;
    s2.push_back(a[i]);
    solve(a, i+2, b-a[i], s2);

}
vector<vector<int>> combinationSum(vector<int> & a, int b)
{
    ans.clear();
    mp.clear();
    ::b = b;
    if(a.size() == 0 || b==0)
        return ans;
    
    sort(a.begin(), a.end());
    vector<int> st;
    solve(a, 0, b, st);
    sort(ans.begin(), ans.end());
    return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<int>ar(n);
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    int t;
    cin>>t;

    vector<vector<int>> ans = combinationSum(ar, t);
    for(auto vec: ans)
        {
            for(int num:vec)
            {
                cout<<num<<" ";
            }
            cout<<endl;
        }
    return 0;
}