#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../default/t.cpp"
#include "../tree/cartesian_tree.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vi a(n);
  for(int &x : a) cin >> x;
  cout << cartesian_tree(a) << '\n';

  return 0;
}

