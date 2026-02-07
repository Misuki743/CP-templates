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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../numtheory/mu.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../numtheory/mu.cpp\"\n#include \"../numtheory/linear_sieve.cpp\"\
    \n\nvc<pii> factorize(int x) {\n  vc<pii> v;\n  int x0 = x;\n  for(int d = 2;\
    \ d <= x0; d++) {\n    if (x % d == 0) {\n      int f = 0;\n      while(x % d\
    \ == 0)\n        x /= d, f++;\n      v.emplace_back(d, f);\n    }\n  }\n  return\
    \ v;\n}\n\nint mu[1 << 15];\n\ntemplate<int32_t sz = 64>\nvoid check_small() {\n\
    \  if (sz == 0) return;\n  check_small<max(sz - 1, 0)>();\n  auto ls = linear_sieve<sz>();\n\
    \  auto mu2 = mu_table<int>(ls);\n  for(int i = 0; i < sz; i++)\n    assert(mu[i]\
    \ == mu2[i]);\n}\n\ntemplate<int32_t sz = (1 << 15)>\nvoid check_power() {\n \
    \ if (sz == 0) return;\n  check_power<max(sz >> 1, 0)>();\n  auto ls = linear_sieve<sz>();\n\
    \  auto mu2 = mu_table<int>(ls);\n  for(int i = 0; i < sz; i++)\n    assert(mu[i]\
    \ == mu2[i]);\n}\n\nvoid a_plus_b() {\n  int x, y; cin >> x >> y;\n  cout << x\
    \ + y << '\\n';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  for(int x = 1; x < (1 << 15); x++) {\n    mu[x] = 1;\n    for(auto [p, f]\
    \ : factorize(x)) {\n      if (f == 1) mu[x] = -mu[x];\n      else mu[x] = 0;\n\
    \    }\n  }\n\n  check_small();\n  check_power();\n  a_plus_b();\n\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest_mu_table.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest_mu_table.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_mu_table.test.cpp
- /verify/test/mytest_mu_table.test.cpp.html
title: test/mytest_mu_table.test.cpp
---
