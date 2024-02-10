---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../actedmonoid/affineSum.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../ds/slidingWindowAggregation.cpp\"\n#include \"../actedmonoid/affineSum.cpp\"\
    \n\nusing am = actedMonoid_affineSum<mint>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  SWAG<am::T, am::Tid, am::Top> swag;\n\n  int q; cin >> q;\n\
    \  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      mint a, b; cin\
    \ >> a >> b;\n      swag.push(am::T{a, b});\n    } else if (t == 1) {\n      swag.pop();\n\
    \    } else if (t == 2) {\n      mint x; cin >> x;\n      cout << am::Top(am::T{0,\
    \ x}, swag.query())[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/queue_operate_all_composite.test.cpp
- /verify/test/queue_operate_all_composite.test.cpp.html
title: test/queue_operate_all_composite.test.cpp
---
