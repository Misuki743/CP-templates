---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rooted_tree_isomorphism_classification.test.cpp
    title: test/rooted_tree_isomorphism_classification.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/treeHash.cpp\"\ntemplate<bool ordered = false>\npair<int,\
    \ vector<int>> treeHash(vector<vector<int>> &g, int root = 0) {\n  int nxt = 0;\n\
    \  static map<vector<int>, int> toId;\n  vector<int> id(ssize(g));\n  auto dfs\
    \ = [&](int v, int p, auto self) -> int {\n    vector<int> seq;\n    seq.reserve(ssize(g[v]));\n\
    \    for(int x : g[v]) if (x != p)\n      seq.emplace_back(self(x, v, self));\n\
    \    if constexpr (!ordered)\n      R::sort(seq);\n    if (!toId.contains(seq))\n\
    \      toId[seq] = nxt++;\n    return id[v] = toId[seq];\n  };\n\n  dfs(root,\
    \ -1, dfs);\n\n  return make_pair(nxt, id);\n}\n"
  code: "template<bool ordered = false>\npair<int, vector<int>> treeHash(vector<vector<int>>\
    \ &g, int root = 0) {\n  int nxt = 0;\n  static map<vector<int>, int> toId;\n\
    \  vector<int> id(ssize(g));\n  auto dfs = [&](int v, int p, auto self) -> int\
    \ {\n    vector<int> seq;\n    seq.reserve(ssize(g[v]));\n    for(int x : g[v])\
    \ if (x != p)\n      seq.emplace_back(self(x, v, self));\n    if constexpr (!ordered)\n\
    \      R::sort(seq);\n    if (!toId.contains(seq))\n      toId[seq] = nxt++;\n\
    \    return id[v] = toId[seq];\n  };\n\n  dfs(root, -1, dfs);\n\n  return make_pair(nxt,\
    \ id);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/treeHash.cpp
  requiredBy: []
  timestamp: '2024-01-28 03:46:27+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rooted_tree_isomorphism_classification.test.cpp
documentation_of: graph/treeHash.cpp
layout: document
redirect_from:
- /library/graph/treeHash.cpp
- /library/graph/treeHash.cpp.html
title: graph/treeHash.cpp
---
