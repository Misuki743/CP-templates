---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"test/rectangle_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
    \n\n#include<../default/t.cpp>\n#include<../ds/fenwickTree.cpp>\n#include<../misc/compression.cpp>\n\
    #include<../misc/rectangleSum.cpp>\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<tuple<int, int, ll>>\
    \ pts(n);\n  for(auto &[x, y, w] : pts)\n    cin >> x >> y >> w;\n  vector<array<int,\
    \ 4>> query(q);\n  for(auto &[l, d, r, u] : query)\n    cin >> l >> r >> d >>\
    \ u;\n\n  for(ll ans : rectangleSum(pts, query))\n    cout << ans << '\\n';\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include<../default/t.cpp>\n\
    #include<../ds/fenwickTree.cpp>\n#include<../misc/compression.cpp>\n#include<../misc/rectangleSum.cpp>\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<tuple<int, int, ll>> pts(n);\n  for(auto &[x, y, w]\
    \ : pts)\n    cin >> x >> y >> w;\n  vector<array<int, 4>> query(q);\n  for(auto\
    \ &[l, d, r, u] : query)\n    cin >> l >> r >> d >> u;\n\n  for(ll ans : rectangleSum(pts,\
    \ query))\n    cout << ans << '\\n';\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-27 18:42:26+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/rectangle_sum.test.cpp
- /verify/test/rectangle_sum.test.cpp.html
title: test/rectangle_sum.test.cpp
---
