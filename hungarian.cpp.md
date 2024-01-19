---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h
  bundledCode: "#line 1 \"hungarian.cpp\"\n/**\n * Author: Benjamin Qi, chilli\n *\
    \ Date: 2020-04-04\n * License: CC0\n * Source: https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h\n\
    \ * Description: Given a weighted bipartite graph, matches every node on\n * the\
    \ left with a node on the right such that no\n * nodes are in two matchings and\
    \ the sum of the edge weights is minimal. Takes\n * cost[N][M], where cost[i][j]\
    \ = cost for L[i] to be matched with R[j] and\n * returns (min cost, match), where\
    \ L[i] is matched with\n * R[match[i]]. Negate costs for max cost. Requires $N\
    \ \\le M$.\n * Time: O(N^2M)\n * Status: Tested on kattis:cordonbleu, stress-tested\n\
    \ */\n\npair<int, vi> hungarian(const vector<vi> &a) {\n\tif (a.empty()) return\
    \ {0, {}};\n\tint n = sz(a) + 1, m = sz(a[0]) + 1;\n\tvi u(n), v(m), p(m), ans(n\
    \ - 1);\n\trep(i,1,n) {\n\t\tp[0] = i;\n\t\tint j0 = 0; // add \"dummy\" worker\
    \ 0\n\t\tvi dist(m, INT_MAX), pre(m, -1);\n\t\tvector<bool> done(m + 1);\n\t\t\
    do { // dijkstra\n\t\t\tdone[j0] = true;\n\t\t\tint i0 = p[j0], j1, delta = INT_MAX;\n\
    \t\t\trep(j,1,m) if (!done[j]) {\n\t\t\t\tauto cur = a[i0 - 1][j - 1] - u[i0]\
    \ - v[j];\n\t\t\t\tif (cur < dist[j]) dist[j] = cur, pre[j] = j0;\n\t\t\t\tif\
    \ (dist[j] < delta) delta = dist[j], j1 = j;\n\t\t\t}\n\t\t\trep(j,0,m) {\n\t\t\
    \t\tif (done[j]) u[p[j]] += delta, v[j] -= delta;\n\t\t\t\telse dist[j] -= delta;\n\
    \t\t\t}\n\t\t\tj0 = j1;\n\t\t} while (p[j0]);\n\t\twhile (j0) { // update alternating\
    \ path\n\t\t\tint j1 = pre[j0];\n\t\t\tp[j0] = p[j1], j0 = j1;\n\t\t}\n\t}\n\t\
    rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;\n\treturn {-v[0], ans}; // min cost\n\
    }\n"
  code: "/**\n * Author: Benjamin Qi, chilli\n * Date: 2020-04-04\n * License: CC0\n\
    \ * Source: https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h\n\
    \ * Description: Given a weighted bipartite graph, matches every node on\n * the\
    \ left with a node on the right such that no\n * nodes are in two matchings and\
    \ the sum of the edge weights is minimal. Takes\n * cost[N][M], where cost[i][j]\
    \ = cost for L[i] to be matched with R[j] and\n * returns (min cost, match), where\
    \ L[i] is matched with\n * R[match[i]]. Negate costs for max cost. Requires $N\
    \ \\le M$.\n * Time: O(N^2M)\n * Status: Tested on kattis:cordonbleu, stress-tested\n\
    \ */\n\npair<int, vi> hungarian(const vector<vi> &a) {\n\tif (a.empty()) return\
    \ {0, {}};\n\tint n = sz(a) + 1, m = sz(a[0]) + 1;\n\tvi u(n), v(m), p(m), ans(n\
    \ - 1);\n\trep(i,1,n) {\n\t\tp[0] = i;\n\t\tint j0 = 0; // add \"dummy\" worker\
    \ 0\n\t\tvi dist(m, INT_MAX), pre(m, -1);\n\t\tvector<bool> done(m + 1);\n\t\t\
    do { // dijkstra\n\t\t\tdone[j0] = true;\n\t\t\tint i0 = p[j0], j1, delta = INT_MAX;\n\
    \t\t\trep(j,1,m) if (!done[j]) {\n\t\t\t\tauto cur = a[i0 - 1][j - 1] - u[i0]\
    \ - v[j];\n\t\t\t\tif (cur < dist[j]) dist[j] = cur, pre[j] = j0;\n\t\t\t\tif\
    \ (dist[j] < delta) delta = dist[j], j1 = j;\n\t\t\t}\n\t\t\trep(j,0,m) {\n\t\t\
    \t\tif (done[j]) u[p[j]] += delta, v[j] -= delta;\n\t\t\t\telse dist[j] -= delta;\n\
    \t\t\t}\n\t\t\tj0 = j1;\n\t\t} while (p[j0]);\n\t\twhile (j0) { // update alternating\
    \ path\n\t\t\tint j1 = pre[j0];\n\t\t\tp[j0] = p[j1], j0 = j1;\n\t\t}\n\t}\n\t\
    rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;\n\treturn {-v[0], ans}; // min cost\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: hungarian.cpp
  requiredBy: []
  timestamp: '2022-06-22 03:09:57+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hungarian.cpp
layout: document
redirect_from:
- /library/hungarian.cpp
- /library/hungarian.cpp.html
title: hungarian.cpp
---
