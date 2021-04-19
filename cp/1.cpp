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
#define vpi vector<pi>
#define vpl vector<pl>
#define endl "\n"


void ReadCP()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


ll subarray(vl dif, ll n)
{
  
    ll ans = 1, temp = 1;
  
    // Traverse the array
    for (ll i = 1; i < n; i++) {
  
        // If elemet is same as
        // previous increment temp value
        if (dif[i] == dif[i - 1]) {
            ++temp;
        }
        else {
            ans = max(ans, temp);
            temp = 1;
        }
    }
    ans = max(ans, temp);
  
    // Return the required answer
    return ans;
}


ll solve(vl ar, ll n){
	ll start = 0, end = 0;

	ll i =0;
	vl dif(n, 0);
	for(ll i =1;i<n;i++){
		dif[i] = abs(ar[i]-ar[i-1]);
	}

	for(ll i =0;i<n;i++){
		cout<<dif[i]<<" ";
	}
	cout<<endl;

	ll ans = subarray(dif, n);

	return ans;




}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ReadCP();
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		ll n;
		cin>>n;
		vl ar;
		ll d;
		for(ll j =0;j<n;j++){
			cin>>d;
			ar.push_back(d);
		}

		cout << "Case #" << i << ": "<<solve(ar, n)<<endl;
	}
	return 0;
}