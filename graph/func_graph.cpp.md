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
  bundledCode: "#line 1 \"graph/func_graph.cpp\"\nstruct func_graph {\n  vector<int>\
    \ a;\n  const int n;\n  vector<bool> in_cyc;\n  func_graph(vector<int> _a) : a(_a),\
    \ n(size(a)), in_cyc(n, false) {\n    vector<bool> in_s(n, false), vis(n, false);\n\
    \    vector<int> s;\n    auto dfs = [&](int v, auto &&self) -> void {\n      vis[v]\
    \ = true;\n      s.emplace_back(v);\n      in_s[v] = true;\n      if (in_s[a[v]])\
    \ {\n        in_cyc[a[v]] = true;\n        while(s.back() != a[v]) {\n       \
    \   in_cyc[s.back()] = true;\n          in_s[s.back()] = false;\n          s.pop_back();\n\
    \        }\n      } else if (!vis[a[v]]) {\n        self(a[v], self);\n      }\n\
    \    };\n\n    for(int v = 0; v < n; v++) {\n      if (vis[v]) continue;\n   \
    \   dfs(v, dfs);\n      while(!s.empty()) {\n        in_s[s.back()] = false;\n\
    \        s.pop_back();\n      }\n    }\n  }\n};\n"
  code: "struct func_graph {\n  vector<int> a;\n  const int n;\n  vector<bool> in_cyc;\n\
    \  func_graph(vector<int> _a) : a(_a), n(size(a)), in_cyc(n, false) {\n    vector<bool>\
    \ in_s(n, false), vis(n, false);\n    vector<int> s;\n    auto dfs = [&](int v,\
    \ auto &&self) -> void {\n      vis[v] = true;\n      s.emplace_back(v);\n   \
    \   in_s[v] = true;\n      if (in_s[a[v]]) {\n        in_cyc[a[v]] = true;\n \
    \       while(s.back() != a[v]) {\n          in_cyc[s.back()] = true;\n      \
    \    in_s[s.back()] = false;\n          s.pop_back();\n        }\n      } else\
    \ if (!vis[a[v]]) {\n        self(a[v], self);\n      }\n    };\n\n    for(int\
    \ v = 0; v < n; v++) {\n      if (vis[v]) continue;\n      dfs(v, dfs);\n    \
    \  while(!s.empty()) {\n        in_s[s.back()] = false;\n        s.pop_back();\n\
    \      }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/func_graph.cpp
  requiredBy: []
  timestamp: '2024-12-21 17:17:42+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/func_graph.cpp
layout: document
redirect_from:
- /library/graph/func_graph.cpp
- /library/graph/func_graph.cpp.html
title: graph/func_graph.cpp
---
