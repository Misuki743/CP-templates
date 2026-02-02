//#include "ds/RMQ.cpp"
//#include "tree/LCA.cpp"

struct auxiliary_tree {
  LCA lca;

  auxiliary_tree(vc<pii> e, int root = 0) : lca(e, root) {}

  auto induced_tree(vi vs) {
    const int P = 10;

    auto proj = [&](int v) { return lca.tin[v]; };
    if (ssize(vs) < (1 << P) / P) {
      ranges::sort(vs, {}, proj);
    } else {
      int mx = proj(ranges::max(vs, {}, proj));
      for(int i = 0; mx > 0; i++, mx >>= P){
        array<int, (1 << P) + 1> f = {};
        for(int v : vs)
          f[(proj(v) >> (i * P) & ((1 << P) - 1)) + 1]++;
        pSum(f);
        vi nxt(size(vs));
        for(int v : vs)
          nxt[f[proj(v) >> (i * P) & ((1 << P) - 1)]++] = v;
        vs.swap(nxt);
      }
    }

    vi s, old_id;
    vc<bool> is_critical_node;
    auto push_new_vertex = [&](int v, bool critical = true) {
      s.emplace_back(ssize(old_id));
      old_id.emplace_back(v);
      is_critical_node.emplace_back(critical);
    };
    
    if (int v = lca.lca(vs[0], vs.back()); v != vs[0])
      push_new_vertex(v, false);

    vc<pii> e;
    for(int v : vs) {
      if (s.empty() or lca.is_ancestor_of(old_id[s.back()], v)) {
        push_new_vertex(v);
      } else {
        int last_pop = -1;
        do {
          int j = s.back(); s.pop_back();
          if (last_pop != -1)
            e.emplace_back(j, last_pop);
          last_pop = j;
        } while(!lca.is_ancestor_of(old_id[s.back()], v));

        if (int x = lca.lca(old_id[last_pop], v); x != old_id[s.back()])
          push_new_vertex(x, false);
        e.emplace_back(s.back(), last_pop);

        push_new_vertex(v);
      }
    }

    for(int i = 1; i < ssize(s); i++)
      e.emplace_back(s[i - 1], s[i]);

    return tuple(e, old_id, is_critical_node);
  }
};
