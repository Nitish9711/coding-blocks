#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

double get_need_k(int d, vector<double> &delta)
{
	double sum = 0;
	for (int i = 0; i < delta.size(); i++)
	{
		sum += ceil(delta[i] / d) - 1;
	}
	return sum;
}

int solve(int k, vector<int> &minutes)
{
	vector<double> delta(minutes.size() - 1, 0);
	int max_delta = 0;
	for (int i = 1; i < minutes.size(); i++)
	{
		delta[i - 1] = minutes[i] - minutes[i - 1];
		max_delta = delta[i - 1] > max_delta ? delta[i - 1] : max_delta;
	}

	int l = 1, r = max_delta, m;
	while (l < r)
	{
		m = (l + r) / 2;
		double k1 = get_need_k(m, delta);
		if (k1 <= k)
		{
			r = m;
		} 
		else
		{
			l = m + 1;
		}
	}
	return r;
}

int main()
{
	//freopen("1.txt", "r", stdin);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int a, b;
		cin>>a>>b;
		int n;
		cin>>n;
		string str;
		// int mid = (a + b)/2;
		int s = a+1;
		int mid;
		int e = b;
		for(int i = 0;i<n;i++){
			mid = (s + e)/2;
			cout<<mid<<endl;
			cin>>str;
			if(str == "TOO_SMALL"){
				s = mid+1;
			}
			else if (str == "CORRECT"){
				break;
			}
			else if(str == "TOO_BIG"){
				s = mid-1;
			}

		}
	}
}