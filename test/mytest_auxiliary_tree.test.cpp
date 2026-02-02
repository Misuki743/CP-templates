#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../tree/prufer_recover.cpp"
#include "../enumerate/enumerate_bit.cpp"
#include "../enumerate/enumerate_twelvefold.cpp"
#include "../enumerate/enumerate_label_tree.cpp"
#include "../enumerate/enumerate_unlabel_rooted_tree.cpp"
#include "../ds/RMQ.cpp"
#include "../tree/LCA.cpp"
#include "../tree/auxiliary_tree.cpp"

auto auxiliary_tree_brute_force(vvi g, vi vs, int root = 0) {

  vc<bool> in_vs(size(g), false);
  for(int v : vs) in_vs[v] = true;

  vi old_id;
  vc<pii> e;
  vc<bool> is_critical_node;
  auto dfs = [&](int v, int p, auto &self) -> int {
    vi head;
    for(int x : g[v]) {
      if (x == p) continue;
      int y = self(x, v, self);
      if (y != -1) head.eb(y);
    }

    if (!in_vs[v] and ssize(head) <= 1)
      return head.empty() ? -1 : head[0];

    int i = size(old_id);
    old_id.emplace_back(v);
    is_critical_node.emplace_back(in_vs[v]);
    for(int j : head)
      e.emplace_back(i, j);
    return i;
  };

  dfs(root, -1, dfs);

  return tuple(e, old_id, is_critical_node);
}

void check(vector<vector<int>> g, int root) {
  vc<pii> e;
  for(int u = 0; u < ssize(g); u++)
    for(int v : g[u])
      if (u < v)
        e.emplace_back(u, v);

  auxiliary_tree aux(e, root);
  auto check2 = [&](vi vs) {
    auto [ep, old_id, crit] = aux.induced_tree(vs);
    auto [ep2, old_id2, crit2] = auxiliary_tree_brute_force(g, vs, root);

    assert(ssize(old_id) == ssize(old_id2));
    assert(set(old_id.begin(), old_id.end()) ==
           set(old_id2.begin(), old_id2.end()));

    vi val = old_id;
    ranges::sort(val);
    vi mp(size(g), -1);
    for(int i = 0; i < ssize(val); i++)
      mp[val[i]] = i;

    {
      vi p(size(old_id));
      for(int i = 0; i < ssize(p); i++)
        p[i] = mp[old_id[i]];
      for(auto &[u, v] : ep)
        u = p[u], v = p[v];
      vi tmp(size(old_id));
      for(int i = 0; i < ssize(p); i++)
        tmp[p[i]] = old_id[i];
      old_id.swap(tmp);
      vc<bool> tmp2(size(old_id));
      for(int i = 0; i < ssize(p); i++)
        tmp2[p[i]] = crit[i];
      crit.swap(tmp2);
    }

    {
      vi p(size(old_id2));
      for(int i = 0; i < ssize(p); i++)
        p[i] = mp[old_id2[i]];
      for(auto &[u, v] : ep2)
        u = p[u], v = p[v];
      vi tmp(size(old_id2));
      for(int i = 0; i < ssize(p); i++)
        tmp[p[i]] = old_id2[i];
      old_id2.swap(tmp);
      vc<bool> tmp2(size(old_id2));
      for(int i = 0; i < ssize(p); i++)
        tmp2[p[i]] = crit2[i];
      crit2.swap(tmp2);
    }

    ranges::sort(ep);
    ranges::sort(ep2);

    assert(old_id == old_id2);
    assert(ep == ep2);
    assert(crit == crit2);
  };

  mt19937 rng(clock);
  const int n = ssize(g);
  if (ssize(g) <= 15) {
    for(int msk = 1; msk < (1 << n); msk++) {
      vi vs;
      for(int i = 0; i < n; i++)
        if (msk >> i & 1)
          vs.eb(i);
      shuffle(vs.begin(), vs.end(), rng);
      check2(vs);
    }
  } else {
    for(int sz = 1; sz <= n; sz <<= 1) {
      set<int> s;
      while(ssize(s) != sz)
        s.insert(rng() % n);
      vi vs;
      for(int x : s) vs.eb(x);
      shuffle(vs.begin(), vs.end(), rng);
      check2(vs);
    }
  }
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

  for(int n = 1; n <= 6; n++) {
    enumerate_label_tree(n, [&](vector<vector<int>> g) {
      for(int r = 0; r < n; r++)
        check(g, r);
    });
  }

  for(int n = 7; n <= 8; n++) {
    enumerate_unlabel_rooted_tree(n, [&](vector<vector<int>> g) {
      for(int r = 0; r < n; r++)
        check(g, r);
      g = random_relabel(g);
      for(int r = 0; r < n; r++)
        check(g, r);
    });
  }

  //path
  for(int n = 1; n <= 100; n += 2) {
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++)
      g[i].emplace_back(i - 1), g[i - 1].emplace_back(i);
    check(g, 0);
    check(random_relabel(g), rng() % n);
  }

  //star
  for(int n = 2; n <= 100; n += 2) {
    for(int root : {0, n / 2, n - 1}) {
      vector<vector<int>> g(n);
      for(int i = 0; i < n; i++)
        if (i != root)
          g[root].emplace_back(i), g[i].emplace_back(root);
      check(g, root);
      check(g, root == 0);
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
    for(int r : {0, n / 2, n - 1})
      check(g, r);
    g = random_relabel(g);
    for(int r : {0, n / 2, n - 1})
      check(g, r);
  }

  a_plus_b();

  return 0;
}
