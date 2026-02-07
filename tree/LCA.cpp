//#include "ds/RMQ.cpp"

struct LCA {
  vi dep, tin, tout, mp;
  RMQ<int> rmq;

  LCA(vc<pii> e, int root = 0) : rmq(precomp(e, root)) {}

  vi precomp(vc<pii> &e, int root) {
    const int n = ssize(e) + 1;

    dep = tin = tout = mp = vi(n);

    vi sz(n, 1), p(n), ord;
    {
      vi d(n);
      for(auto &[u, v] : e)
        p[u] ^= v, p[v] ^= u, d[u]++, d[v]++;

      d[root] = 0;
      ord.reserve(n - 1);
      for(int i = 0; i < n; i++) {
        int v = i;
        while(d[v] == 1) {
          ord.emplace_back(v);
          sz[p[v]] += sz[v];
          d[v] = 0, d[p[v]]--, p[p[v]] ^= v;
          v = p[v];
        }
      }
      p[root] = root;
    }

    vi dfn(n);
    {
      vi nxt(n, 1);
      for(int v : ord | views::reverse) {
        dfn[v] = nxt[p[v]], nxt[p[v]] += sz[v];
        nxt[v] = dfn[v] + 1;
        dep[v] = dep[p[v]] + 1;
      }
      vi().swap(ord);
      vi().swap(sz);
    }

    vi init(2 * n - 1);
    {
      vi dfn_ord = invPerm(std::move(dfn));

      int nxt = 0, pre = root;
      for(int v : dfn_ord) {
        while(pre != p[v]) {
          pre = p[pre], tout[pre] = nxt;
          init[nxt++] = pre;
        }
        tin[v] = tout[v] = nxt;
        init[nxt++] = pre = v;
      }

      while(pre != root) {
        pre = p[pre], tout[pre] = nxt;
        init[nxt++] = pre;
      }
    }

    {
      vi f(n);
      for(int x : dep) f[x]++;
      pSum(f);

      vi rank(n);
      for(int v = 0; v < n; v++) {
        rank[v] = --f[dep[v]];
        mp[rank[v]] = v;
      }
      for(int &v : init) v = rank[v];
    }

    return init;
  }

  int lca(int u, int v) {
    if (tin[u] > tin[v]) swap(u, v);
    return mp[rmq.query(tin[u], tout[v] + 1)];
  }

  int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  bool is_ancestor_of(int u, int v) {
    return tin[u] <= tin[v] and tout[v] <= tout[u];
  }
};
