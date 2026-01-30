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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/staticTopTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n\n#include \"../default/t.cpp\"\n#define eb emplace_back\n#define pb push_back\n\
    #include \"../modint/MontgomeryModInt.cpp\"\n#include \"../ds/staticTopTree.cpp\"\
    \n#include \"../dp/dynamicTreeDP.cpp\"\n\nstruct M {\n  mint a, b, ans, sz;\n\
    };\n\nM rake(const M &a, const M &b) {\n  return M{a.a, a.b, a.ans + b.ans, a.sz\
    \ + b.sz};\n}\nM compress(const M &a, const M &b) {\n  return M{a.a * b.a, a.a\
    \ * b.b + a.b, a.ans + b.ans * a.a + a.b * b.sz, a.sz + b.sz};\n}\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >>\
    \ q;\n  vector<mint> a(n);\n  for(mint &x : a) cin >> x;\n\n  vector<array<int,\
    \ 4>> uvbc(n - 1);\n  for(auto &[u, v, b, c] : uvbc)\n    cin >> u >> v >> b >>\
    \ c;\n\n  vector<vector<int>> g(n);\n  for(auto [u, v, _, __] : uvbc)\n    g[u].eb(v),\
    \ g[v].eb(u);\n  uvbc.pb({-1, 0, 1, 0});\n\n  static_top_tree stt(g);\n\n  vector<int>\
    \ eid(n);\n  for(int i = 0; auto &[u, v, _, __] : uvbc) {\n    if (stt.r[v] ==\
    \ u) swap(u, v);\n    eid[u] = i++;\n  }\n\n  auto get = [&](int v) {\n    auto\
    \ [_, __, b, c] = uvbc[eid[v]];\n    return M{b, c, a[v] * b + c, 1};\n  };\n\n\
    \  vector<M> init(n);\n  for(int i = 0; i < n; i++)\n    init[i] = get(i);\n\n\
    \  dynamic_tree_dp<M, rake, compress> ddp(g, init);\n\n  while(q--) {\n    int\
    \ op; cin >> op;\n    if (op == 0) {\n      int w, x; cin >> w >> x;\n      a[w]\
    \ = x;\n      ddp.set(w, get(w));\n    } else {\n      int e, y, z; cin >> e >>\
    \ y >> z;\n      auto &[u, _, b, c] = uvbc[e];\n      b = y, c = z;\n      ddp.set(u,\
    \ get(u));\n    }\n    cout << ddp.query().ans << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/test/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/test/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
