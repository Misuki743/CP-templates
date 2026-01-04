---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fast_set.cpp\"\nstruct fast_set {\n  using u64 = uint64_t;\n\
    \  static constexpr u64 B = 64;\n  int sz;\n  vector<vector<u64>> data;\n\n  fast_set(u64\
    \ _sz) : sz(_sz) {\n    do {\n      data.pb(vector<u64>(ceilDiv(_sz, B)));\n \
    \     _sz = ceilDiv(_sz, B);\n    } while(_sz > 1);\n  }\n\n  fast_set(string\
    \ s) : sz(ssize(s)) {\n    u64 _sz = sz;\n    data.pb(vector<u64>(ceilDiv(_sz,\
    \ B)));\n    for(int i = 0; i < ssize(s); i++)\n      data[0][i / B] |= u64(s[i]\
    \ - '0') << (i % B);\n    _sz /= B;\n    while(_sz > 1) {\n      data.pb(vector<u64>(ceilDiv(_sz,\
    \ B)));\n      for(u64 i = 0; i < _sz; i++)\n        data.back()[i / B] |= u64(!!end(data)[-2][i])\
    \ << (i % B);\n      _sz = ceilDiv(_sz, B);\n    }\n  }\n\n  bool contains(int\
    \ x) {\n    return x < sz and (data[0][x / B] >> (x % B) & 1);\n  }\n\n  void\
    \ insert(int x) {\n    if (contains(x)) return;\n    assert(x < sz);\n    for(auto\
    \ &v : data)\n      v[x / B] |= u64(1) << (x % B), x /= B;\n  }\n\n  void erase(int\
    \ x) {\n    if (x >= sz or !contains(x)) return;\n    u64 pre = !(data[0][x /\
    \ B] &= (-u64(1)) ^ (u64(1) << (x % B)));\n    for(auto &v : data | views::drop(1))\n\
    \      x /= B, pre = !(v[x / B] ^= u64(pre) << (x % B));\n  }\n\n  int geq(int\
    \ x) {\n    if (x >= sz) return sz;\n    chmax(x, int(0));\n    for(int i = 0;\
    \ i < ssize(data) and x / (int)B < ssize(data[i]); i++, x = x / (int)B + 1) {\n\
    \      if (data[i][x / B] >> (x % B)) {\n        int y = x;\n        for(int j\
    \ = i; j >= 0; j--)\n          y = (y + countr_zero(data[j][y / B] >> (y % B)))\
    \ * B;\n        return y / B;\n      }\n    }\n    return sz;\n  }\n\n  int leq(int\
    \ x) {\n    if (x < 0) return -1;\n    chmin(x, sz - 1);\n    for(int i = 0; i\
    \ < ssize(data) and x >= 0; i++, x = x / (int)B - 1) {\n      if (data[i][x /\
    \ B] << (B - 1 - x % B)) {\n        int y = x;\n        for(int j = i; j >= 0;\
    \ j--)\n          y = (y - countl_zero(data[j][y / B] << (B - 1 - y % B))) * B\
    \ + (B - 1);\n        return y / B;\n      }\n    }\n    return -1;\n  }\n};\n"
  code: "struct fast_set {\n  using u64 = uint64_t;\n  static constexpr u64 B = 64;\n\
    \  int sz;\n  vector<vector<u64>> data;\n\n  fast_set(u64 _sz) : sz(_sz) {\n \
    \   do {\n      data.pb(vector<u64>(ceilDiv(_sz, B)));\n      _sz = ceilDiv(_sz,\
    \ B);\n    } while(_sz > 1);\n  }\n\n  fast_set(string s) : sz(ssize(s)) {\n \
    \   u64 _sz = sz;\n    data.pb(vector<u64>(ceilDiv(_sz, B)));\n    for(int i =\
    \ 0; i < ssize(s); i++)\n      data[0][i / B] |= u64(s[i] - '0') << (i % B);\n\
    \    _sz /= B;\n    while(_sz > 1) {\n      data.pb(vector<u64>(ceilDiv(_sz, B)));\n\
    \      for(u64 i = 0; i < _sz; i++)\n        data.back()[i / B] |= u64(!!end(data)[-2][i])\
    \ << (i % B);\n      _sz = ceilDiv(_sz, B);\n    }\n  }\n\n  bool contains(int\
    \ x) {\n    return x < sz and (data[0][x / B] >> (x % B) & 1);\n  }\n\n  void\
    \ insert(int x) {\n    if (contains(x)) return;\n    assert(x < sz);\n    for(auto\
    \ &v : data)\n      v[x / B] |= u64(1) << (x % B), x /= B;\n  }\n\n  void erase(int\
    \ x) {\n    if (x >= sz or !contains(x)) return;\n    u64 pre = !(data[0][x /\
    \ B] &= (-u64(1)) ^ (u64(1) << (x % B)));\n    for(auto &v : data | views::drop(1))\n\
    \      x /= B, pre = !(v[x / B] ^= u64(pre) << (x % B));\n  }\n\n  int geq(int\
    \ x) {\n    if (x >= sz) return sz;\n    chmax(x, int(0));\n    for(int i = 0;\
    \ i < ssize(data) and x / (int)B < ssize(data[i]); i++, x = x / (int)B + 1) {\n\
    \      if (data[i][x / B] >> (x % B)) {\n        int y = x;\n        for(int j\
    \ = i; j >= 0; j--)\n          y = (y + countr_zero(data[j][y / B] >> (y % B)))\
    \ * B;\n        return y / B;\n      }\n    }\n    return sz;\n  }\n\n  int leq(int\
    \ x) {\n    if (x < 0) return -1;\n    chmin(x, sz - 1);\n    for(int i = 0; i\
    \ < ssize(data) and x >= 0; i++, x = x / (int)B - 1) {\n      if (data[i][x /\
    \ B] << (B - 1 - x % B)) {\n        int y = x;\n        for(int j = i; j >= 0;\
    \ j--)\n          y = (y - countl_zero(data[j][y / B] << (B - 1 - y % B))) * B\
    \ + (B - 1);\n        return y / B;\n      }\n    }\n    return -1;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fast_set.cpp
  requiredBy: []
  timestamp: '2026-01-05 01:33:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fast_set.cpp
layout: document
redirect_from:
- /library/ds/fast_set.cpp
- /library/ds/fast_set.cpp.html
title: ds/fast_set.cpp
---
