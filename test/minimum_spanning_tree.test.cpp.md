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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/DSU.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/DSU.cpp\"\n#include \"../graph/Kruskal.cpp\"\
    \n#include \"../graph/Prim.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  ll n, m; cin >> n >> m;\n  vector<array<ll, 3>> e(m);\n\
    \  for(auto &[u, v, w] : e)\n    cin >> u >> v >> w;\n\n  ll cost;\n  vector<int>\
    \ eid;\n  if (n * n < m * (int)bit_width((unsigned)m))\n    tie(cost, eid) = Prim(e,\
    \ n);\n  else\n    tie(cost, eid) = Kruskal(e, n);\n\n  cout << cost << '\\n';\n\
    \  cout << eid << '\\n';\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/minimum_spanning_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/minimum_spanning_tree.test.cpp
layout: document
redirect_from:
- /verify/test/minimum_spanning_tree.test.cpp
- /verify/test/minimum_spanning_tree.test.cpp.html
title: test/minimum_spanning_tree.test.cpp
---
