#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../default/t.cpp"
#include "../tree/HLD.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vc<pii> e(n - 1);
  for(auto &[u, v] : e)
    cin >> u >> v;
  HLD hld(std::move(e));
  while(q--) {
    int s, t, k; cin >> s >> t >> k;
    cout << hld.kth(s, t, k) << '\n';
  }

  return 0;
}
