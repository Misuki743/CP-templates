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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/DSUrollback.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../ds/DSUrollback.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >>\
    \ n >> q;\n  vector<array<int, 4>> query(q);\n  for(auto &[t, k, u, v] : query)\
    \ {\n    cin >> t >> k >> u >> v;\n    k += 1;\n  }\n\n  vector<vector<array<int,\
    \ 3>>> g(q + 1);\n  vector<vector<array<int, 3>>> qry(q + 1);\n  for(int i = 1;\
    \ auto &[t, k, u, v] : query) {\n    if (t == 0)\n      g[k].push_back({i, u,\
    \ v});\n    else\n      qry[k].push_back({i, u, v});\n    i++;\n  }\n\n  DSU dsu(n);\n\
    \  vector<int> ans(q + 1, -1);\n  auto dfs = [&](int v, auto self) -> void {\n\
    \    int t = dsu.time();\n    for(auto [i, a, b] : qry[v])\n      ans[i] = dsu.query(a)\
    \ == dsu.query(b);\n    for(auto [x, a, b] : g[v]) {\n      dsu.merge(a, b);\n\
    \      self(x, self);\n      dsu.rollback(t);\n    }\n  };\n\n  dfs(0, dfs);\n\
    \n  for(int i = 0; i <= q; i++)\n    if (ans[i] != -1)\n      cout << ans[i] <<\
    \ '\\n';\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/persistent_unionfind.test.cpp
- /verify/test/persistent_unionfind.test.cpp.html
title: test/persistent_unionfind.test.cpp
---
