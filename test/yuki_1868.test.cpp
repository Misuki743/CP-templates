#define PROBLEM "https://yukicoder.me/problems/no/1868"

#include "../default/t.cpp"
#include "../graph/shortest_path/BFS_01.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vi r(n - 1);
  for(int &x : r) { cin >> x, x--; }

  vvc<pii> g(2 * n);
  for(int i = 0; i < n - 1; i++)
    g[i].emplace_back(r[i] + n, 1);
  for(int i = 0; i < n; i++)
    g[i + n].emplace_back(i, 0);
  for(int i = n + 1; i < 2 * n; i++)
    g[i].emplace_back(i - 1, 0);

  cout << BFS_01(g, {0}).first[n - 1] << '\n';

  return 0;
}
