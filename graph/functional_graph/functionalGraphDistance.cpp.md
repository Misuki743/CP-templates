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
  bundledCode: "#line 1 \"graph/functional_graph/functionalGraphDistance.cpp\"\nstruct\
    \ functionalGraphDistance {\n  int n;\n  vector<int> ccId, dep, treeId, l, tin,\
    \ tout, cycSize;\n  vector<bool> onCycle;\n  functionalGraphDistance(vector<int>\
    \ f) : n(ssize(f)), ccId(n, -1), \n  dep(n), treeId(n, -1), l(n), tin(n), tout(n),\
    \ cycSize(n), onCycle(n, false) {\n    vector<vector<int>> g(n);\n    for(int\
    \ i = 0; i < n; i++) {\n      g[f[i]].emplace_back(i);\n      g[i].emplace_back(f[i]);\n\
    \    }\n\n    vector<bool> inSta(n, false);\n    int nxt = 0;\n    auto calc =\
    \ [&](int s) -> void {\n      {\n        auto dfs = [&](int v, auto self) -> void\
    \ {\n          ccId[v] = nxt;\n          for(int x : g[v])\n            if (ccId[x]\
    \ == -1)\n              self(x, self);\n        };\n        dfs(s, dfs);\n   \
    \   }\n\n      vector<int> cycle;\n      {\n        vector<int> sta;\n       \
    \ auto dfs = [&](int v, auto self) -> void {\n          if (inSta[v]) {\n    \
    \        while(sta.back() != v) {\n              cycle.emplace_back(sta.back());\n\
    \              sta.pop_back();\n            }\n            cycle.emplace_back(sta.back());\n\
    \            ranges::reverse(cycle);\n          } else {\n            sta.emplace_back(v);\n\
    \            inSta[v] = true;\n            self(f[v], self);\n          }\n  \
    \      };\n        dfs(s, dfs);\n      }\n\n      for(int i = 0; i < ssize(cycle);\
    \ i++)\n        onCycle[cycle[i]] = true, l[cycle[i]] = i, cycSize[cycle[i]] =\
    \ ssize(cycle);\n\n      {\n        int t = 0;\n        auto dfs = [&](int v,\
    \ int p, int id, auto self) -> void {\n          tin[v] = t++;\n          for(int\
    \ x : g[v]) if (!onCycle[x] and x != p) {\n            treeId[x] = id, dep[x]\
    \ = dep[v] + 1;\n            self(x, v, id, self);\n          }\n          tout[v]\
    \ = t++;\n        };\n        for(int x : cycle) dfs(x, -1, x, dfs);\n      }\n\
    \    };\n\n    for(int v = 0; v < n; v++) {\n      if (ccId[v] == -1) {\n    \
    \    calc(v);\n        nxt++;\n      }\n    }\n  }\n\n  int dis(int u, int v)\
    \ {\n    if (ccId[u] != ccId[v]) return INT_MAX;\n    if (!onCycle[u] and !onCycle[v])\
    \ {\n      if (treeId[u] == treeId[v] and tin[v] <= tin[u] and tout[u] <= tout[v])\n\
    \        return dep[u] - dep[v];\n      else\n        return INT_MAX;\n    } else\
    \ if (onCycle[u] and !onCycle[v]) {\n      return INT_MAX;\n    } else if (!onCycle[u]\
    \ and onCycle[v]) {\n      return dep[u] + (l[v] - l[treeId[u]] + cycSize[v])\
    \ % cycSize[v];\n    } else {\n      return (l[v] - l[u] + cycSize[v]) % cycSize[v];\n\
    \    }\n  }\n};\n"
  code: "struct functionalGraphDistance {\n  int n;\n  vector<int> ccId, dep, treeId,\
    \ l, tin, tout, cycSize;\n  vector<bool> onCycle;\n  functionalGraphDistance(vector<int>\
    \ f) : n(ssize(f)), ccId(n, -1), \n  dep(n), treeId(n, -1), l(n), tin(n), tout(n),\
    \ cycSize(n), onCycle(n, false) {\n    vector<vector<int>> g(n);\n    for(int\
    \ i = 0; i < n; i++) {\n      g[f[i]].emplace_back(i);\n      g[i].emplace_back(f[i]);\n\
    \    }\n\n    vector<bool> inSta(n, false);\n    int nxt = 0;\n    auto calc =\
    \ [&](int s) -> void {\n      {\n        auto dfs = [&](int v, auto self) -> void\
    \ {\n          ccId[v] = nxt;\n          for(int x : g[v])\n            if (ccId[x]\
    \ == -1)\n              self(x, self);\n        };\n        dfs(s, dfs);\n   \
    \   }\n\n      vector<int> cycle;\n      {\n        vector<int> sta;\n       \
    \ auto dfs = [&](int v, auto self) -> void {\n          if (inSta[v]) {\n    \
    \        while(sta.back() != v) {\n              cycle.emplace_back(sta.back());\n\
    \              sta.pop_back();\n            }\n            cycle.emplace_back(sta.back());\n\
    \            ranges::reverse(cycle);\n          } else {\n            sta.emplace_back(v);\n\
    \            inSta[v] = true;\n            self(f[v], self);\n          }\n  \
    \      };\n        dfs(s, dfs);\n      }\n\n      for(int i = 0; i < ssize(cycle);\
    \ i++)\n        onCycle[cycle[i]] = true, l[cycle[i]] = i, cycSize[cycle[i]] =\
    \ ssize(cycle);\n\n      {\n        int t = 0;\n        auto dfs = [&](int v,\
    \ int p, int id, auto self) -> void {\n          tin[v] = t++;\n          for(int\
    \ x : g[v]) if (!onCycle[x] and x != p) {\n            treeId[x] = id, dep[x]\
    \ = dep[v] + 1;\n            self(x, v, id, self);\n          }\n          tout[v]\
    \ = t++;\n        };\n        for(int x : cycle) dfs(x, -1, x, dfs);\n      }\n\
    \    };\n\n    for(int v = 0; v < n; v++) {\n      if (ccId[v] == -1) {\n    \
    \    calc(v);\n        nxt++;\n      }\n    }\n  }\n\n  int dis(int u, int v)\
    \ {\n    if (ccId[u] != ccId[v]) return INT_MAX;\n    if (!onCycle[u] and !onCycle[v])\
    \ {\n      if (treeId[u] == treeId[v] and tin[v] <= tin[u] and tout[u] <= tout[v])\n\
    \        return dep[u] - dep[v];\n      else\n        return INT_MAX;\n    } else\
    \ if (onCycle[u] and !onCycle[v]) {\n      return INT_MAX;\n    } else if (!onCycle[u]\
    \ and onCycle[v]) {\n      return dep[u] + (l[v] - l[treeId[u]] + cycSize[v])\
    \ % cycSize[v];\n    } else {\n      return (l[v] - l[u] + cycSize[v]) % cycSize[v];\n\
    \    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional_graph/functionalGraphDistance.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional_graph/functionalGraphDistance.cpp
layout: document
redirect_from:
- /library/graph/functional_graph/functionalGraphDistance.cpp
- /library/graph/functional_graph/functionalGraphDistance.cpp.html
title: graph/functional_graph/functionalGraphDistance.cpp
---
