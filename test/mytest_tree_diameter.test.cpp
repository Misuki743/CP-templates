#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../tree/prufer_recover.cpp"
#include "../enumerate/enumerate_bit.cpp"
#include "../enumerate/enumerate_twelvefold.cpp"
#include "../enumerate/enumerate_label_tree.cpp"
#include "../enumerate/enumerate_unlabel_rooted_tree.cpp"
#include "../tree/tree.cpp"
#include "../tree/tree_diameter.cpp"

void check(vector<vector<int>> g) {
  const int n = ssize(g);
  vi dep;
  auto dfs = [&](int v, int p, auto &self) -> void {
    for(int x : g[v]) {
      if (x == p) continue;
      dep[x] = dep[v] + 1;
      self(x, v, self);
    }
  };

  int diameter = -1;
  for(int r = 0; r < n; r++) {
    vi(n, INT_MAX).swap(dep);
    dep[r] = 0;
    dfs(r, -1, dfs);
    chmax(diameter, ranges::max(dep));
  }

  vc<pii> e;
  for(int u = 0; u < n; u++)
    for(int v : g[u])
      if (u < v)
        e.emplace_back(u, v);

  set<pii> s;
  for(auto [u, v] : e)
    s.emplace(u, v), s.emplace(v, u);

  auto [diameter_2, path] = tree_diameter(e);

  assert(diameter == diameter_2);
  assert(ssize(path) == diameter + 1);
  for(int i = 1; i < ssize(path); i++)
    assert(s.contains(pair(path[i - 1], path[i])));
  Unique(path);
  assert(ssize(path) == diameter + 1);
}

auto random_relabel(vector<vector<int>> g) {
  mt19937 rng(clock);
  const int n = ssize(g);
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  shuffle(p.begin(), p.end(), rng);
  vector<vector<int>> g2(n);
  for(int u = 0; u < n; u++)
    for(int v : g[u])
      g2[p[u]].eb(p[v]);
  return g2;
}

void a_plus_b() {
  int a, b; cin >> a >> b;
  cout << a + b << '\n';
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  mt19937 rng(clock);

  for(int n = 1; n <= 7; n++) {
    enumerate_label_tree(n, [&](vector<vector<int>> g) {
      check(g);
    });
  }

  for(int n = 1; n <= 15; n++) {
    enumerate_unlabel_rooted_tree(n, [&](vector<vector<int>> g) {
      check(g);
      check(random_relabel(g));
    });
  }

  //path
  for(int n = 1; n <= 100; n++) {
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++)
      g[i].emplace_back(i - 1), g[i - 1].emplace_back(i);
    check(g);
    check(random_relabel(g));
  }

  //star
  for(int n = 2; n <= 100; n++) {
    for(int root : {0, n / 2, n - 1}) {
      vector<vector<int>> g(n);
      for(int i = 0; i < n; i++)
        if (i != root)
          g[root].emplace_back(i), g[i].emplace_back(root);
      check(g);
    }
  }

  //almost path
  for(int tc = 0; tc < 30; tc++) {
    int n = 500;
    vector<vector<int>> g(n);
    for(int v = 1; v < n; v++) {
      int x = rng() % min(v, 5);
      g[v].emplace_back(x), g[x].emplace_back(v);
    }
    check(g);
    check(random_relabel(g));
  }

  a_plus_b();

  return 0;
}
