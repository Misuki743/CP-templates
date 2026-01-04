#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "../default/t.cpp"
#include "../ds/fast_set.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  string t; cin >> t;
  fast_set s(t);
  while(q--) {
    int c, k; cin >> c >> k;
    if (c == 0) s.insert(k);
    if (c == 1) s.erase(k);
    if (c == 2) cout << s.contains(k) << '\n';
    if (c == 3) {
      int x = s.geq(k);
      cout << (x == n ? -1 : x) << '\n';
    }
    if (c == 4) cout << s.leq(k) << '\n';
  }

  return 0;
}

