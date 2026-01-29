#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../default/t.cpp"
#include "../graph/tree.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> p(n - 1);
  for(int &x : p) cin >> x;
  p.insert(p.begin(), -1);
  tree T(std::move(p));
  while(q--) {
    int u, v; cin >> u >> v;
    cout << T.lca(u, v) << '\n';
  }

  return 0;
}
