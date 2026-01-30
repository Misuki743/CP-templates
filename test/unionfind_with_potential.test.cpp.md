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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/potentialDSU.cpp\"\n#include\
    \ \"../modint/MontgomeryModInt.cpp\"\n\nmint id() { return 0; }\nmint op(const\
    \ mint &a, const mint &b) { return a + b; }\nmint inv(const mint &a) { return\
    \ mint(0) - a; }\n\nint main() {\n  int n, q; cin >> n >> q;\n\n  DSU<mint, id,\
    \ op, inv> dsu(n);\n  while(q--) {\n    int t, u, v; cin >> t >> u >> v;\n   \
    \ if (t == 0) {\n      int x; cin >> x;\n      cout << dsu.merge(v, u, x) << '\\\
    n';\n    } else {\n      if (dsu.query(u) != dsu.query(v))\n        cout << -1\
    \ << '\\n';\n      else\n        cout << dsu.query(v, u) << '\\n';\n    }\n  }\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/unionfind_with_potential.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unionfind_with_potential.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind_with_potential.test.cpp
- /verify/test/unionfind_with_potential.test.cpp.html
title: test/unionfind_with_potential.test.cpp
---
