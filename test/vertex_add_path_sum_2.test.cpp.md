---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/staticTopTree2.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../ds/staticTopTree2.cpp\"\n#include\
    \ \"../ds/STT_pathAggregate.cpp\"\n\nll id() { return 0ll; }\nll op(const ll &a,\
    \ const ll &b) { return a + b; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a) cin >> x;\n  auto g = readGraph<false>(n, n - 1, 0);\n\n  STT_pathAggregate<ll,\
    \ id, op> stt(g, a);\n\n  while(q--) {\n    int op; cin >> op;\n    if (op ==\
    \ 0) {\n      int p, x; cin >> p >> x;\n      stt.set(p, a[p] += x);\n    } else\
    \ {\n      int u, v; cin >> u >> v;\n      cout << stt.query(u, v) << '\\n';\n\
    \    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/vertex_add_path_sum_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_add_path_sum_2.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum_2.test.cpp
- /verify/test/vertex_add_path_sum_2.test.cpp.html
title: test/vertex_add_path_sum_2.test.cpp
---
