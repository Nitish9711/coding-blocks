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

void ReadCP()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

ll solve(vector<vector<ll>> ar, ll n, ll m, ll k){
	vector<vector<ll>> dp(n, vector<ll>(m, 0));
	ll ans =0;
	for(ll i =0;i<n;i++){
		for(ll j =0;j<m;j++){
			dp[i][j] = ar[i][j];
		}
	}
	
	for(ll i =0;i<n;i++){
		for(ll j =1;j<m;j++){
			dp[i][j] += dp[i][j-1];
		}
	}
	for(ll i =0;i<m;i++){
		for(ll j =1;j<n;j++){
			dp[j][i] += dp[j-1][i];
		}
	}
	for(ll i =0;i<n;i++){
		for(ll j =0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<endl;
	

	for(ll l = 2;l<=n;l++){
		cout<<l<<endl;
		
		for(ll i = l-1;i<n;i++){
			
			ll s = l-1, e = m-1;
			ll temp =0;
			while(s<=e){
				ll mid = (s+e)/2;
				cout<<"i "<<i<<" mid "<<mid<<" s "<<s<<" e "<<e<<endl;
				 temp = dp[i][mid];

				if(mid - l >=0 && i-l<0)
					temp = temp - dp[i][mid-l];
				
				else if(i-l >=0 && mid-l >=0)
					temp = temp -dp[i][mid-l] - dp[i-l][mid] + dp[i-l][mid-l];

				else if(i-l >=0 && mid-l<0)
					temp = temp - dp[i-l][mid];
				// else if(i-l<0 && mid-l<0)
				

				ll avg = temp/(l*l);
				cout<<"temp "<<temp<<endl;
				if(avg >k)
					e = mid-1;
				else if(avg == k)
					break;

				else if(avg <k)
					s = mid+1;
				
				
			}


			
			ans += m-s;
			cout<<"b "<<s<<" ans "<<ans <<endl;
		



		}

	}

	cout<<"ans "<<ans<<endl;

	return  ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ReadCP();
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m, k;
		cin >> n >> m >> k;

		vector<vector<ll>> ar(n, vector<ll>(m, 0));
		ll d;
		ll one = 0;
		for (ll i = 0; i < n; i++)
		{
			for (ll j = 0; j < m; j++)
			{
				cin >> d;
				ar[i][j] = d;
				if(d  >=k)
					one++;
			}
		}
		cout<<one<<endl;

		cout << solve(ar, n, m, k) + one << endl;
	}
	return 0;
}