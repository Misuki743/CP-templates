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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph/eulerianTrail.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/eulerianTrail.cpp\"\n\n\
    signed main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t; cin\
    \ >> t;\n  while(t--) {\n    int n, m; cin >> n >> m;\n    vector<array<int, 2>>\
    \ e(m);\n    for(auto &[u, v] : e)\n      cin >> u >> v;\n    auto [vid, eid]\
    \ = eulerianTrail<true>(n, e);\n    if (vid.empty()) {\n      cout << \"No\\n\"\
    ; \n    } else {\n      cout << \"Yes\\n\";\n      cout << vid << '\\n';\n   \
    \   cout << eid << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/eulerian_trail_directed.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/eulerian_trail_directed.test.cpp
layout: document
redirect_from:
- /verify/test/eulerian_trail_directed.test.cpp
- /verify/test/eulerian_trail_directed.test.cpp.html
title: test/eulerian_trail_directed.test.cpp
---
