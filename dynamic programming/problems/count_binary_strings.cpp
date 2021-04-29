// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.


#include<iostream>
using namespace std;

long long int dp[91][2];
long long int count(int n,int s)
{
	if(n==1)
		return 1;
	
	if(dp[n][s]!=-1)
		return dp[n][s];

	if(s==0)
		dp[n][s]=count(n-1,1)+count(n-1,0);
	else
		dp[n][s]=count(n-1,0);

	return dp[n][s];
}

int main() {
	int t,n;
	cin>>t;
	
	while(t--)
	{
		for(int i=0;i<=90;i++){	
			for(int j=0;j<=2;j++){//change
				dp[i][j]=-1;
			}
		}
		cin>>n;
		long long int res=count(n,1)+count(n,0);
		cout<<res<<endl;
	}
	return 0;
}