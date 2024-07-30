struct staticTopTree {
  enum type { AddVertex, Rake, Compress };

  vector<vector<int>> g;
  int n, nxt;
  vector<int> lc, rc, p, vt, mp;

  staticTopTree(vector<vector<int>> _g) : n(size(_g)), nxt(0),
  lc(2 * n, -1), rc(2 * n, -1), p(2 * n, -1), vt(2 * n), mp(n) {
    g.swap(_g);
    dfs(0, -1);
    compress(0);
    g.swap(_g);
  }

  int dfs(int v, int p) {
    int sz = 1, mx = 0;
    for(int &x : g[v]) {
      if (x == p) swap(x, g[v].back());
      if (x == p) continue;
      int c = dfs(x, v);
      sz += c;
      if (chmax(mx, c)) swap(x, g[v][0]);
    }
    if (!g[v].empty() and g[v].back() == p) g[v].pop_back();
    return sz;
  }

  void allocate(int v, int l, int r, type t) {
    if (l != -1) p[l] = v, lc[v] = l;
    if (r != -1) p[r] = v, rc[v] = r;
    vt[v] = t;
  }

  pii merge(vector<pii> &vs, type t) {
    if (size(vs) == 1) return vs[0];
    int szSum = 0, i = 0, pre = 0;
    for(auto [_, sz] : vs) szSum += sz;
    while(i + 1 < ssize(vs) and 2 * pre <= szSum) pre += vs[i++].second;
    vector lv(vs.begin(), vs.begin() + i), rv(vs.begin() + i, vs.end());
    auto [l, lsz] = merge(lv, t);
    auto [r, rsz] = merge(rv, t);
    allocate(nxt, l, r, t);
    return {nxt++, lsz + rsz + 1};
  }

  pii compress(int v) {
    vector vs(1, addVertex(v));
    while(!g[v].empty())
      vs.emplace_back(addVertex(v = g[v][0]));
    return merge(vs, type::Compress);
  }

  pii addVertex(int v) {
    auto [l, lsz] = rake(v);
    allocate(nxt, l, -1, type::AddVertex);
    mp[v] = nxt;
    return {nxt++, lsz + 1};
  }

  pii rake(int v) {
    if (ssize(g[v]) <= 1) return {-1, 0};
    vector<pii> vs;
    for(int x : g[v] | views::drop(1))
      vs.emplace_back(compress(x));
    return merge(vs, type::Rake);
  }
};
