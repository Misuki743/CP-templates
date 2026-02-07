---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_auxiliary_tree.test.cpp
    title: test/mytest_auxiliary_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree.test.cpp
    title: test/mytest_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree_diameter.test.cpp
    title: test/mytest_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/enumerate_unlabel_rooted_tree.cpp\"\n//number\
    \ of unlabel rooted tree (1-based)\n//1, 1, 2, 4, 9,\n//20, 48, 115, 286, 719,\n\
    //1842, 4766, 12486, 32973, 87811,\n//235381, 634847, 1721159, 4688676, 12826228,\n\
    //35221832, 97055181, 268282855, 743724984, 2067174645\n\n//root is 0\ntemplate<typename\
    \ F>\nrequires invocable<F, vector<vector<int>>>\nvoid enumerate_unlabel_rooted_tree(int\
    \ n, F f) {\n  const int LIM = 25;\n  assert(0 < n and n <= LIM);\n\n  vector\
    \ hash(1, array<int, LIM>{-1});\n  array<int, LIM + 2> st;\n  fill(st.begin(),\
    \ st.end(), INT_MAX);\n  st[0] = -1, st[1] = 0;\n\n  auto size = [&](int id) {\n\
    \    int r = 1;\n    while(st[r] <= id) r++;\n    return r - 1;\n  };\n\n  for(int\
    \ m = 2; m <= n; m++) {\n    st[m] = ssize(hash);\n    array<int, LIM> h;\n  \
    \  int nxt = 0;\n    auto dfs = [&](int pre_id, int sum, auto &self) -> void {\n\
    \      if (sum == 0) {\n        h[nxt++] = -1;\n        hash.emplace_back(h);\n\
    \        nxt--;\n      } else {\n        for(int x = min(pre_id, st[sum + 1] -\
    \ 1); x >= 0; x--) {\n          h[nxt++] = x;\n          self(x, sum - size(x),\
    \ self);\n          nxt--;\n        }\n      }\n    };\n    dfs(INT_MAX, m - 1,\
    \ dfs);\n  }\n  st[n + 1] = ssize(hash);\n\n  for(int id = st[n]; id < st[n +\
    \ 1]; id++) {\n    vector<vector<int>> g(n);\n    int nxt = 0;\n    auto dfs =\
    \ [&](int v, int id, auto &self) -> void {\n      if (id == 0) return;\n     \
    \ for(int i = 0; hash[id][i] != -1; i++) {\n        g[v].emplace_back(nxt), g[nxt].emplace_back(v);\n\
    \        self(nxt++, hash[id][i], self);\n      }\n    };\n    dfs(nxt++, id,\
    \ dfs);\n    f(g);\n  }\n}\n"
  code: "//number of unlabel rooted tree (1-based)\n//1, 1, 2, 4, 9,\n//20, 48, 115,\
    \ 286, 719,\n//1842, 4766, 12486, 32973, 87811,\n//235381, 634847, 1721159, 4688676,\
    \ 12826228,\n//35221832, 97055181, 268282855, 743724984, 2067174645\n\n//root\
    \ is 0\ntemplate<typename F>\nrequires invocable<F, vector<vector<int>>>\nvoid\
    \ enumerate_unlabel_rooted_tree(int n, F f) {\n  const int LIM = 25;\n  assert(0\
    \ < n and n <= LIM);\n\n  vector hash(1, array<int, LIM>{-1});\n  array<int, LIM\
    \ + 2> st;\n  fill(st.begin(), st.end(), INT_MAX);\n  st[0] = -1, st[1] = 0;\n\
    \n  auto size = [&](int id) {\n    int r = 1;\n    while(st[r] <= id) r++;\n \
    \   return r - 1;\n  };\n\n  for(int m = 2; m <= n; m++) {\n    st[m] = ssize(hash);\n\
    \    array<int, LIM> h;\n    int nxt = 0;\n    auto dfs = [&](int pre_id, int\
    \ sum, auto &self) -> void {\n      if (sum == 0) {\n        h[nxt++] = -1;\n\
    \        hash.emplace_back(h);\n        nxt--;\n      } else {\n        for(int\
    \ x = min(pre_id, st[sum + 1] - 1); x >= 0; x--) {\n          h[nxt++] = x;\n\
    \          self(x, sum - size(x), self);\n          nxt--;\n        }\n      }\n\
    \    };\n    dfs(INT_MAX, m - 1, dfs);\n  }\n  st[n + 1] = ssize(hash);\n\n  for(int\
    \ id = st[n]; id < st[n + 1]; id++) {\n    vector<vector<int>> g(n);\n    int\
    \ nxt = 0;\n    auto dfs = [&](int v, int id, auto &self) -> void {\n      if\
    \ (id == 0) return;\n      for(int i = 0; hash[id][i] != -1; i++) {\n        g[v].emplace_back(nxt),\
    \ g[nxt].emplace_back(v);\n        self(nxt++, hash[id][i], self);\n      }\n\
    \    };\n    dfs(nxt++, id, dfs);\n    f(g);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_unlabel_rooted_tree.cpp
  requiredBy: []
  timestamp: '2026-01-29 17:21:40+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_tree_diameter.test.cpp
  - test/mytest_tree.test.cpp
  - test/mytest_auxiliary_tree.test.cpp
documentation_of: enumerate/enumerate_unlabel_rooted_tree.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_unlabel_rooted_tree.cpp
- /library/enumerate/enumerate_unlabel_rooted_tree.cpp.html
title: enumerate/enumerate_unlabel_rooted_tree.cpp
---
