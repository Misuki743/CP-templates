#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../default/t.cpp"
#include "../graph/hopcroftKarp.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int l, r, m; cin >> l >> r >> m;
  vector<vi> g(l);
  vi btoa(r, -1);
  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
  }
  cout << hopcroftKarp(g, btoa) << '\n';
  for(int i = 0; i < r; i++)
    if (btoa[i] != -1)
      cout << btoa[i] << ' ' << i << '\n';

  return 0;
}

