#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../graph/prufer_recover.cpp"
#include "../enumerate/enumerate_cartesian_product.cpp"
#include "../enumerate/enumerate_label_tree.cpp"
#include "../enumerate/enumerate_unlabel_rooted_tree.cpp"
#include "../graph/tree.cpp"

void check(vector<vector<int>> g, int root) {
  const int n = ssize(g);
  vector<int> p(n, root), sz(n, 1), dep(n);
  auto dfs = [&](int v, auto &self) -> void {
    for(int x : g[v]) {
      if (x == p[v]) continue;
      p[x] = v, dep[x] = dep[v] + 1;
      self(x, self);
      sz[v] += sz[x];
    }
  };
  dfs(root, dfs);

  vector<pii> e;
  for(int u = 0; u < n; u++)
    for(int v : g[u])
      if (u < v)
        e.emplace_back(u, v);

  tree T(e, root);
  assert(tie(T.p, T.sz, T.dep) == tie(p, sz, dep));
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
  return pair(g2, p[0]);
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
      for(int root = 0; root < n; root++)
        check(g, root);
    });
  }

  for(int n = 1; n <= 15; n++) {
    enumerate_unlabel_rooted_tree(n, [&](vector<vector<int>> g) {
      check(g, 0);
      auto [gp, root] = random_relabel(g);
      check(gp, root);
    });
  }

  //path
  for(int n = 1; n <= 100; n++) {
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++)
      g[i].emplace_back(i - 1), g[i - 1].emplace_back(i);
    check(g, 0);
    check(g, n / 2);
    check(g, n - 1);
    auto [gp, root] = random_relabel(g);
    check(gp, root);
  }

  //star
  for(int n = 2; n <= 100; n++) {
    for(int root : {0, n / 2, n - 1}) {
      vector<vector<int>> g(n);
      for(int i = 0; i < n; i++)
        if (i != root)
          g[root].emplace_back(i), g[i].emplace_back(root);
      check(g, root);
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
    check(g, 0);
    auto [gp, root] = random_relabel(g);
    check(gp, root);
  }

  a_plus_b();

  return 0;
}
