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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph/Dinic.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../graph/Dinic.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int l, r, m; cin >> l\
    \ >> r >> m;\n  const int s = l + r, t = l + r + 1;\n  Dinic<int> dinic(l + r\
    \ + 2);\n  for(int i = 0; i < l; i++) dinic.addEdge(s, i, 1);\n  for(int i = l;\
    \ i < l + r; i++) dinic.addEdge(i, t, 1);\n  for(int i = 0; i < m; i++) {\n  \
    \  int u, v; cin >> u >> v;\n    dinic.addEdge(u, v + l, 1);\n  }\n\n  cout <<\
    \ dinic.runFlow(s, t) << '\\n';\n  for(int v = 0; v < l; v++)\n    for(auto &e\
    \ : dinic.g[v])\n      if (e.cap == 0 and e.to != s)\n        cout << v << ' '\
    \ << e.to - l << '\\n';\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/matching_on_bipartite_graph.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/matching_on_bipartite_graph.test.cpp
layout: document
redirect_from:
- /verify/test/matching_on_bipartite_graph.test.cpp
- /verify/test/matching_on_bipartite_graph.test.cpp.html
title: test/matching_on_bipartite_graph.test.cpp
---
