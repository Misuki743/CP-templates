---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_enumerate_twelvefold.test.cpp
    title: test/mytest_enumerate_twelvefold.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree.test.cpp
    title: test/mytest_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/enumerate_twelvefold.cpp\"\n//#include \"enumerate/bit.cpp\"\
    \n\ntemplate<typename F>\nrequires invocable<F, vector<int>>\nvoid enumerate_cartesian_power(int\
    \ n, int k, F f) {\n  assert(min(n, k) >= 0);\n  vector<int> p(k);\n  auto dfs\
    \ = [&](int i, auto &self) -> void {\n    if (i == k) {\n      f(p);\n    } else\
    \ {\n      for(int x = 0; x < n; x++) {\n        p[i] = x;\n        self(i + 1,\
    \ self);\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<int>>\nvoid enumerate_permutation(int n, F f) {\n  assert(n\
    \ >= 0);\n  vector<int> p(n);\n  iota(p.begin(), p.end(), 0);\n  do { f(p); }\
    \ while(next_permutation(p.begin(), p.end()));\n}\n\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<int>>\nvoid enumerate_combination(int n, int k, F f) {\n\
    \  assert(min(n, k) >= 0);\n  vector<int> p;\n  auto dfs = [&](auto &self) ->\
    \ void {\n    if (ssize(p) == k) {\n      f(p);\n    } else {\n      for(int x\
    \ = (p.empty() ? 0 : p.back() + 1); x + k - ssize(p) <= n; x++) {\n        p.emplace_back(x);\n\
    \        self(self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(dfs);\n\
    }\n\ntemplate<typename F>\nrequires invocable<F, vector<int>>\nvoid enumerate_set_partition(int\
    \ n, F f) {\n  assert(n >= 0);\n  vector<int> p;\n  int msk = (1 << n) - 1;\n\
    \  auto dfs = [&](auto &self) -> void {\n    if (msk == 0) {\n      f(p);\n  \
    \  } else {\n      int x = msk & (-msk);\n      msk ^= x;\n      enumerate_subset(msk,\
    \ [&](int sub) {\n        p.emplace_back(sub | x);\n        msk ^= sub;\n    \
    \    self(self);\n        msk ^= sub;\n        p.pop_back();\n      });\n    \
    \  msk ^= x;\n    }\n  };\n  dfs(dfs);\n}\n\ntemplate<typename F>\nrequires invocable<F,\
    \ vector<int>>\nvoid enumerate_multisubset(int n, int sum, F f) {\n  assert(min(n,\
    \ sum) >= 0);\n  vector<int> p(n);\n  auto dfs = [&](int i, auto &self) -> void\
    \ {\n    if (i == n) {\n      if (sum == 0) f(p);\n    } else {\n      for(int\
    \ x = sum; x >= 0; x--) {\n        p[i] = x, sum -= x;\n        self(i + 1, self);\n\
    \        sum += x;\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\ntemplate<typename\
    \ F>\nrequires invocable<F, vector<int>>\nvoid enumerate_integer_partition(int\
    \ n, F f) {\n  assert(n >= 0);\n  vector<int> p;\n  auto dfs = [&](int s, auto\
    \ &self) -> void {\n    if (s == 0) {\n      f(p);\n    } else {\n      for(int\
    \ x = (p.empty() ? s : min(p.back(), s)); x > 0; x--) {\n        p.emplace_back(x);\n\
    \        self(s - x, self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(n,\
    \ dfs);\n}\n"
  code: "//#include \"enumerate/bit.cpp\"\n\ntemplate<typename F>\nrequires invocable<F,\
    \ vector<int>>\nvoid enumerate_cartesian_power(int n, int k, F f) {\n  assert(min(n,\
    \ k) >= 0);\n  vector<int> p(k);\n  auto dfs = [&](int i, auto &self) -> void\
    \ {\n    if (i == k) {\n      f(p);\n    } else {\n      for(int x = 0; x < n;\
    \ x++) {\n        p[i] = x;\n        self(i + 1, self);\n      }\n    }\n  };\n\
    \  dfs(0, dfs);\n}\n\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_permutation(int n, F f) {\n  assert(n >= 0);\n  vector<int> p(n);\n\
    \  iota(p.begin(), p.end(), 0);\n  do { f(p); } while(next_permutation(p.begin(),\
    \ p.end()));\n}\n\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_combination(int n, int k, F f) {\n  assert(min(n, k) >= 0);\n \
    \ vector<int> p;\n  auto dfs = [&](auto &self) -> void {\n    if (ssize(p) ==\
    \ k) {\n      f(p);\n    } else {\n      for(int x = (p.empty() ? 0 : p.back()\
    \ + 1); x + k - ssize(p) <= n; x++) {\n        p.emplace_back(x);\n        self(self);\n\
    \        p.pop_back();\n      }\n    }\n  };\n  dfs(dfs);\n}\n\ntemplate<typename\
    \ F>\nrequires invocable<F, vector<int>>\nvoid enumerate_set_partition(int n,\
    \ F f) {\n  assert(n >= 0);\n  vector<int> p;\n  int msk = (1 << n) - 1;\n  auto\
    \ dfs = [&](auto &self) -> void {\n    if (msk == 0) {\n      f(p);\n    } else\
    \ {\n      int x = msk & (-msk);\n      msk ^= x;\n      enumerate_subset(msk,\
    \ [&](int sub) {\n        p.emplace_back(sub | x);\n        msk ^= sub;\n    \
    \    self(self);\n        msk ^= sub;\n        p.pop_back();\n      });\n    \
    \  msk ^= x;\n    }\n  };\n  dfs(dfs);\n}\n\ntemplate<typename F>\nrequires invocable<F,\
    \ vector<int>>\nvoid enumerate_multisubset(int n, int sum, F f) {\n  assert(min(n,\
    \ sum) >= 0);\n  vector<int> p(n);\n  auto dfs = [&](int i, auto &self) -> void\
    \ {\n    if (i == n) {\n      if (sum == 0) f(p);\n    } else {\n      for(int\
    \ x = sum; x >= 0; x--) {\n        p[i] = x, sum -= x;\n        self(i + 1, self);\n\
    \        sum += x;\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\ntemplate<typename\
    \ F>\nrequires invocable<F, vector<int>>\nvoid enumerate_integer_partition(int\
    \ n, F f) {\n  assert(n >= 0);\n  vector<int> p;\n  auto dfs = [&](int s, auto\
    \ &self) -> void {\n    if (s == 0) {\n      f(p);\n    } else {\n      for(int\
    \ x = (p.empty() ? s : min(p.back(), s)); x > 0; x--) {\n        p.emplace_back(x);\n\
    \        self(s - x, self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(n,\
    \ dfs);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_twelvefold.cpp
  requiredBy: []
  timestamp: '2026-01-29 06:19:40+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_enumerate_twelvefold.test.cpp
  - test/mytest_tree.test.cpp
documentation_of: enumerate/enumerate_twelvefold.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_twelvefold.cpp
- /library/enumerate/enumerate_twelvefold.cpp.html
title: enumerate/enumerate_twelvefold.cpp
---
