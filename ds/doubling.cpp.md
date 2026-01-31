---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki_1097.test.cpp
    title: test/yuki_1097.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/doubling.cpp\"\ntemplate<class T, typename F>\nrequires\
    \ R_invocable<T, F, T&, T&>\nstruct doubling {\n  const int LOG;\n  const T id;\n\
    \  F op;\n  vvi jp;\n  vvc<T> data;\n\n  doubling(int _LOG, vi to, vc<T> init,\
    \ T _id, F f) : LOG(_LOG), id(_id), op(f),\n    jp(LOG, vi(size(to), -1)), data(LOG,\
    \ vc<T>(size(to), id)) {\n    assert(size(init) == size(to));\n    jp[0] = std::move(to),\
    \ data[0] = std::move(init);\n    for(int i = 1; i < LOG; i++)\n      for(int\
    \ j = 0; j < ssize(jp[i]); j++)\n        if (int k = jp[i - 1][j]; k != -1 and\
    \ jp[i - 1][k] != -1)\n          jp[i][j] = jp[i - 1][k], data[i][j] = op(data[i\
    \ - 1][j], data[i - 1][k]);\n  }\n\n  auto jump(int s, ll step) {\n    assert(0ll\
    \ <= step and step < (1ll << LOG));\n    T prod = id;\n    for(; step > 0; step\
    \ -= step & (-step)) {\n      if (int to = jp[countr_zero((uint64_t)step)][s];\
    \ to != -1) {\n        prod = op(prod, data[countr_zero((uint64_t)step)][s]);\n\
    \        s = to;\n      }\n    }\n    return pair(s, prod);\n  }\n\n  template<typename\
    \ P>\n  requires R_invocable<bool, P, T&, T&>\n  auto jump_while_true(int s, P\
    \ pred) {\n    ll step = 0;\n    T prod = id;\n    for(int i = LOG - 1; i >= 0;\
    \ i--)\n      if (jp[i][s] != -1)\n        if (T tmp = op(prod, data[i][s]); pred(tmp))\n\
    \          step += 1ll << i, prod = tmp, s = jp[i][s];\n    return tuple(s, step,\
    \ prod);\n  }\n};\n"
  code: "template<class T, typename F>\nrequires R_invocable<T, F, T&, T&>\nstruct\
    \ doubling {\n  const int LOG;\n  const T id;\n  F op;\n  vvi jp;\n  vvc<T> data;\n\
    \n  doubling(int _LOG, vi to, vc<T> init, T _id, F f) : LOG(_LOG), id(_id), op(f),\n\
    \    jp(LOG, vi(size(to), -1)), data(LOG, vc<T>(size(to), id)) {\n    assert(size(init)\
    \ == size(to));\n    jp[0] = std::move(to), data[0] = std::move(init);\n    for(int\
    \ i = 1; i < LOG; i++)\n      for(int j = 0; j < ssize(jp[i]); j++)\n        if\
    \ (int k = jp[i - 1][j]; k != -1 and jp[i - 1][k] != -1)\n          jp[i][j] =\
    \ jp[i - 1][k], data[i][j] = op(data[i - 1][j], data[i - 1][k]);\n  }\n\n  auto\
    \ jump(int s, ll step) {\n    assert(0ll <= step and step < (1ll << LOG));\n \
    \   T prod = id;\n    for(; step > 0; step -= step & (-step)) {\n      if (int\
    \ to = jp[countr_zero((uint64_t)step)][s]; to != -1) {\n        prod = op(prod,\
    \ data[countr_zero((uint64_t)step)][s]);\n        s = to;\n      }\n    }\n  \
    \  return pair(s, prod);\n  }\n\n  template<typename P>\n  requires R_invocable<bool,\
    \ P, T&, T&>\n  auto jump_while_true(int s, P pred) {\n    ll step = 0;\n    T\
    \ prod = id;\n    for(int i = LOG - 1; i >= 0; i--)\n      if (jp[i][s] != -1)\n\
    \        if (T tmp = op(prod, data[i][s]); pred(tmp))\n          step += 1ll <<\
    \ i, prod = tmp, s = jp[i][s];\n    return tuple(s, step, prod);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/doubling.cpp
  requiredBy: []
  timestamp: '2026-01-31 20:47:40+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki_1097.test.cpp
documentation_of: ds/doubling.cpp
layout: document
redirect_from:
- /library/ds/doubling.cpp
- /library/ds/doubling.cpp.html
title: ds/doubling.cpp
---
