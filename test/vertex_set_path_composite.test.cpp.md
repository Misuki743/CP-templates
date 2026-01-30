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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/heavyLightDecomposition.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../segtree/segmentTree.cpp\"\n#include \"../actedmonoid/actedMonoid_affineSum.cpp\"\
    \n#include \"../ds/heavyLightDecomposition.cpp\"\n\nusing am = actedMonoid_affineSum<mint>;\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<am::T> ab(n);\n  for(auto &[a, b] : ab)\n    cin >>\
    \ a >> b;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n    int\
    \ u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  HLD hld(g);\n  vector<am::T> init(n);\n  for(int i = 0; i < n; i++)\n\
    \    init[hld.id[i]] = ab[i];\n  segmentTree<am::T, am::Tid, am::Top> st(init);\n\
    \  ranges::reverse(init);\n  segmentTree<am::T, am::Tid, am::Top> str(init);\n\
    \n  while(q--) {\n    int t, a, b, c; cin >> t >> a >> b >> c;\n    if (t == 0)\
    \ {\n      st.set(hld.id[a], am::T{b, c});\n      str.set((n - 1) - hld.id[a],\
    \ am::T{b, c});\n    } else {\n      auto res = am::T{0, c};\n      for(auto [l,\
    \ r, rev] : hld.query(a, b)) {\n        if (rev)\n          res = am::Top(res,\
    \ str.query(n - r, n - l));\n        else\n          res = am::Top(res, st.query(l,\
    \ r));\n      }\n      cout << res[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_composite.test.cpp
- /verify/test/vertex_set_path_composite.test.cpp.html
title: test/vertex_set_path_composite.test.cpp
---
