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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/incremental_scc\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\n#include\
    \ \"../ds/DSU.cpp\"\n#include \"../graph/SCC.cpp\"\n#include \"../graph/incrementalSCC.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector<mint> x(n);\n  for(int i = 0; i < n; i++) cin >>\
    \ x[i];\n  vector<array<int, 2>> e(m);\n  for(auto &[u, v] : e) cin >> u >> v;\n\
    \n  auto t = incrementalSCC(e, n);\n  vector<mint> sum = x, cost(n, 0);\n  DSU\
    \ dsu(n);\n  mint ans = 0;\n  for(int i = 0, j = 0; i < m; i++) {\n    while(j\
    \ < ssize(t) and t[j][2] == i) {\n      auto [u, v, _] = t[j++];\n      u = dsu.query(u),\
    \ v = dsu.query(v);\n      mint sump = sum[u] + sum[v], costp = cost[u] + cost[v]\
    \ + sum[u] * sum[v];\n      ans += costp - (cost[u] + cost[v]);\n      sum[u]\
    \ = sum[v] = sump, cost[u] = cost[v] = costp;\n      dsu.merge(u, v);\n    }\n\
    \    cout << ans << '\\n';\n  }\n\n  return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/incremental_scc.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/incremental_scc.test.cpp
layout: document
redirect_from:
- /verify/test/incremental_scc.test.cpp
- /verify/test/incremental_scc.test.cpp.html
title: test/incremental_scc.test.cpp
---
