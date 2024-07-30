//#include "ds/staticTopTree2.cpp"

template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct STT_pathAggregate : staticTopTree {
  vector<M> data;
  vector<int> dep, head;

  STT_pathAggregate(vector<vector<int>> g, vector<M> init = vector<M>())
  : staticTopTree(g), data(nxt, id()), dep(nxt), head(nxt) {
    head[nxt - 1] = nxt - 1;
    dfs(nxt - 1);
    if (!init.empty()) {
      for(int v = 0; v < n; v++)
        data[mp[v]] = init[v];
      for(int v = 0; v < nxt; v++)
        if (vt[v] == type::Compress)
          data[v] = op(data[lc[v]], data[rc[v]]);
    }
  }

  void dfs(int v) {
    for(int c : {lc[v], rc[v]}) if (c != -1) {
      dep[c] = dep[v] + 1;
      head[c] = vt[v] == type::AddVertex or (vt[v] == type::Rake and vt[c] != type::Rake) ? c : head[v];
      dfs(c);
    }
  }

  void pull(int v) {
    v = p[v];
    while(v != -1 and vt[v] == type::Compress) {
      data[v] = op(data[lc[v]], data[rc[v]]);
      v = p[v];
    }
  }

  void set(int v, M x) { data[mp[v]] = x, pull(mp[v]); }

  M levelAggregate(int v) {
    int x = head[v];
    M ret = data[v];
    while(v != x) {
      int w = p[v];
      if (vt[w] == type::Compress and rc[w] == v)
        ret = op(ret, data[lc[w]]);
      v = w;
    }
    return ret;
  }

  M query(int u, int v) {
    u = mp[u], v = mp[v];
    M ret = id();
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        ret = op(ret, levelAggregate(u)), u = p[head[u]];
      else
        ret = op(ret, levelAggregate(v)), v = p[head[v]];
    }
    if (vt[head[u]] == type::Rake) return op(ret, data[p[head[u]]]);
    if (u == v) return op(ret, data[u]);
    if (u > v) swap(u, v);
    ret = op(ret, op(data[u], data[v]));
    while(p[u] != p[v]) {
      if (dep[u] > dep[v]) {
        int w = p[u];
        if (lc[w] == u and rc[w] != -1)
          ret = op(ret, data[rc[w]]);
        u = w;
      } else {
        int w = p[v];
        if (rc[w] == v)
          ret = op(ret, data[lc[w]]);
        v = w;
      }
    }
    return ret;
  }
};
