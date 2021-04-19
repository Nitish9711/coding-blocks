#include <bits/stdc++.h>

using namespace std;

struct DSU {
	set<int> roots;
	vector<int> par, sz;

	DSU (int n) : par(n), sz(n, 1) {
		iota(begin(par), end(par), 0);
		roots.insert(cbegin(par), cend(par));
	}

	int root(int x) {
		if (x == par[x]) return x;
		return x = par[par[x]] = root(par[x]);
	}

	void join(int a, int b) {
		a = root(a), b = root(b);
		if (a == b) return;
		if (rand() % 2) swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
		roots.erase(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin >> test;
	while (test--) {
		int n, m;
		long long a, b;
		cin >> n >> m >> a >> b;

		DSU d(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;

			d.join(u, v);
		}

		long long res = 0;

		if (b < a) {
			for (int root : d.roots) {
				res += a + b * (d.sz[root] - 1);
			}
		}
		else {
			res = a * n;
		}

		cout << res << '\n';
	}
}