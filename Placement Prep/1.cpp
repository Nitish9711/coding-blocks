    #include <bits/stdc++.h>


    using namespace std;



    #define pi 3.1415926536
    #define pb push_back
    #define F first
    #define S second
    #define endl "\n"
    #define bs binary_search
    #define int long long
    #define float double
    #define mii map<int, int>
    #define mci map<char, int>
    #define msi map<string, int>
    #define mss map<string, string>
    #define mcc map<char, char>
    #define mpi map<pair<int, int>, int>
    #define vi vector<int>
    #define vs vector<string>
    #define si set<int>
    #define ss set<string>
    #define sc set<char>
    int const max1 = 2e5 + 5;
    int const mod = 1e9 + 7;
    int inf = 1e18;

    vector<pair<int, int>> adj[max1];
    map<int, set<int>> nfa_state;
    set<set<int>> all;

    void closure(int n, set<int> &s)
    {
        s.insert(n);
        for (auto x : adj[n])
        {
            if (x.S == 0)
            {
                closure(x.F, s);
            }
        }
    }

    set<int> search(int t, set<int> s)
    {
        set<int> result;
        for (auto x : s)
        {
            for (auto y : adj[x])
            {
                if (y.S == t)
                {
                    result.insert(y.F);
                }
            }
        }
        for (auto x : result)
        {
            closure(x, result);
        }
        return result;
    }

    void ans(int max1, int ter, map<pair<int, int>, int> table)
    {
        for (int i = 0; i < 28 + ter; i++)
            cout << "-";
        cout << "\n";
        cout << "|       States       |";
        int space = 16;
        cout << " a |"
            << " b |";

        cout << "\n";
        for (int i = 0; i < 28 + ter; i++)
            cout << "-";
        cout << "\n";

        for (int i = 1; i <= max1; i++)
        {
            cout << char('A' + i - 1) << "={";
            int t = 0;
            for (auto x : nfa_state[i])
            {
                cout << x << ",";
                int temp = x;
                if (temp == 0)
                {
                    t += 2;
                    continue;
                }
                while (temp)
                {
                    t++;
                    temp /= 10;
                }
                t++;
            }
            cout << "}";
            int gaps = 16 - t;
            for (int j = 0; j < gaps; j++)
                cout << " ";

            for (int j = 1; j <= ter; j++)
            {
                cout << " | " << char('A' + table[{i, j}] - 1);
            }
            cout << " |";
            cout << endl;
        }
    }

    void solve()
    {
        int st, ter;
        // cout<<"number of states : ";
        cin >> st;
        // cout<<"number of terminals : ";
        cin >> ter;
        int n;
        // cout<<"number of transitions : ";
        cin >> n;
        // 0 terminal is epsilon
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            // cout<<"Enter starting state and final state";
            cin >> a >> b;
            int c;
            // cout<<"Enter terminal between the states";
            cin >> c;
            adj[a].pb({b, c});
        }
        set<int> temp;
        closure(0, temp);
        nfa_state[1] = temp;
        all.insert(temp);
        int current = 1;
        int max1 = 1;
        map<pair<int, int>, int> table;
        while (current <= max1)
        {
            temp = nfa_state[current];
            for (int i = 1; i <= ter; i++)
            {
                set<int> result = search(i, temp);
                if (all.find(result) == all.end())
                {
                    max1++;
                    all.insert(result);
                    nfa_state[max1] = result;
                    table[{current, i}] = max1;
                }
                else
                {
                    for (int j = 1; j <= max1; j++)
                    {
                        if (nfa_state[j] == result)
                        {
                            table[{current, i}] = j;
                            break;
                        }
                    }
                }
            }
            current++;
        }

        ans(max1, ter, table);
    }

    int32_t main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int tc = 1;
        // cin>>tc;
        while (tc--)
        {
            solve();
        }
    }
