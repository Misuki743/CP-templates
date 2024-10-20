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
  bundledCode: "#line 1 \"poly/pref_suf_prod_eval.cpp\"\ntemplate<class Mint>\nvector<Mint>\
    \ pref_suf_prod_eval(int k0, FPS<Mint> F, vector<FPS<Mint>> L, vector<FPS<Mint>>\
    \ R = {}) {\n  vector<int> lc, rc, dp;\n  vector<FPS<Mint>> L_prod, R_prod;\n\
    \  {\n    auto dfs = [&](int l, int r, auto &&self) -> int {\n      if (l + 1\
    \ == r) {\n        lc.emplace_back(-1), rc.emplace_back(-1);\n        L_prod.emplace_back(L[l]);\n\
    \        if (!R.empty()) R_prod.emplace_back(R[l]);\n        dp.emplace_back();\n\
    \      } else {\n        int mid = (l + r) / 2;\n        int a = self(l, mid,\
    \ self), b = self(mid, r, self);\n        lc.emplace_back(a), rc.emplace_back(b);\n\
    \        L_prod.emplace_back(L_prod[a] * L_prod[b]);\n        if (!R.empty())\
    \ R_prod.emplace_back(R_prod[a] * R_prod[b]);\n        dp.emplace_back(max(dp[a]\
    \ + (R.empty() ? 0 : ssize(R_prod[b]) - 1), dp[b] + ssize(L_prod[a]) - 1));\n\
    \      }\n      return size(lc) - 1;\n    };\n\n    dfs(0, size(L), dfs);\n  }\n\
    \n  vector<Mint> ret;\n  ret.reserve(size(L));\n  auto dfs = [&](int i, FPS<Mint>\
    \ G, auto &&self) -> void {\n    if (lc[i] == -1) {\n      ret.emplace_back(G[0]);\n\
    \    } else {\n      {\n        auto H = R.empty() ? G : G * R_prod[rc[i]];\n\
    \        int b = max(0, (int)(ssize(G) - 1 - dp[lc[i]]));\n        H.erase(H.begin(),\
    \ H.begin() + b);\n        self(lc[i], H, self);\n      }\n      {\n        auto\
    \ H = G * L_prod[lc[i]];\n        int b = max(0, (int)(ssize(G) - 1 - dp[rc[i]]));\n\
    \        H.erase(H.begin(), H.begin() + b);\n        self(rc[i], H, self);\n \
    \     }\n    }\n  };\n\n  F.resize(k0 + 1);\n  dfs(size(lc) - 1, F, dfs);\n\n\
    \  return ret;\n}\n"
  code: "template<class Mint>\nvector<Mint> pref_suf_prod_eval(int k0, FPS<Mint> F,\
    \ vector<FPS<Mint>> L, vector<FPS<Mint>> R = {}) {\n  vector<int> lc, rc, dp;\n\
    \  vector<FPS<Mint>> L_prod, R_prod;\n  {\n    auto dfs = [&](int l, int r, auto\
    \ &&self) -> int {\n      if (l + 1 == r) {\n        lc.emplace_back(-1), rc.emplace_back(-1);\n\
    \        L_prod.emplace_back(L[l]);\n        if (!R.empty()) R_prod.emplace_back(R[l]);\n\
    \        dp.emplace_back();\n      } else {\n        int mid = (l + r) / 2;\n\
    \        int a = self(l, mid, self), b = self(mid, r, self);\n        lc.emplace_back(a),\
    \ rc.emplace_back(b);\n        L_prod.emplace_back(L_prod[a] * L_prod[b]);\n \
    \       if (!R.empty()) R_prod.emplace_back(R_prod[a] * R_prod[b]);\n        dp.emplace_back(max(dp[a]\
    \ + (R.empty() ? 0 : ssize(R_prod[b]) - 1), dp[b] + ssize(L_prod[a]) - 1));\n\
    \      }\n      return size(lc) - 1;\n    };\n\n    dfs(0, size(L), dfs);\n  }\n\
    \n  vector<Mint> ret;\n  ret.reserve(size(L));\n  auto dfs = [&](int i, FPS<Mint>\
    \ G, auto &&self) -> void {\n    if (lc[i] == -1) {\n      ret.emplace_back(G[0]);\n\
    \    } else {\n      {\n        auto H = R.empty() ? G : G * R_prod[rc[i]];\n\
    \        int b = max(0, (int)(ssize(G) - 1 - dp[lc[i]]));\n        H.erase(H.begin(),\
    \ H.begin() + b);\n        self(lc[i], H, self);\n      }\n      {\n        auto\
    \ H = G * L_prod[lc[i]];\n        int b = max(0, (int)(ssize(G) - 1 - dp[rc[i]]));\n\
    \        H.erase(H.begin(), H.begin() + b);\n        self(rc[i], H, self);\n \
    \     }\n    }\n  };\n\n  F.resize(k0 + 1);\n  dfs(size(lc) - 1, F, dfs);\n\n\
    \  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/pref_suf_prod_eval.cpp
  requiredBy: []
  timestamp: '2024-10-20 15:27:14+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/pref_suf_prod_eval.cpp
layout: document
redirect_from:
- /library/poly/pref_suf_prod_eval.cpp
- /library/poly/pref_suf_prod_eval.cpp.html
title: poly/pref_suf_prod_eval.cpp
---
