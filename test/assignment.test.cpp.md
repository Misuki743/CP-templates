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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph/MCMF.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../graph/MCMF.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  vector a(n, vector<int>(n));\n  for(auto\
    \ &v : a)\n    for(int &x : v)\n      cin >> x;\n\n  const int s = 2 * n, t =\
    \ 2 * n + 1;\n  MCMF<int, ll> mcmf(2 * n + 2);\n  for(int v = 0; v < n; v++) {\n\
    \    mcmf.addEdge(s, v, 1, 0);\n    mcmf.addEdge(v + n, t, 1, 0);\n  }\n  for(int\
    \ u = 0; u < n; u++)\n    for(int v = 0; v < n; v++)\n      mcmf.addEdge(u, v\
    \ + n, 1, a[u][v]);\n\n  mcmf.initPotential(s);\n  cout << mcmf.runFlow(s, t,\
    \ true).second << '\\n';\n  for(int v = 0; v < n; v++)\n    for(auto e : mcmf.g[v])\n\
    \      if (e.cap == 0 and e.to != s)\n        cout << e.to - n << \" \\n\"[v +\
    \ 1 == n];\n\n  return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/assignment.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/assignment.test.cpp
- /verify/test/assignment.test.cpp.html
title: test/assignment.test.cpp
---
