#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>
#define mod 1000000007
void ReadCP()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class Graph
{
	ll n;
	vector<ll> *adj;
	ll *count1;
	ll x;

public:
	Graph(ll N, ll X)
	{
		this->n = N;
		adj = new vector<ll>[N];
		count1 = new ll[N];
		this->x = X;
	}

	void addEdge(int a, int b)
	{
		adj[a].push_back(b);
		// adj[b].push_back(a);
	}

	// void printNumberOfNodes()
	// {
	// 	for (int i = 1; i <n; i++)
	// 	{
	// 		cout << "\nNodes in subtree of " << i;
	// 		cout << ": " << count1[i];
	// 	}
	// }

	void decrease(){
		for(int i=1;i<n;i++){
			count1[i]--;
		}
	}

	void numberOfNodes(ll s, ll e)
	{
		vector<ll>::iterator u;
		count1[s] = 1;
		for (u = adj[s].begin(); u != adj[s].end(); u++)
		{

			if (*u == e)
				continue;

			numberOfNodes(*u, s);

			count1[s] += count1[*u];
		}
	}


	void solve(){
		ll sum =0;
		// cout<<sum<<endl;
		queue<ll>q;
		vector<bool>visited(n, false); 
		q.push(1);
		vector<ll>val(n);
		val[1] = x;
		while(!q.empty()){
			auto p = q.front();
			q.pop();     
			// cout<<"p "<<p<<endl;
			vector<pair<ll, ll>>temp;
			// temp.push_back({0, 0});
			for(ll i =0;i<adj[p].size();i++)
			{
				temp.push_back({ count1[adj[p][i]],adj[p][i]});
			}
			sort(temp.begin(), temp.end());
			// for(ll i =temp.size()-1;i>=0;i--){
			// 	cout<<"( "<<temp[i].first<<", "<<temp[i].second<<")";
			// }
			// cout<<endl;
			ll temp2 = val[p];
			ll j = 1;
			for(ll i =temp.size()-1;i>=0;i--){
				if(!visited[temp[i].second]){
					q.push(temp[i].second);
					 val[temp[i].second] = val[p]*j;
					j++;
					visited[temp[i].second]= true;
				}
			}
			
			

			
		}

		for(int i=1;i<n;i++){
			sum+= val[i];
			sum = sum%mod;
			sum += mod;
			sum = sum%mod;
		}
		// return sum;
		cout<<sum<<endl;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ReadCP();
	int T;
	cin >> T;
	while (T--)
	{
		ll n, x;
		cin >> n >> x;
		Graph g(n+1,x);
		for (ll i = 1; i <= n - 1; i++)
		{
			ll x;
			ll y;
			cin >> x >> y;
			g.addEdge(x, y);
			
		}
	    g.numberOfNodes(1, 0);
		g.decrease();
		// g.printNumberOfNodes();
		// g.printNumberOfcount();
		// cout<<endl;
		g.solve();


	}
	return 0;
}