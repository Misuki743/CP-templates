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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph/Dijkstra.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../graph/Dijkstra.cpp\"\n\nint main() {\n \
    \ ios::sync_with_stdio(false), cin.tie(0);\n\n  int n, m, s, t; cin >> n >> m\
    \ >> s >> t;\n  vector<vector<pair<int, ll>>> g(n);\n  while(m--) {\n    int a,\
    \ b, c; cin >> a >> b >> c;\n    g[a].emplace_back(b, c);\n  }\n\n  auto [dis,\
    \ pre] = Dijkstra(g, s);\n  auto path = recover(pre, t);\n\n  if (dis[t] == -1)\
    \ {\n    cout << -1 << '\\n';\n  } else {\n    cout << dis[t] << ' ' << ssize(path)\
    \ - 1 << '\\n';\n    for(int i = 0; i + 1 < ssize(path); i++)\n      cout << path[i]\
    \ << ' ' << path[i + 1] << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/shortest_path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/shortest_path.test.cpp
- /verify/test/shortest_path.test.cpp.html
title: test/shortest_path.test.cpp
---
