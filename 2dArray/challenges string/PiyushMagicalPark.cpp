#include<iostream>

using namespace std;


int main()
{
    int n, m, k, s;
	bool success = true;

	cin>>n>>m>>k>>s;
	char ar[n][m];
	for(int i= 0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>ar[i][j];
		}
		
	}
	for(int i= 0;i<n;i++)
	{
		for(int j=0;j<m;j++)                                           
		{	if(s<k)
			{
				success = false;
				break;
			}
			if(ar[i][j]=='.')
			{	s -=2;
                
            }
            else if(ar[i][j]=='*')
			{	s += 5;
                
            }

			else
			{	break;
            }
            if(j!=m-1)
			{	s--;
                
            }	
    }		
}
	if(success)
	{	cout<<"Yes"<<endl;
		cout<< s<<endl;
	}
	else
	{
		cout<<"No";
	}
	

	
	
	return 0;
}