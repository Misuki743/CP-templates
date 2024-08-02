struct staticTopTree {
  enum type { Vertex, Rake, Compress, AddEdge, AddVertex};

  vector<vector<int>> g;
  int stt_rt, n;
  vector<int> lc, rc, p, ord;
  vector<type> vt;
  int nxt;

  staticTopTree(vector<vector<int>> _g, int root = 0) : n(size(_g)),
  lc(4 * n, -1), rc(4 * n, -1), p(4 * n, -1), vt(4 * n, type::Vertex), nxt(2 * n) {
    g.swap(_g);
    dfs(root, -1);
    stt_rt = compress(root).first;
    g.swap(_g);
  }

  int dfs(int v, int pa) {
    int sz = 1, pid = -1;
    pii heavy(-1, -1);
    for(int i = -1; int x : g[v]) {
      i++;
      if (x == pa) {
        pid = i;
        continue;
      }
      int tmp = dfs(x, v);
      chmax(heavy, pii(tmp, i));
      sz += tmp;
    }
    if (heavy.second != -1) swap(g[v][heavy.second], g[v][0]);
    if (pid != -1) g[v].erase(g[v].begin() + (pid == 0 and heavy.second != -1 ? heavy.second : pid));
    return sz;
  }

  void newVertex(int l, int r, type t) {
    if (l != -1) p[l] = nxt, lc[nxt] = l;
    if (r != -1) p[r] = nxt, rc[nxt] = r;
    ord.emplace_back(nxt);
    vt[nxt++] = t;
  }

  void setVertex(int l, int r, int v, type t) {
    if (l != -1) p[l] = v, lc[v] = l;
    if (r != -1) p[r] = v, rc[v] = r;
    ord.emplace_back(v);
    vt[v] = t;
  }

  pii merge(vector<pii> &vs, type t, int v = -1) {
    if (size(vs) == 1) return vs[0];
    int szSum = 0;
    for(auto [_, sz] : vs) szSum += sz;
    int i = 0, pre = 0;
    while(i + 1 < ssize(vs) and 2 * pre <= szSum) pre += vs[i++].second;
    vector<pii> lv(vs.begin(), vs.begin() + i), rv(vs.begin() + i, vs.end());
    auto [l, lsz] = merge(lv, t);
    auto [r, rsz] = merge(rv, t);
    if (v == -1) {
      newVertex(l, r, t);
      return {nxt - 1, lsz + rsz + 1};
    } else {
      setVertex(l, r, v, t);
      return {v, lsz + rsz + 1};
    }
  }

  pii compress(int v) {
    vector<pii> vs(1, addEdge(v));
    while(!g[v].empty()) 
      vs.emplace_back(addEdge(v = g[v][0]));
    return merge(vs, type::Compress);
  }

  pii addEdge(int v) {
    auto [l, lsz] = addVertex(v);
    setVertex(l, -1, v + n, type::AddEdge);
    return {v + n, lsz + 1};
  }

  pii addVertex(int v) {
    if (ssize(g[v]) <= 1) {
      setVertex(-1, -1, v, type::Vertex);
      return {v, 1};
    } else {
      auto [l, lsz] = rake(v);
      setVertex(l, -1, v, type::AddVertex);
      return {v, lsz + 1};
    }
  }

  pii rake(int v) {
    vector<pii> vs;
    for(int x : g[v] | views::drop(1))
      vs.emplace_back(compress(x));
    return merge(vs, type::Rake);
  }
};
