---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/assignment_problem.test.cpp
    title: test/assignment_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h
  bundledCode: "#line 1 \"graph/matching/hungarian.cpp\"\n//source: KACTL\n\n/**\n\
    \ * Author: Benjamin Qi, chilli\n * Date: 2020-04-04\n * License: CC0\n * Source:\
    \ https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h\n\
    \ * Description: Given a weighted bipartite graph, matches every node on\n * the\
    \ left with a node on the right such that no\n * nodes are in two matchings and\
    \ the sum of the edge weights is minimal. Takes\n * cost[N][M], where cost[i][j]\
    \ = cost for L[i] to be matched with R[j] and\n * returns (min cost, match), where\
    \ L[i] is matched with\n * R[match[i]]. Negate costs for max cost. Requires $N\
    \ \\le M$.\n * Time: O(N^2M)\n * Status: Tested on kattis:cordonbleu, stress-tested\n\
    \ */\n\ntemplate<class T, T inf>\npair<T, vector<T>> hungarian(const vector<vector<T>>\
    \ &a) {\n  if (a.empty()) return {0, {}};\n  int n = ssize(a) + 1, m = ssize(a[0])\
    \ + 1;\n  vector<int> p(m);\n  vector<T> u(n), v(m), ans(n - 1);\n  for(int i\
    \ = 1; i < n; i++) {\n    p[0] = i;\n    int j0 = 0;\n    vector<T> dist(m, inf),\
    \ pre(m, -1);\n    vector<bool> done(m + 1);\n    do {\n      done[j0] = true;\n\
    \      int i0 = p[j0], j1;\n      T delta = inf;\n      for(int j = 1; j < m;\
    \ j++) if (!done[j]) {\n\t\t\t\tauto cur = a[i0 - 1][j - 1] - u[i0] - v[j];\n\t\
    \t\t\tif (cur < dist[j]) dist[j] = cur, pre[j] = j0;\n\t\t\t\tif (dist[j] < delta)\
    \ delta = dist[j], j1 = j;\n      }\n      for(int j = 0; j < m; j++) {\n\t\t\t\
    \tif (done[j]) u[p[j]] += delta, v[j] -= delta;\n\t\t\t\telse dist[j] -= delta;\n\
    \      }\n      j0 = j1;\n    } while(p[j0]);\n    while(j0) {\n      int j1 =\
    \ pre[j0];\n      p[j0] = p[j1], j0 = j1;\n    }\n  }\n  for(int j = 1; j < m;\
    \ j++) if (p[j]) ans[p[j] - 1] = j - 1;\n  return {-v[0], ans};\n}\n"
  code: "//source: KACTL\n\n/**\n * Author: Benjamin Qi, chilli\n * Date: 2020-04-04\n\
    \ * License: CC0\n * Source: https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h\n\
    \ * Description: Given a weighted bipartite graph, matches every node on\n * the\
    \ left with a node on the right such that no\n * nodes are in two matchings and\
    \ the sum of the edge weights is minimal. Takes\n * cost[N][M], where cost[i][j]\
    \ = cost for L[i] to be matched with R[j] and\n * returns (min cost, match), where\
    \ L[i] is matched with\n * R[match[i]]. Negate costs for max cost. Requires $N\
    \ \\le M$.\n * Time: O(N^2M)\n * Status: Tested on kattis:cordonbleu, stress-tested\n\
    \ */\n\ntemplate<class T, T inf>\npair<T, vector<T>> hungarian(const vector<vector<T>>\
    \ &a) {\n  if (a.empty()) return {0, {}};\n  int n = ssize(a) + 1, m = ssize(a[0])\
    \ + 1;\n  vector<int> p(m);\n  vector<T> u(n), v(m), ans(n - 1);\n  for(int i\
    \ = 1; i < n; i++) {\n    p[0] = i;\n    int j0 = 0;\n    vector<T> dist(m, inf),\
    \ pre(m, -1);\n    vector<bool> done(m + 1);\n    do {\n      done[j0] = true;\n\
    \      int i0 = p[j0], j1;\n      T delta = inf;\n      for(int j = 1; j < m;\
    \ j++) if (!done[j]) {\n\t\t\t\tauto cur = a[i0 - 1][j - 1] - u[i0] - v[j];\n\t\
    \t\t\tif (cur < dist[j]) dist[j] = cur, pre[j] = j0;\n\t\t\t\tif (dist[j] < delta)\
    \ delta = dist[j], j1 = j;\n      }\n      for(int j = 0; j < m; j++) {\n\t\t\t\
    \tif (done[j]) u[p[j]] += delta, v[j] -= delta;\n\t\t\t\telse dist[j] -= delta;\n\
    \      }\n      j0 = j1;\n    } while(p[j0]);\n    while(j0) {\n      int j1 =\
    \ pre[j0];\n      p[j0] = p[j1], j0 = j1;\n    }\n  }\n  for(int j = 1; j < m;\
    \ j++) if (p[j]) ans[p[j] - 1] = j - 1;\n  return {-v[0], ans};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/matching/hungarian.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/assignment_problem.test.cpp
documentation_of: graph/matching/hungarian.cpp
layout: document
redirect_from:
- /library/graph/matching/hungarian.cpp
- /library/graph/matching/hungarian.cpp.html
title: graph/matching/hungarian.cpp
---
