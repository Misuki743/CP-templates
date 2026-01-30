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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph/2sat.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../graph/2sat.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(0);\n\n  string p, cnf; cin >> p >> cnf;\n  int n, m; cin >> n >> m;\n\
    \n  TwoSat ts(n);\n  while(m--) {\n    int a, b, c; cin >> a >> b >> c;\n    a\
    \ = (a > 0 ? a - 1 : ~(-(a + 1)));\n    b = (b > 0 ? b - 1 : ~(-(b + 1)));\n \
    \   ts.either(a, b);\n  }\n\n  if (ts.solve()) {\n    cout << \"s SATISFIABLE\\\
    n\";\n    cout << \"v \";\n    for(int i = 0; i < n; i++)\n      cout << (ts.values[i]\
    \ ? i + 1 : -(i + 1)) << ' ';\n    cout << 0 << '\\n';\n  } else {\n    cout <<\
    \ \"s UNSATISFIABLE\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/two_sat.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/two_sat.test.cpp
- /verify/test/two_sat.test.cpp.html
title: test/two_sat.test.cpp
---
