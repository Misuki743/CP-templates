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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph/prufer_recover.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../graph/prufer_recover.cpp\"\n#include \"../enumerate/enumerate_bit.cpp\"\
    \n#include \"../enumerate/enumerate_twelvefold.cpp\"\n#include \"../enumerate/enumerate_label_tree.cpp\"\
    \n#include \"../enumerate/enumerate_unlabel_rooted_tree.cpp\"\n#include \"../graph/tree.cpp\"\
    \n\nvoid check(vector<vector<int>> g, int root) {\n  const int n = ssize(g);\n\
    \  vector<int> p(n, root), sz(n, 1), dep(n);\n  auto dfs = [&](int v, auto &self)\
    \ -> void {\n    for(int x : g[v]) {\n      if (x == p[v]) continue;\n      p[x]\
    \ = v, dep[x] = dep[v] + 1;\n      self(x, self);\n      sz[v] += sz[x];\n   \
    \ }\n  };\n  dfs(root, dfs);\n\n  vector<pii> e;\n  for(int u = 0; u < n; u++)\n\
    \    for(int v : g[u])\n      if (u < v)\n        e.emplace_back(u, v);\n\n  tree\
    \ T(e, root);\n  assert(tie(T.p, T.sz, T.dep) == tie(p, sz, dep));\n}\n\nauto\
    \ random_relabel(vector<vector<int>> g) {\n  mt19937 rng(clock);\n  const int\
    \ n = ssize(g);\n  vector<int> p(n);\n  iota(p.begin(), p.end(), 0);\n  shuffle(p.begin(),\
    \ p.end(), rng);\n  vector<vector<int>> g2(n);\n  for(int u = 0; u < n; u++)\n\
    \    for(int v : g[u])\n      g2[p[u]].eb(p[v]);\n  return pair(g2, p[0]);\n}\n\
    \nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n}\n\
    \nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  mt19937 rng(clock);\n\
    \n  for(int n = 1; n <= 7; n++) {\n    enumerate_label_tree(n, [&](vector<vector<int>>\
    \ g) {\n      for(int root = 0; root < n; root++)\n        check(g, root);\n \
    \   });\n  }\n\n  for(int n = 1; n <= 15; n++) {\n    enumerate_unlabel_rooted_tree(n,\
    \ [&](vector<vector<int>> g) {\n      check(g, 0);\n      auto [gp, root] = random_relabel(g);\n\
    \      check(gp, root);\n    });\n  }\n\n  //path\n  for(int n = 1; n <= 100;\
    \ n++) {\n    vector<vector<int>> g(n);\n    for(int i = 1; i < n; i++)\n    \
    \  g[i].emplace_back(i - 1), g[i - 1].emplace_back(i);\n    check(g, 0);\n   \
    \ check(g, n / 2);\n    check(g, n - 1);\n    auto [gp, root] = random_relabel(g);\n\
    \    check(gp, root);\n  }\n\n  //star\n  for(int n = 2; n <= 100; n++) {\n  \
    \  for(int root : {0, n / 2, n - 1}) {\n      vector<vector<int>> g(n);\n    \
    \  for(int i = 0; i < n; i++)\n        if (i != root)\n          g[root].emplace_back(i),\
    \ g[i].emplace_back(root);\n      check(g, root);\n    }\n  }\n\n  //almost path\n\
    \  for(int tc = 0; tc < 30; tc++) {\n    int n = 500;\n    vector<vector<int>>\
    \ g(n);\n    for(int v = 1; v < n; v++) {\n      int x = rng() % min(v, 5);\n\
    \      g[v].emplace_back(x), g[x].emplace_back(v);\n    }\n    check(g, 0);\n\
    \    auto [gp, root] = random_relabel(g);\n    check(gp, root);\n  }\n\n  a_plus_b();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest_tree.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_tree.test.cpp
- /verify/test/mytest_tree.test.cpp.html
title: test/mytest_tree.test.cpp
---
