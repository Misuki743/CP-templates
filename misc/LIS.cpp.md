---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/longest_increasing_subsequence.test.cpp
    title: test/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/LIS.cpp\"\ntemplate<class T, bool strict = true>\n\
    vector<int> LIS(vector<T> &a) {\n  if (a.empty()) return {};\n  vector<T> dp(ssize(a),\
    \ numeric_limits<T>::max());\n  vector<int> id(ssize(a)), pre(ssize(a), -1);\n\
    \  for(int i = 0; i < ssize(a); i++) {\n    int j;\n    if constexpr (strict)\n\
    \      j = ranges::lower_bound(dp, a[i]) - dp.begin();\n    else\n      j = ranges::upper_bound(dp,\
    \ a[i]) - dp.begin();\n    if (a[i] < dp[j])\n      dp[j] = a[i], id[j] = i;\n\
    \    if (j >= 1)\n      pre[i] = id[j - 1];\n  }\n\n  vector<T> lis;\n  int i\
    \ = id[ranges::lower_bound(dp, numeric_limits<T>::max()) - dp.begin() - 1];\n\
    \  while(i != -1) {\n    lis.emplace_back(i);\n    i = pre[i];\n  }\n  ranges::reverse(lis);\n\
    \n  return lis;\n}\n"
  code: "template<class T, bool strict = true>\nvector<int> LIS(vector<T> &a) {\n\
    \  if (a.empty()) return {};\n  vector<T> dp(ssize(a), numeric_limits<T>::max());\n\
    \  vector<int> id(ssize(a)), pre(ssize(a), -1);\n  for(int i = 0; i < ssize(a);\
    \ i++) {\n    int j;\n    if constexpr (strict)\n      j = ranges::lower_bound(dp,\
    \ a[i]) - dp.begin();\n    else\n      j = ranges::upper_bound(dp, a[i]) - dp.begin();\n\
    \    if (a[i] < dp[j])\n      dp[j] = a[i], id[j] = i;\n    if (j >= 1)\n    \
    \  pre[i] = id[j - 1];\n  }\n\n  vector<T> lis;\n  int i = id[ranges::lower_bound(dp,\
    \ numeric_limits<T>::max()) - dp.begin() - 1];\n  while(i != -1) {\n    lis.emplace_back(i);\n\
    \    i = pre[i];\n  }\n  ranges::reverse(lis);\n\n  return lis;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/LIS.cpp
  requiredBy: []
  timestamp: '2024-12-08 22:54:18+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/longest_increasing_subsequence.test.cpp
documentation_of: misc/LIS.cpp
layout: document
redirect_from:
- /library/misc/LIS.cpp
- /library/misc/LIS.cpp.html
title: misc/LIS.cpp
---
