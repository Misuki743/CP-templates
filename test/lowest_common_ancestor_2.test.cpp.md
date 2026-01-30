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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/LCA.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../default/t.cpp\"\
    \n#include \"../ds/RMQ.cpp\"\n#include \"../ds/LCA.cpp\"\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n\
    \  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++) {\n    int v; cin >>\
    \ v;\n    g[v].emplace_back(u);\n  }\n\n  LCA lc(g);\n\n  while(q--) {\n    int\
    \ u, v; cin >> u >> v;\n    cout << lc.lca(u, v) << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/lowest_common_ancestor_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/lowest_common_ancestor_2.test.cpp
layout: document
redirect_from:
- /verify/test/lowest_common_ancestor_2.test.cpp
- /verify/test/lowest_common_ancestor_2.test.cpp.html
title: test/lowest_common_ancestor_2.test.cpp
---
