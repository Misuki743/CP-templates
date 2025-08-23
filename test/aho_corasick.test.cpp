#define PROBLEM "https://judge.yosupo.jp/problem/aho_corasick"

#include "../default/t.cpp"
#include "../string/AhoCorasick.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  AhoCorasick ac(1 << 20);
  vector<int> vs;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    vs.eb(ac.insert(s));
  }

  ac.build();

  cout << ssize(ac.v) << '\n';
  for(auto &node : ac.v | views::drop(1))
    cout << node.p << ' ' << node.link << '\n';
  cout << vs << '\n';

  return 0;
}

