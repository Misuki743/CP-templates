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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../tree/centroidTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../poly/NTTmint.cpp\"\n#include \"../tree/centroidTree.cpp\"\n#include\
    \ \"../numtheory/crt.cpp\"\n#include \"../ds_problem/frequency_of_tree_distance.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n;\
    \ cin >> n;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n   \
    \ int u, v; cin >> u >> v;\n    g[u].emplace_back(v), g[v].emplace_back(u);\n\
    \  }\n\n  auto ans1 = frequency_of_tree_distance(g);\n  auto ans2 = frequency_of_tree_distance<26,\
    \ 7, 3, MontgomeryModInt<(7 << 26) | 1>>(g);\n  for(int i = 0; i < n - 1; i++)\
    \ {\n    vector<ll> r = {ans1[i].get(), ans2[i].get()};\n    vector<ll> m = {998244353,\
    \ (7 << 26) | 1};\n    cout << crt(r, m).first << \" \\n\"[i + 1 == n - 1];\n\
    \  }\n\n  return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/frequency_table_of_tree_distance.test.cpp
- /verify/test/frequency_table_of_tree_distance.test.cpp.html
title: test/frequency_table_of_tree_distance.test.cpp
---
