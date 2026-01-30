#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include "../default/t.cpp"
#include "../graph/flow/MCMF.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector a(n, vector<int>(n));
  for(auto &v : a)
    for(int &x : v)
      cin >> x;

  const int s = 2 * n, t = 2 * n + 1;
  MCMF<int, ll> mcmf(2 * n + 2);
  for(int v = 0; v < n; v++) {
    mcmf.addEdge(s, v, 1, 0);
    mcmf.addEdge(v + n, t, 1, 0);
  }
  for(int u = 0; u < n; u++)
    for(int v = 0; v < n; v++)
      mcmf.addEdge(u, v + n, 1, a[u][v]);

  mcmf.initPotential(s);
  cout << mcmf.runFlow(s, t, true).second << '\n';
  for(int v = 0; v < n; v++)
    for(auto e : mcmf.g[v])
      if (e.cap == 0 and e.to != s)
        cout << e.to - n << " \n"[v + 1 == n];

  return 0;
}

