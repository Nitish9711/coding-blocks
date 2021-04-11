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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ReadCP();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int d;
		int fre[101]={0};
		string ar[400];
		int ans = 0;
		pi p1, p2;
		int x1, x2, y1, y2;
		int cnt = 0;
		for(int i =0;i<n;i++){
			cin>>ar[i];
			// cout<<ar[i]<<endl;
			for(int j = 0;j<n;j++){
				// cin>>ar[i][j];
				if(ar[i][j] == '*'){
					cnt++;
					if(cnt == 1){
						x1 = i;
						y1 = j;
					}
					else{
						x2  = i;
						y2  = j;
					}

				}

			}
		}

		if(y2 == y1){
			if(y1+1<n){
				ar[x1][y1+1]='*';
				ar[x2][y1+1] = '*';
			}
			else{
				ar[x1][y1-1]= '*';
				ar[x2][y1-1] = '*';
			}
		}	
		else if(x1 == x2){
			if(x1+1<n){
				ar[x1+1][y1]= '*';
				ar[x1+1][y2] = '*';
			}
			else{
				ar[x1-1][y1] = '*';
				ar[x2-1][y2] = '*';
			}
		}
		else{
			ar[x2][y1] = '*';
			ar[x1][y2] = '*';
		}
		for(int i =0;i<n;i++){
			for(int j =0;j<n;j++){
				cout<<ar[i][j];
			}
			cout<<endl;
		}

	}
	return 0;
}