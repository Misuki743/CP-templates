#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../default/t.cpp"
#include "../graph/tree.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<pii> e(n - 1);
  for(auto &[u, v] : e) cin >> u >> v;
  mt19937 rng(clock);
  tree T(std::move(e), rng() % n);
  while(q--) {
    int s, t, i; cin >> s >> t >> i;
    cout << T.kth(s, t, i) << '\n';
  }

  return 0;
}
