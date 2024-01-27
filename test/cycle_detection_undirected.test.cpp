#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"

#include "../default/t.cpp"
#include "../graph/cycleDetection.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<array<int, 2>> e(m);
  for(auto &[u, v] : e)
    cin >> u >> v;
  
  auto [vs, es] = cycleDetection(e);
  if (vs.empty()) {
    cout << -1 << '\n';
  } else {
    cout << ssize(vs) << '\n';
    cout << vs << '\n';
    cout << es << '\n';
  }

  return 0;
}
