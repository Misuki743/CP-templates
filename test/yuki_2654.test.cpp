#define PROBLEM "https://yukicoder.me/problems/no/2654"

#include "../default/t.cpp"
#include "../ds/dynamicMedian.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n + 1);
  for(int &x : a)
    cin >> x;
  vector<vector<int>> g(n + 1);
  for(int i = 0; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  dynamicMedian<int, ll> s;
  vector<ll> ans(n + 1, LLONG_MAX);
  auto dfs = [&](int v, int p, auto self) -> void {
    s.insert(a[v]);
    if (s.size() > 2 and s.min() != s.max()) {
      int mn = s.min();
      s.erase(mn);
      int med = s.median();
      if (med == mn)
        med++;
      ans[v] = min(ans[v], (ssize(s.left) - ssize(s.right)) * med - s.lsum + s.rsum);
      s.insert(mn);
    }
    if (s.size() > 2 and s.min() != s.max()) {
      int mx = s.max();
      s.erase(mx);
      int med = s.median();
      if (med == mx)
        med--;
      ans[v] = min(ans[v], (ssize(s.left) - ssize(s.right)) * med - s.lsum + s.rsum);
      s.insert(mx);
    }
    if (s.size() > 2 and s.min() == s.max())
      ans[v] = 1;
    for(int x : g[v])
      if (x != p)
        self(x, v, self);
    s.erase(a[v]);
  };

  dfs(0, -1, dfs);

  for(int i = 1; i <= n; i++)
    cout << (ans[i] == LLONG_MAX ? -1 : ans[i]) << '\n';

  return 0;
}
