#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

void ReadCP()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
class node
{
public:
	char data;
	unordered_map<char, node *> children;
	int cnt;
	bool terminal;
	node(char d)
	{
		data = d;
		terminal = false;
		cnt = 0;
	}
};

class Trie
{
	node *root;
public:
	Trie()
	{
		root = new node('\0');
	}

	void insert(string w)
	{
		node *temp = root;
		for (int i = 0; i < w.length(); i++)
		{
			char ch = w[i];
			if (temp->children.count(ch))
			{
				temp = temp->children[ch];
				temp->cnt = temp->cnt + 1;
			}
			else
			{
				node *n = new node(ch);
				temp->children[ch] = n;
				temp = n;
				temp->cnt = temp->cnt + 1;
			}
		}
		temp->terminal = true;
	}

	string prefix(string s)
	{
		node *temp = root;
		int i = 0, length = s.length();
		string ans = "";
		while (i != length)
		{
			if ((temp->children[s[i]])->cnt == 1)
			{
				ans += s[i];
				return ans;
			}
			else
			{
				ans += s[i];
				temp = temp->children[s[i]];
			}
			i++;
		}
		return ans;
	}
};

int main()
{
	ReadCP();
	int t;
	cin>>t;

	while(t--){
	
		int n,m;
		cin>>n>>m;

		vector<string>ar;
		string str;
		Trie t;
		bool one = false, zero = false;
		string oneStart , zeroStart;
		for(int i=0;i<n;i++){
			cin>>str;
			ar.push_back(str);
			// ar[i]  = str;
			t.insert(str);

			if(str[0] == '1' && one == false){
				oneStart = str;
				one = true;
			}
			else if(str[0] == '0' && zero == false){
				zeroStart = str;
				zero = true;
			}
		}	

		ll ans = 0;
		if(one == true)
			ans += m;
		if(zero == true)
			ans += m;

		for(int i=0;i<n;i++){
			
			if((ar[i][0] == '0' && ar[i] != zeroStart)
				|| (ar[i][0]== '1' && ar[i]!= oneStart) ){
					string pre = t.prefix(ar[i]);
					ll preLen = pre.length();
					if(preLen != m)
						ans += m - (preLen  -1);
			}

		}

		cout<<ans<<endl;

    


	}



	return 0;
}