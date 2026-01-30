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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/eulerTour2.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../segtree/segmentTree.cpp\"\n#include\
    \ \"../ds/eulerTour2.cpp\"\n\nll unit() { return 0ll; }\nll add(const ll &a, const\
    \ ll &b) { return a + b; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a)\n    cin >> x;\n  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++)\
    \ {\n    int v; cin >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  eulerTour2<ll, unit, add> eu(g);\n\n  for(int v = 0; v < n; v++)\n \
    \   eu.set(v, a[v]);\n\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0)\
    \ {\n      int x, y; cin >> x >> y;\n      eu.set(x, eu.get(x) + y);\n    } else\
    \ {\n      int x; cin >> x;\n      cout << eu.query(x) << '\\n';\n    }\n  }\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_subtree_sum.test.cpp
- /verify/test/vertex_add_subtree_sum.test.cpp.html
title: test/vertex_add_subtree_sum.test.cpp
---
