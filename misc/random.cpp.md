---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lca_2.test.cpp
    title: test/lca_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/random.cpp\"\nnamespace RNG {\n  mt19937_64 rng(clock);\n\
    \n  //empty vector would be assumed to be n = 2\n  vector<pii> prufer_recover(vector<int>\
    \ prufer_code) {\n    const int n = ssize(prufer_code) + 2;\n    assert(prufer_code.empty()\
    \ or (ranges::min(prufer_code) >= 0 and ranges::max(prufer_code) < n));\n    vector<int>\
    \ d(n, 1);\n    for(int x : prufer_code) d[x]++;\n    min_heap<int> leaf;\n  \
    \  for(int v = 0; v < n; v++)\n      if (d[v] == 1)\n        leaf.emplace(v);\n\
    \    vector<pii> edges;\n    for(int x : prufer_code) {\n      int v = leaf.top();\
    \ leaf.pop();\n      edges.emplace_back(v, x);\n      if (--d[x] == 1)\n     \
    \   leaf.emplace(x);\n    }\n    int v = leaf.top(); leaf.pop();\n    edges.emplace_back(v,\
    \ leaf.top());\n    return edges;\n  }\n\n  int rand_int(int l, int r) { return\
    \ uniform_int_distribution(l, r - 1)(rng); }\n  vi rand_seq(int n, int l, int\
    \ r) {\n    assert(n >= 0);\n    vi v(n);\n    for(int &x : v) x = rand_int(l,\
    \ r);\n    return v;\n  }\n  vvi rand_label_tree(int n) {\n    assert(n >= 0);\n\
    \    if (n <= 1) return vvi(n);\n    else return adjacency_list<false>(n, prufer_recover(rand_seq(n\
    \ - 2, 0, n)), 0);\n  }\n  vi rand_perm(int n) {\n    assert(n >= 0);\n    vi\
    \ p(n);\n    iota(p.begin(), p.end(), 0);\n    shuffle(p.begin(), p.end(), rng);\n\
    \    return p;\n  }\n  vi rand_comb(int n, int k) {\n    assert(0 <= k and k <=\
    \ n);\n    vi p = rand_perm(n);\n    p.resize(k);\n    ranges::sort(p);\n    return\
    \ p;\n  }\n};\n"
  code: "namespace RNG {\n  mt19937_64 rng(clock);\n\n  //empty vector would be assumed\
    \ to be n = 2\n  vector<pii> prufer_recover(vector<int> prufer_code) {\n    const\
    \ int n = ssize(prufer_code) + 2;\n    assert(prufer_code.empty() or (ranges::min(prufer_code)\
    \ >= 0 and ranges::max(prufer_code) < n));\n    vector<int> d(n, 1);\n    for(int\
    \ x : prufer_code) d[x]++;\n    min_heap<int> leaf;\n    for(int v = 0; v < n;\
    \ v++)\n      if (d[v] == 1)\n        leaf.emplace(v);\n    vector<pii> edges;\n\
    \    for(int x : prufer_code) {\n      int v = leaf.top(); leaf.pop();\n     \
    \ edges.emplace_back(v, x);\n      if (--d[x] == 1)\n        leaf.emplace(x);\n\
    \    }\n    int v = leaf.top(); leaf.pop();\n    edges.emplace_back(v, leaf.top());\n\
    \    return edges;\n  }\n\n  int rand_int(int l, int r) { return uniform_int_distribution(l,\
    \ r - 1)(rng); }\n  vi rand_seq(int n, int l, int r) {\n    assert(n >= 0);\n\
    \    vi v(n);\n    for(int &x : v) x = rand_int(l, r);\n    return v;\n  }\n \
    \ vvi rand_label_tree(int n) {\n    assert(n >= 0);\n    if (n <= 1) return vvi(n);\n\
    \    else return adjacency_list<false>(n, prufer_recover(rand_seq(n - 2, 0, n)),\
    \ 0);\n  }\n  vi rand_perm(int n) {\n    assert(n >= 0);\n    vi p(n);\n    iota(p.begin(),\
    \ p.end(), 0);\n    shuffle(p.begin(), p.end(), rng);\n    return p;\n  }\n  vi\
    \ rand_comb(int n, int k) {\n    assert(0 <= k and k <= n);\n    vi p = rand_perm(n);\n\
    \    p.resize(k);\n    ranges::sort(p);\n    return p;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/random.cpp
  requiredBy: []
  timestamp: '2026-01-30 01:25:42+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lca_2.test.cpp
documentation_of: misc/random.cpp
layout: document
redirect_from:
- /library/misc/random.cpp
- /library/misc/random.cpp.html
title: misc/random.cpp
---
