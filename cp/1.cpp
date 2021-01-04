#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

bool sortcol(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1[1] > v2[1];
}

bool isPowerOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}
bool findPair(vector<pair<int, int>>p, int i , int j){

    for(int i =0 ;i<p.size();i++){
        // cout<<i<<" "<<j<<" "<<p[i].first<<" "<<p[i].second<<" "<<endl;
        if((p[i].first == i && p[i].second ==  j) || (p[i].first == j && p[i].second == i)){
            
            return true;
        }
    }
    return false;
}
int main()
{
    int m = 1000000007;
    vector<int> deliciousness{1, 3, 5, 7,9};
    vector<pair<int, int>>p;
    int n = deliciousness.size();
    int ans = 0;

    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if( i == j){
                continue;
            }
            else{
                if(findPair(p, i , j)){
                    continue;
                }
                else{
                    if(isPowerOfTwo(deliciousness[i]  + deliciousness[j])){
                    p.push_back(make_pair(i, j));
                    cout<<i<<" "<<j<<endl;
                    p.push_back(make_pair(j, i));
                    // cout<<j<<" "<<i<<endl;
                    ans++;
                    ans = ans%m;
                    }
                }
            }
        }
    }

cout << ans << endl;
    // for(int i =0;i<p.size();i++){
    //     cout<<p[i].first<<" "<<p[i].second<<endl;
    // }
   

    

    return 0;
}