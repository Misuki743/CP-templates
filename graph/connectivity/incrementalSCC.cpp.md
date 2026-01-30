---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/connectivity/incrementalSCC.cpp\"\n//#include \"ds/DSU.cpp\"\
    \n//#include \"graph/SCC.cpp\"\n\nvector<array<int, 3>> incrementalSCC(vector<array<int,\
    \ 2>> _e, int n) {\n  vector<array<int, 3>> e(ssize(_e));\n  for(int i = 0; auto\
    \ [u, v] : _e)\n    e[i] = {u, v, i}, i++;\n\n  DSU dsu(n);\n  vector<array<int,\
    \ 3>> ret;\n  vector<int> mp(n, -1);\n  auto calc = [&](int l, int r, vector<array<int,\
    \ 3>> e, auto &&self) -> void {\n    if (l + 1 == r) return;\n\n    int mid =\
    \ (l + r) / 2;\n\n    vector<array<int, 3>> el, er;\n    {\n      auto ep = e;\n\
    \      int nxt = 0;\n      for(auto &x : ep) for(int &v : x | views::take(2))\
    \ {\n        v = dsu.query(v);\n        if (mp[v] == -1) mp[v] = nxt++;\n    \
    \    v = mp[v];\n      }\n      for(auto &x : e) for(int &v : x | views::take(2))\
    \ mp[dsu.query(v)] = -1;\n      vector<vector<int>> g(nxt);\n      for(auto &[u,\
    \ v, t] : ep)\n        if (t <= mid)\n          g[u].emplace_back(v);\n      auto\
    \ gId = SCC(g).groupId;\n      for(int i = 0; auto &[u, v, t] : ep)\n        (gId[u]\
    \ == gId[v] ? el : er).push_back(e[i++]);\n    }\n\n    self(l, mid, el, self);\n\
    \n    for(auto [u, v, t] : el)\n      if (dsu.merge(u, v))\n        ret.push_back({u,\
    \ v, mid});\n\n    self(mid, r, er, self);\n  };\n\n  calc(0, ssize(e), e, calc);\n\
    \n  return ret;\n}\n"
  code: "//#include \"ds/DSU.cpp\"\n//#include \"graph/SCC.cpp\"\n\nvector<array<int,\
    \ 3>> incrementalSCC(vector<array<int, 2>> _e, int n) {\n  vector<array<int, 3>>\
    \ e(ssize(_e));\n  for(int i = 0; auto [u, v] : _e)\n    e[i] = {u, v, i}, i++;\n\
    \n  DSU dsu(n);\n  vector<array<int, 3>> ret;\n  vector<int> mp(n, -1);\n  auto\
    \ calc = [&](int l, int r, vector<array<int, 3>> e, auto &&self) -> void {\n \
    \   if (l + 1 == r) return;\n\n    int mid = (l + r) / 2;\n\n    vector<array<int,\
    \ 3>> el, er;\n    {\n      auto ep = e;\n      int nxt = 0;\n      for(auto &x\
    \ : ep) for(int &v : x | views::take(2)) {\n        v = dsu.query(v);\n      \
    \  if (mp[v] == -1) mp[v] = nxt++;\n        v = mp[v];\n      }\n      for(auto\
    \ &x : e) for(int &v : x | views::take(2)) mp[dsu.query(v)] = -1;\n      vector<vector<int>>\
    \ g(nxt);\n      for(auto &[u, v, t] : ep)\n        if (t <= mid)\n          g[u].emplace_back(v);\n\
    \      auto gId = SCC(g).groupId;\n      for(int i = 0; auto &[u, v, t] : ep)\n\
    \        (gId[u] == gId[v] ? el : er).push_back(e[i++]);\n    }\n\n    self(l,\
    \ mid, el, self);\n\n    for(auto [u, v, t] : el)\n      if (dsu.merge(u, v))\n\
    \        ret.push_back({u, v, mid});\n\n    self(mid, r, er, self);\n  };\n\n\
    \  calc(0, ssize(e), e, calc);\n\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/connectivity/incrementalSCC.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/connectivity/incrementalSCC.cpp
layout: document
redirect_from:
- /library/graph/connectivity/incrementalSCC.cpp
- /library/graph/connectivity/incrementalSCC.cpp.html
title: graph/connectivity/incrementalSCC.cpp
---
