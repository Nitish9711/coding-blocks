#define pis pair<int, string>
#define vp vector<pair<int, int>>

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
		adj[b].push_back(a);
	}

	void printNumberOfNodes()
	{
		for (int i = 1; i <n; i++)
		{
			cout << "\nNodes in subtree of " << i;
			cout << ": " << count1[i];
		}
	}
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

	bool comp(pair<ll, ll> a, pair<ll, ll>b){
		if(b.first > a.first)