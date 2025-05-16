---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bipartitematching_2.test.cpp
    title: test/bipartitematching_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/hopcroftKarp.cpp\"\n//source: KACTL\n\n/**\n * Author:\
    \ Chen Xing\n * Date: 2009-10-13\n * License: CC0\n * Source: N/A\n * Description:\
    \ Fast bipartite matching algorithm. Graph $g$ should be a list\n * of neighbors\
    \ of the left partition, and $btoa$ should be a vector full of\n * -1's of the\
    \ same size as the right partition. Returns the size of\n * the matching. $btoa[i]$\
    \ will be the match for vertex $i$ on the right side,\n * or $-1$ if it's not\
    \ matched.\n * Usage: vi btoa(m, -1); hopcroftKarp(g, btoa);\n * Time: O(\\sqrt{V}E)\n\
    \ * Status: stress-tested by MinimumVertexCover, and tested on oldkattis.adkbipmatch\
    \ and SPOJ:MATCHING\n */\n\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n\
    #define all(x) begin(x), end(x)\n#define sz(x) (int)(x).size()\ntypedef vector<int>\
    \ vi;\n\nbool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {\n  if\
    \ (A[a] != L) return 0;\n  A[a] = -1;\n  for (int b : g[a]) if (B[b] == L + 1)\
    \ {\n    B[b] = 0;\n    if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))\n\
    \      return btoa[b] = a, 1;\n  }\n  return 0;\n}\n\nint hopcroftKarp(vector<vi>&\
    \ g, vi& btoa) {\n  int res = 0;\n  vi A(g.size()), B(btoa.size()), cur, next;\n\
    \  for (;;) {\n    fill(all(A), 0);\n    fill(all(B), 0);\n    /// Find the starting\
    \ nodes for BFS (i.e. layer 0).\n    cur.clear();\n    for (int a : btoa) if(a\
    \ != -1) A[a] = -1;\n    rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);\n    ///\
    \ Find all layers using bfs.\n    for (int lay = 1;; lay++) {\n      bool islast\
    \ = 0;\n      next.clear();\n      for (int a : cur) for (int b : g[a]) {\n  \
    \      if (btoa[b] == -1) {\n          B[b] = lay;\n          islast = 1;\n  \
    \      }\n        else if (btoa[b] != a && !B[b]) {\n          B[b] = lay;\n \
    \         next.push_back(btoa[b]);\n        }\n      }\n      if (islast) break;\n\
    \      if (next.empty()) return res;\n      for (int a : next) A[a] = lay;\n \
    \     cur.swap(next);\n    }\n    /// Use DFS to scan for augmenting paths.\n\
    \    rep(a,0,sz(g))\n      res += dfs(a, 0, g, btoa, A, B);\n  }\n}\n"
  code: "//source: KACTL\n\n/**\n * Author: Chen Xing\n * Date: 2009-10-13\n * License:\
    \ CC0\n * Source: N/A\n * Description: Fast bipartite matching algorithm. Graph\
    \ $g$ should be a list\n * of neighbors of the left partition, and $btoa$ should\
    \ be a vector full of\n * -1's of the same size as the right partition. Returns\
    \ the size of\n * the matching. $btoa[i]$ will be the match for vertex $i$ on\
    \ the right side,\n * or $-1$ if it's not matched.\n * Usage: vi btoa(m, -1);\
    \ hopcroftKarp(g, btoa);\n * Time: O(\\sqrt{V}E)\n * Status: stress-tested by\
    \ MinimumVertexCover, and tested on oldkattis.adkbipmatch and SPOJ:MATCHING\n\
    \ */\n\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) (int)(x).size()\ntypedef vector<int> vi;\n\nbool dfs(int\
    \ a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {\n  if (A[a] != L) return\
    \ 0;\n  A[a] = -1;\n  for (int b : g[a]) if (B[b] == L + 1) {\n    B[b] = 0;\n\
    \    if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))\n      return btoa[b]\
    \ = a, 1;\n  }\n  return 0;\n}\n\nint hopcroftKarp(vector<vi>& g, vi& btoa) {\n\
    \  int res = 0;\n  vi A(g.size()), B(btoa.size()), cur, next;\n  for (;;) {\n\
    \    fill(all(A), 0);\n    fill(all(B), 0);\n    /// Find the starting nodes for\
    \ BFS (i.e. layer 0).\n    cur.clear();\n    for (int a : btoa) if(a != -1) A[a]\
    \ = -1;\n    rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);\n    /// Find all\
    \ layers using bfs.\n    for (int lay = 1;; lay++) {\n      bool islast = 0;\n\
    \      next.clear();\n      for (int a : cur) for (int b : g[a]) {\n        if\
    \ (btoa[b] == -1) {\n          B[b] = lay;\n          islast = 1;\n        }\n\
    \        else if (btoa[b] != a && !B[b]) {\n          B[b] = lay;\n          next.push_back(btoa[b]);\n\
    \        }\n      }\n      if (islast) break;\n      if (next.empty()) return\
    \ res;\n      for (int a : next) A[a] = lay;\n      cur.swap(next);\n    }\n \
    \   /// Use DFS to scan for augmenting paths.\n    rep(a,0,sz(g))\n      res +=\
    \ dfs(a, 0, g, btoa, A, B);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/hopcroftKarp.cpp
  requiredBy: []
  timestamp: '2025-05-10 02:31:09+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bipartitematching_2.test.cpp
documentation_of: graph/hopcroftKarp.cpp
layout: document
redirect_from:
- /library/graph/hopcroftKarp.cpp
- /library/graph/hopcroftKarp.cpp.html
title: graph/hopcroftKarp.cpp
---
