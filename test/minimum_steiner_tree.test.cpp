#define PROBLEM "https://judge.yosupo.jp/problem/minimum_steiner_tree"

#include "../default/t.cpp"
#include "../graph/misc/steinerTree.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<tuple<int, int, ll>> e(m);
  for(auto &[u, v, w] : e) cin >> u >> v >> w;
  int k; cin >> k;
  vector<int> s(k);
  for(int &x : s) cin >> x;

  auto [cost, t] = steiner_tree(n, s, e);
  cout << cost << ' ' << ssize(t) << '\n';
  cout << t << '\n';

  return 0;
}

