#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../default/t.cpp"
#include "../tree/weighted_tree_diameter.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vc<tuple<int, int, ll>> e(n - 1);
  for(auto &[u, v, w] : e)
    cin >> u >> v >> w;

  auto [d, path] = weighted_tree_diameter(e);
  cout << d << ' ' << ssize(path) << '\n';
  cout << path << '\n';

  return 0;
}
