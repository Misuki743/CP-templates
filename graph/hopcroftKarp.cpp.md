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
    \ vi;\n\nbool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {\n\tif\
    \ (A[a] != L) return 0;\n\tA[a] = -1;\n\tfor (int b : g[a]) if (B[b] == L + 1)\
    \ {\n\t\tB[b] = 0;\n\t\tif (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))\n\
    \t\t\treturn btoa[b] = a, 1;\n\t}\n\treturn 0;\n}\n\nint hopcroftKarp(vector<vi>&\
    \ g, vi& btoa) {\n\tint res = 0;\n\tvi A(g.size()), B(btoa.size()), cur, next;\n\
    \tfor (;;) {\n\t\tfill(all(A), 0);\n\t\tfill(all(B), 0);\n\t\t/// Find the starting\
    \ nodes for BFS (i.e. layer 0).\n\t\tcur.clear();\n\t\tfor (int a : btoa) if(a\
    \ != -1) A[a] = -1;\n\t\trep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);\n\t\t\
    /// Find all layers using bfs.\n\t\tfor (int lay = 1;; lay++) {\n\t\t\tbool islast\
    \ = 0;\n\t\t\tnext.clear();\n\t\t\tfor (int a : cur) for (int b : g[a]) {\n\t\t\
    \t\tif (btoa[b] == -1) {\n\t\t\t\t\tB[b] = lay;\n\t\t\t\t\tislast = 1;\n\t\t\t\
    \t}\n\t\t\t\telse if (btoa[b] != a && !B[b]) {\n\t\t\t\t\tB[b] = lay;\n\t\t\t\t\
    \tnext.push_back(btoa[b]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (islast) break;\n\t\t\
    \tif (next.empty()) return res;\n\t\t\tfor (int a : next) A[a] = lay;\n\t\t\t\
    cur.swap(next);\n\t\t}\n\t\t/// Use DFS to scan for augmenting paths.\n\t\trep(a,0,sz(g))\n\
    \t\t\tres += dfs(a, 0, g, btoa, A, B);\n\t}\n}\n"
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
    \ a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {\n\tif (A[a] != L) return\
    \ 0;\n\tA[a] = -1;\n\tfor (int b : g[a]) if (B[b] == L + 1) {\n\t\tB[b] = 0;\n\
    \t\tif (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))\n\t\t\treturn btoa[b]\
    \ = a, 1;\n\t}\n\treturn 0;\n}\n\nint hopcroftKarp(vector<vi>& g, vi& btoa) {\n\
    \tint res = 0;\n\tvi A(g.size()), B(btoa.size()), cur, next;\n\tfor (;;) {\n\t\
    \tfill(all(A), 0);\n\t\tfill(all(B), 0);\n\t\t/// Find the starting nodes for\
    \ BFS (i.e. layer 0).\n\t\tcur.clear();\n\t\tfor (int a : btoa) if(a != -1) A[a]\
    \ = -1;\n\t\trep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);\n\t\t/// Find all\
    \ layers using bfs.\n\t\tfor (int lay = 1;; lay++) {\n\t\t\tbool islast = 0;\n\
    \t\t\tnext.clear();\n\t\t\tfor (int a : cur) for (int b : g[a]) {\n\t\t\t\tif\
    \ (btoa[b] == -1) {\n\t\t\t\t\tB[b] = lay;\n\t\t\t\t\tislast = 1;\n\t\t\t\t}\n\
    \t\t\t\telse if (btoa[b] != a && !B[b]) {\n\t\t\t\t\tB[b] = lay;\n\t\t\t\t\tnext.push_back(btoa[b]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif (islast) break;\n\t\t\tif (next.empty()) return res;\n\
    \t\t\tfor (int a : next) A[a] = lay;\n\t\t\tcur.swap(next);\n\t\t}\n\t\t/// Use\
    \ DFS to scan for augmenting paths.\n\t\trep(a,0,sz(g))\n\t\t\tres += dfs(a, 0,\
    \ g, btoa, A, B);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/hopcroftKarp.cpp
  requiredBy: []
  timestamp: '2025-03-16 13:02:37+08:00'
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
