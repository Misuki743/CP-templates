---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_auxiliary_tree.test.cpp
    title: test/mytest_auxiliary_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/auxiliary_tree.cpp\"\n//#include \"ds/RMQ.cpp\"\n//#include\
    \ \"tree/LCA.cpp\"\n\nstruct auxiliary_tree {\n  LCA lca;\n\n  auxiliary_tree(vc<pii>\
    \ e, int root = 0) : lca(e, root) {}\n\n  auto induced_tree(vi vs) {\n    const\
    \ int P = 10;\n\n    auto proj = [&](int v) { return lca.tin[v]; };\n    if (ssize(vs)\
    \ < (1 << P) / P) {\n      ranges::sort(vs, {}, proj);\n    } else {\n      int\
    \ mx = proj(ranges::max(vs, {}, proj));\n      for(int i = 0; mx > 0; i++, mx\
    \ >>= P){\n        array<int, (1 << P) + 1> f = {};\n        for(int v : vs)\n\
    \          f[(proj(v) >> (i * P) & ((1 << P) - 1)) + 1]++;\n        pSum(f);\n\
    \        vi nxt(size(vs));\n        for(int v : vs)\n          nxt[f[proj(v) >>\
    \ (i * P) & ((1 << P) - 1)]++] = v;\n        vs.swap(nxt);\n      }\n    }\n\n\
    \    vi s, old_id;\n    vc<bool> is_critical_node;\n    auto push_new_vertex =\
    \ [&](int v, bool critical = true) {\n      s.emplace_back(ssize(old_id));\n \
    \     old_id.emplace_back(v);\n      is_critical_node.emplace_back(critical);\n\
    \    };\n    \n    if (int v = lca.lca(vs[0], vs.back()); v != vs[0])\n      push_new_vertex(v,\
    \ false);\n\n    vc<pii> e;\n    for(int v : vs) {\n      if (s.empty() or lca.is_ancestor_of(old_id[s.back()],\
    \ v)) {\n        push_new_vertex(v);\n      } else {\n        int last_pop = -1;\n\
    \        do {\n          int j = s.back(); s.pop_back();\n          if (last_pop\
    \ != -1)\n            e.emplace_back(j, last_pop);\n          last_pop = j;\n\
    \        } while(!lca.is_ancestor_of(old_id[s.back()], v));\n\n        if (int\
    \ x = lca.lca(old_id[last_pop], v); x != old_id[s.back()])\n          push_new_vertex(x,\
    \ false);\n        e.emplace_back(s.back(), last_pop);\n\n        push_new_vertex(v);\n\
    \      }\n    }\n\n    for(int i = 1; i < ssize(s); i++)\n      e.emplace_back(s[i\
    \ - 1], s[i]);\n\n    return tuple(e, old_id, is_critical_node);\n  }\n};\n"
  code: "//#include \"ds/RMQ.cpp\"\n//#include \"tree/LCA.cpp\"\n\nstruct auxiliary_tree\
    \ {\n  LCA lca;\n\n  auxiliary_tree(vc<pii> e, int root = 0) : lca(e, root) {}\n\
    \n  auto induced_tree(vi vs) {\n    const int P = 10;\n\n    auto proj = [&](int\
    \ v) { return lca.tin[v]; };\n    if (ssize(vs) < (1 << P) / P) {\n      ranges::sort(vs,\
    \ {}, proj);\n    } else {\n      int mx = proj(ranges::max(vs, {}, proj));\n\
    \      for(int i = 0; mx > 0; i++, mx >>= P){\n        array<int, (1 << P) + 1>\
    \ f = {};\n        for(int v : vs)\n          f[(proj(v) >> (i * P) & ((1 << P)\
    \ - 1)) + 1]++;\n        pSum(f);\n        vi nxt(size(vs));\n        for(int\
    \ v : vs)\n          nxt[f[proj(v) >> (i * P) & ((1 << P) - 1)]++] = v;\n    \
    \    vs.swap(nxt);\n      }\n    }\n\n    vi s, old_id;\n    vc<bool> is_critical_node;\n\
    \    auto push_new_vertex = [&](int v, bool critical = true) {\n      s.emplace_back(ssize(old_id));\n\
    \      old_id.emplace_back(v);\n      is_critical_node.emplace_back(critical);\n\
    \    };\n    \n    if (int v = lca.lca(vs[0], vs.back()); v != vs[0])\n      push_new_vertex(v,\
    \ false);\n\n    vc<pii> e;\n    for(int v : vs) {\n      if (s.empty() or lca.is_ancestor_of(old_id[s.back()],\
    \ v)) {\n        push_new_vertex(v);\n      } else {\n        int last_pop = -1;\n\
    \        do {\n          int j = s.back(); s.pop_back();\n          if (last_pop\
    \ != -1)\n            e.emplace_back(j, last_pop);\n          last_pop = j;\n\
    \        } while(!lca.is_ancestor_of(old_id[s.back()], v));\n\n        if (int\
    \ x = lca.lca(old_id[last_pop], v); x != old_id[s.back()])\n          push_new_vertex(x,\
    \ false);\n        e.emplace_back(s.back(), last_pop);\n\n        push_new_vertex(v);\n\
    \      }\n    }\n\n    for(int i = 1; i < ssize(s); i++)\n      e.emplace_back(s[i\
    \ - 1], s[i]);\n\n    return tuple(e, old_id, is_critical_node);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/auxiliary_tree.cpp
  requiredBy: []
  timestamp: '2026-02-02 17:55:32+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_auxiliary_tree.test.cpp
documentation_of: tree/auxiliary_tree.cpp
layout: document
redirect_from:
- /library/tree/auxiliary_tree.cpp
- /library/tree/auxiliary_tree.cpp.html
title: tree/auxiliary_tree.cpp
---
