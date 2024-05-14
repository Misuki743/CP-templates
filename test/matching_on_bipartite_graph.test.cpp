#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../default/t.cpp"
#include "../graph/Dinic.cpp"

int main() {
  int l, r, m; cin >> l >> r >> m;

  const int s = l + r, t = l + r + 1;
  Dinic<int, INT_MAX> flow(l + r + 2);
  flow.init(l + r + 2, s, t);
  while(m--) {
    int u, v; cin >> u >> v;
    flow.addEdge(u, v + l, 1);
  }
  for(int i = 0; i < l; i++)
    flow.addEdge(s, i, 1);
  for(int i = l; i < l + r; i++)
    flow.addEdge(i, t, 1);

  cout << flow.flow() << '\n';
  for(int i = l; i < l + r; i++)
    for(auto e : flow.G[i])
      if (e.to != t and e.cap == 1)
        cout << e.to << ' ' << i - l << '\n';
}
