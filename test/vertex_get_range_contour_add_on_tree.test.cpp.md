---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/fastJump.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#include <bits/extc++.h>\n#include \"../default/t.cpp\"\n#include \"../ds/hashTable.cpp\"\
    \n#include \"../ds/fenwickTree.cpp\"\n#include \"../ds/fastJump.cpp\"\n#include\
    \ \"../ds/centroidTree.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n;\
    \ i++) {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  auto [g2, r] = centroidTree(g);\n\n  vector<int> p(n, -1);\n  auto dfs\
    \ = [&](int v, auto self) -> void {\n    for(int x : g2[v]) {\n      if (x ==\
    \ p[v]) continue;\n      p[x] = v;\n      self(x, self);\n    }\n  };\n  dfs(r,\
    \ dfs);\n\n  gp_hash_table<ll, int, custom_hash> toId({}, {}, {}, {}, {1 << 19});\n\
    \  vector<vector<array<int, 2>>> cand(2 * n);\n  vector<int> base(2 * n);\n  vector<ll>\
    \ init;\n  init.reserve(1 << 19);\n  fastJump fj(g);\n  for(int s = 0; s < n;\
    \ s++) {\n    auto dfs = [&](int v, auto self) -> void {\n      cand[s].push_back({fj.dis(s,\
    \ v), v});\n      if (p[s] != -1)\n        cand[s + n].push_back({fj.dis(p[s],\
    \ v), v});\n      for(int x : g2[v]) {\n        if (x == p[v]) continue;\n   \
    \     self(x, self);\n      }\n    };\n    dfs(s, dfs);\n    for(int d : {0, n})\
    \ {\n      base[s + d] = ssize(init);\n      ranges::sort(cand[s + d]);\n    \
    \  for(auto [_, v] : cand[s + d]) {\n        toId[(ll)v << 32 | (s + d)] = ssize(init);\n\
    \        init.emplace_back(a[v]);\n      }\n    }\n  }\n\n  adjacent_difference(init.begin(),\
    \ init.end(), init.begin());\n  fenwickTree<ll> ft(init);\n  auto modify = [&](int\
    \ v, int l, int r, int d) {\n    int ql = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{l, -1}) - cand[v].begin());\n    int qr = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{r, -1}) - cand[v].begin());\n    ft.add(ql, d), ft.add(qr, -d);\n\
    \  };\n\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int\
    \ x, l, r, d; cin >> x >> l >> r >> d;\n      int v = x, pv = -1;\n      while(v\
    \ != -1) {\n        int di = fj.dis(v, x);\n        modify(v, l - di, r - di,\
    \ d);\n        if (pv != -1) {\n          modify(pv + n, l - di, r - di, d);\n\
    \        }\n        pv = v, v = p[v];\n      }\n    } else {\n      int x; cin\
    \ >> x;\n      int v = x, pv = -1;\n      ll ans = 0;\n      while(v != -1) {\n\
    \        ans += ft.query(toId[(ll)x << 32 | v]);\n        if (pv != -1)\n    \
    \      ans -= ft.query(toId[(ll)x << 32 | (pv + n)]);\n        pv = v, v = p[v];\n\
    \      }\n      cout << ans << '\\n';\n    }\n  }\n\n  return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/vertex_get_range_contour_add_on_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_get_range_contour_add_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_get_range_contour_add_on_tree.test.cpp
- /verify/test/vertex_get_range_contour_add_on_tree.test.cpp.html
title: test/vertex_get_range_contour_add_on_tree.test.cpp
---
