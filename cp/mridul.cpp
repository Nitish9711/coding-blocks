#include <bits/stdc++.h>
#define lln long long int
using namespace std;

void ReadCP() {
#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
#endif
}

lln Max(lln a, lln b) {
  if (a > b)
    return a;
  return b;
}

int main() {
  ReadCP();
  unordered_map<lln, vector<lln>> ump;
  unordered_map<string, pair<lln, pair<lln, lln>>> street_name;
  vector<pair<int, string>> vec_junk;
  map<pair<lln, lln>, string> street_code;

  lln D, I, S, V, F;
  cin >> D >> I >> S >> V >> F;
  for (lln i = 0; i < S; i++) {
    lln B, E, L;
    string str;
    cin >> B >> E >> str >> L;
    ump[B].push_back(E);
    street_name[str] = {L, {B, E}};
    street_code[{B, E}] = str;
  }
  unordered_map<string, int> ump_string_vec;

  vector<vector<string>> car_vec;
  for (lln i = 0; i < V; i++) {
    lln n;
    cin >> n;
    vector<string> foo;
    for (lln j = 0; j < n; j++) {
      string bar;
      cin >> bar;
      if (ump_string_vec.find(bar) == ump_string_vec.end())
        ump_string_vec[bar] = 0;
      ump_string_vec[bar]++;
      foo.push_back(bar);
    }
    car_vec.push_back(foo);
  }

  unordered_map<lln, vector<lln>> ump_go;
  for (auto x : ump) {
    for (lln j = 0; j < x.second.size(); j++) {
      ump_go[x.second[j]].push_back(x.first);
    }
  }
  cout << ump_go.size() << endl;
  for (auto x : ump_go) {
    cout << x.first << endl;
    cout << x.second.size() << endl;
    for (int j = 0; j < x.second.size(); j++) {
      string ans_foo = street_code[{x.second[j], x.first}];
      if (ump_string_vec[ans_foo] == 0)
        cout << ans_foo << " " << 1 << endl;
      else {
        lln asasa = 1 + (rand() % ((ump_string_vec[ans_foo])) / 3)  + 8;
        cout << ans_foo << " " << asasa << endl;
      }
    }
  }

  return 0;
}