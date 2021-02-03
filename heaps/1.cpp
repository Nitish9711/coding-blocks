#include <iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
#define ll long long 
#define null NULL
#define node pair<ll,ll>

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll n;
       cin>>n;
       vector<ll>ar;
       vector<vector<ll, ll>>ans;
       ll d;
       for(ll i =0;i<n;i++){
           cin>>d;
           ar.push_back(d);
       }
       bool ok  = true;

       priority_queue<node, vector<node>, greater<node>>pq;
       for(ll i =1;i<n;i++){
           pq.push(make_pair(ar[i], i));
       }

       while (!pq.empty())
       {
           node p = pq.top();
            pq.pop();
            if(p.first <= ar[0]){
                ans.push_back({p.second+1,1, p.first });
                ar[0] += p.first;
            }
            else{
                ll x = p.first - ar[0];
                if(pq.empty()){
                    ok = false;
                    break;
                }

                else{
                    node q = pq.top();
                    pq.pop();
                    ans.push_back({p.second+1,q.second+1, x});
                    ans.push_back({p.second+1, 1,ar[0]});
                    ar[0]+= ar[0];
                    q.first += x;
                    pq.push(q);

                }
            }
       }

       if (!ok) 
        {
			cout << -1 << endl;
			continue;
		}
		cout << ans.size() << endl;
		for (ll i = 0; i < ans.size(); i++) {
			cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
		}
       


    }
    return 0;
}