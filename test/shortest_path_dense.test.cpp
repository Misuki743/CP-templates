#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../default/t.cpp"
#include "../graph/shortest_path/Dijkstra.cpp"
#include "../graph/shortest_path/path_recover.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(0);

  int n, m, s, t; cin >> n >> m >> s >> t;
  if (n < (1 << 13)) {
    vc adj(n, vll(n, LLONG_MAX));
    for(int i = 0; i < m; i++) {
      int u, v, w; cin >> u >> v >> w;
      adj[u][v] = w;
    }

    auto [dis, pre] = Dijkstra_dense(adj, {s});
    vi path = recover(pre, t);

    if (path.empty()) {
      cout << -1 << '\n';
    } else {
      cout << dis[t] << ' ' << ssize(path) - 1 << '\n';
      for(int i = 1; i < ssize(path); i++)
        cout << path[i - 1] << ' ' << path[i] << '\n';
    }
  } else {
    vvc<pair<int, ll>> g(n);
    for(int i = 0; i < m; i++) {
      int u, v, w; cin >> u >> v >> w;
      g[u].emplace_back(v, w);
    }

    auto [dis, pre] = Dijkstra_sparse(g, {s});
    vi path = recover(pre, t);

    if (path.empty()) {
      cout << -1 << '\n';
    } else {
      cout << dis[t] << ' ' << ssize(path) - 1 << '\n';
      for(int i = 1; i < ssize(path); i++)
        cout << path[i - 1] << ' ' << path[i] << '\n';
    }
  }

  return 0;
}
