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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../factorize_pollard_rho.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../numtheory/factorize_sqrt.cpp\"\n#include \"\
    ../factorize_pollard_rho.cpp\"\n\nvoid check(int64_t x) {\n  vc<int64_t> pf;\n\
    \  for(auto p : factor(x))\n    pf.eb(p);\n  ranges::sort(pf);\n  vc<pair<int64_t,\
    \ int64_t>> pf2;\n  for(int i = 0, j = 0; i < ssize(pf); i = j) {\n    while(j\
    \ < ssize(pf) and pf[i] == pf[j]) j++;\n    pf2.emplace_back(pf[i], j - i);\n\
    \  }\n  pf.resize(unique(pf.begin(), pf.end()) - pf.begin());\n  vc<int64_t> divisor;\n\
    \  auto dfs = [&](int i, int64_t prod, auto &self) -> void {\n    if (i == ssize(pf))\
    \ {\n      divisor.emplace_back(prod);\n      return;\n    }\n    for(int j =\
    \ 0; j <= pf2[i].second; j++) {\n      if (j) prod *= pf2[i].first;\n      self(i\
    \ + 1, prod, self);\n    }\n  };\n  dfs(0, 1, dfs);\n  ranges::sort(divisor);\n\
    \  \n  assert(pf2 == prime_factorize_sqrt(x));\n  assert(pf == prime_factor_sqrt(x));\n\
    \  assert(divisor == divisor_sqrt(x));\n}\n\nvoid check_small() {\n  for(int64_t\
    \ x = 1; x < (1 << 10); x++)\n    check(x);\n}\n\nvoid check_large() {\n  mt19937_64\
    \ rng(clock);\n  for(int64_t l = (1ll << 10); l < (1ll << 53); l <<= 1)\n    for(int\
    \ i = 0; i < 10; i++)\n      check(rng() % l + l);\n}\n\nvoid a_plus_b() {\n \
    \ int x, y; cin >> x >> y;\n  cout << x + y << '\\n';\n}\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  check_small();\n  check_large();\n\
    \  a_plus_b();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest_factorize_sqrt.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest_factorize_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_factorize_sqrt.test.cpp
- /verify/test/mytest_factorize_sqrt.test.cpp.html
title: test/mytest_factorize_sqrt.test.cpp
---
