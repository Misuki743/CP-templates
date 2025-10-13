---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/frequency_table_of_tree_distance.test.cpp
    title: test/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds_problem/frequency_of_tree_distance.cpp\"\ntemplate<int32_t\
    \ k = 23, int32_t c = 119, int32_t r = 3, class Mint = MontgomeryModInt<998244353>>\n\
    vector<Mint> frequency_of_tree_distance(vector<vector<int>> g) {\n  const int\
    \ n = ssize(g);\n  NTT<k, c, r, Mint> Ntt;\n\n  auto [T, R] = centroidTree(g);\n\
    \  vector<bool> vis(n, false);\n  auto calc = [&](int s, int d0) {\n    vector<Mint>\
    \ freq(1);\n    auto dfs = [&](int v, int p, int d, auto &self) -> void {\n  \
    \    if (ssize(freq) <= d) freq.eb(0);\n      if (d > 0) freq[d] += 1;\n     \
    \ for(int x : g[v])\n        if (x != p and !vis[x])\n          self(x, v, d +\
    \ 1, self);\n    };\n    dfs(s, -1, d0, dfs);\n    return freq;\n  };\n\n  auto\
    \ self_conv = [&](vector<Mint> f) {\n    int sz = bit_ceil(2 * f.size());\n  \
    \  f.resize(sz);\n    Ntt.ntt(f, false);\n    for(Mint &x : f) x *= x;\n    Ntt.ntt(f,\
    \ true);\n    return f;\n  };\n\n  vector<Mint> ans(n);\n  auto dfs = [&](int\
    \ v, int p, auto &self) -> void {\n    dbg(v);\n    {\n      auto freq_all = calc(v,\
    \ 0);\n      freq_all[0] = 1;\n      auto F = self_conv(freq_all);\n      for(int\
    \ i = 0; i < n and i < ssize(F); i++)\n        ans[i] += F[i];\n      vis[v] =\
    \ true;\n      for(int x : g[v]) {\n        if (vis[x]) continue;\n        auto\
    \ G = self_conv(calc(x, 1));\n        for(int i = 0; i < n and i < ssize(G); i++)\n\
    \          ans[i] -= G[i];\n      }\n    }\n    for(int x : T[v])\n      if (x\
    \ != p)\n        self(x, v, self);\n  };\n  dfs(R, -1, dfs);\n\n  ans.erase(ans.begin());\n\
    \  for(Mint &x : ans) x *= (Mint::get_mod() + 1) / 2;\n  return ans;\n}\n"
  code: "template<int32_t k = 23, int32_t c = 119, int32_t r = 3, class Mint = MontgomeryModInt<998244353>>\n\
    vector<Mint> frequency_of_tree_distance(vector<vector<int>> g) {\n  const int\
    \ n = ssize(g);\n  NTT<k, c, r, Mint> Ntt;\n\n  auto [T, R] = centroidTree(g);\n\
    \  vector<bool> vis(n, false);\n  auto calc = [&](int s, int d0) {\n    vector<Mint>\
    \ freq(1);\n    auto dfs = [&](int v, int p, int d, auto &self) -> void {\n  \
    \    if (ssize(freq) <= d) freq.eb(0);\n      if (d > 0) freq[d] += 1;\n     \
    \ for(int x : g[v])\n        if (x != p and !vis[x])\n          self(x, v, d +\
    \ 1, self);\n    };\n    dfs(s, -1, d0, dfs);\n    return freq;\n  };\n\n  auto\
    \ self_conv = [&](vector<Mint> f) {\n    int sz = bit_ceil(2 * f.size());\n  \
    \  f.resize(sz);\n    Ntt.ntt(f, false);\n    for(Mint &x : f) x *= x;\n    Ntt.ntt(f,\
    \ true);\n    return f;\n  };\n\n  vector<Mint> ans(n);\n  auto dfs = [&](int\
    \ v, int p, auto &self) -> void {\n    dbg(v);\n    {\n      auto freq_all = calc(v,\
    \ 0);\n      freq_all[0] = 1;\n      auto F = self_conv(freq_all);\n      for(int\
    \ i = 0; i < n and i < ssize(F); i++)\n        ans[i] += F[i];\n      vis[v] =\
    \ true;\n      for(int x : g[v]) {\n        if (vis[x]) continue;\n        auto\
    \ G = self_conv(calc(x, 1));\n        for(int i = 0; i < n and i < ssize(G); i++)\n\
    \          ans[i] -= G[i];\n      }\n    }\n    for(int x : T[v])\n      if (x\
    \ != p)\n        self(x, v, self);\n  };\n  dfs(R, -1, dfs);\n\n  ans.erase(ans.begin());\n\
    \  for(Mint &x : ans) x *= (Mint::get_mod() + 1) / 2;\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/frequency_of_tree_distance.cpp
  requiredBy: []
  timestamp: '2025-10-07 20:13:58+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/frequency_table_of_tree_distance.test.cpp
documentation_of: ds_problem/frequency_of_tree_distance.cpp
layout: document
redirect_from:
- /library/ds_problem/frequency_of_tree_distance.cpp
- /library/ds_problem/frequency_of_tree_distance.cpp.html
title: ds_problem/frequency_of_tree_distance.cpp
---
