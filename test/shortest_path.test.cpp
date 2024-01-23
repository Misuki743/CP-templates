#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../default/t.cpp"
#include "../graph/Dijkstra.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(0);

  int n, m, s, t; cin >> n >> m >> s >> t;
  vector<vector<pair<int, ll>>> g(n);
  while(m--) {
    int a, b, c; cin >> a >> b >> c;
    g[a].emplace_back(b, c);
  }

  auto [dis, pre] = Dijkstra(g, s);
  auto path = recover(pre, t);

  if (dis[t] == -1) {
    cout << -1 << '\n';
  } else {
    cout << dis[t] << ' ' << ssize(path) - 1 << '\n';
    for(int i = 0; i + 1 < ssize(path); i++)
      cout << path[i] << ' ' << path[i + 1] << '\n';
  }

  return 0;
}
