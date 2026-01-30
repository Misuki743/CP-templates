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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/potentialDSU.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/potentialDSU.cpp\"\n#include\
    \ \"../modint/MontgomeryModInt.cpp\"\n\nusing matrix = array<array<mint, 2>, 2>;\n\
    matrix id() {\n  matrix m;\n  m[0][0] = m[1][1] = 1;\n  return m;\n}\nmatrix op(const\
    \ matrix &m1, const matrix &m2) {\n  matrix m;\n  for(int i : {0, 1})\n    for(int\
    \ k : {0, 1})\n      for(int j : {0, 1})\n        m[i][j] += m1[i][k] * m2[k][j];\n\
    \  return m;\n}\nmatrix inv(const matrix &m) {\n  matrix a = m;\n  swap(a[0][0],\
    \ a[1][1]);\n  a[0][1] = -a[0][1], a[1][0] = -a[1][0];\n  return a;\n}\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >>\
    \ n >> q;\n  DSU<matrix, id, op, inv> dsu(n);\n  while(q--) {\n    int t, u, v;\
    \ cin >> t >> u >> v;\n    swap(u, v);\n    if (t == 0) {\n      matrix m;\n \
    \     for(auto &v : m) for(mint &x : v) cin >> x;\n      cout << dsu.merge(u,\
    \ v, m) << '\\n';\n    } else {\n      if (dsu.query(u) != dsu.query(v))\n   \
    \     cout << -1 << '\\n';\n      else\n        cout << dsu.query(u, v) << '\\\
    n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/unionfind_with_potential_non_commutative_group.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unionfind_with_potential_non_commutative_group.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind_with_potential_non_commutative_group.test.cpp
- /verify/test/unionfind_with_potential_non_commutative_group.test.cpp.html
title: test/unionfind_with_potential_non_commutative_group.test.cpp
---
