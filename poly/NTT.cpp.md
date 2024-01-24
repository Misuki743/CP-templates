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
  bundledCode: "#line 1 \"poly/NTT.cpp\"\n//remark: MOD = 2^K * C + 1, R is a primitive\
    \ root modulo MOD\n//remark: a.size() <= 2^K must be satisfied\n//some common\
    \ modulo: 998244353  = 2^23 * 119 + 1, R = 3\n//                    469762049\
    \  = 2^26 * 7   + 1, R = 3\n//                    1224736769 = 2^24 * 73  + 1,\
    \ R = 3\n\ntemplate<int32_t k, int32_t c, int32_t r>\nstruct NTT {\n\n  using\
    \ u32 = uint32_t;\n  static const ll mod = (1ll << k) * c + 1;\n\n  static ll\
    \ binpow(ll a, ll b) {\n    if (b == 0)\n      return 1;\n    if (a == 0)\n  \
    \    return 0;\n    ll d = 1;\n    while(b) {\n      if (b & 1) d = d * a % mod;\n\
    \      b >>= 1, a = a * a % mod;\n    }\n    return d;\n  }\n\n  static ll inv(ll\
    \ a) { return binpow(a, mod - 2); }\n  static constexpr ll get_mod() { return\
    \ mod; }\n\n  static void ntt(vector<ll> &a, bool inverse) {\n    static array<ll,\
    \ k + 1> w = {}, w_inv = {};\n    if (w[k] == 0) {\n      w[k] = binpow(r, c);\n\
    \      for(int i = k - 1; i >= 0; i--)\n        w[i] = w[i + 1] * w[i + 1] % mod;\n\
    \      for(int i = 0; i <= k; i++)\n        w_inv[i] = inv(w[i]);\n    }\n   \
    \ int n = ssize(a);\n    vector<ll> tmp = a;\n    for(int i = 0; i < ssize(a);\
    \ i++) {\n      int idx = 0, lgn = bit_width((u32)n) - 1;\n      for(int j = lgn\
    \ - 1; j >= 0; j--)\n        idx = (idx << 1) | ((i >> (lgn - j - 1)) & 1);\n\
    \      a[idx] = tmp[i];\n    }\n\n    for(int l = 2; l <= n; l <<= 1) {\n    \
    \  const ll w_l = (inverse ? w_inv[bit_width((u32)l) - 1] : w[bit_width((u32)l)\
    \ - 1]);\n\n      for(int i = 0; i < n; i += l) {\n        ll w = 1;\n       \
    \ for(int j = 0; j < (l >> 1); j++) {\n          ll t = a[i + j + l / 2] * w %\
    \ mod;\n          a[i + j + l / 2] = (a[i + j] - t + mod) % mod;\n          a[i\
    \ + j] = (a[i + j] + t) % mod;\n          w = w * w_l % mod;\n        }\n    \
    \  }\n    }\n\n    if (inverse) {\n      ll Inv = inv(n);\n      for(int i = 0;\
    \ i < ssize(a); i++)\n        a[i] = a[i] * Inv % mod;\n    }\n  }\n\n  vector<ll>\
    \ conv(vector<ll> a, vector<ll> b) {\n    int sz = ssize(a) + ssize(b) - 1;\n\
    \    int n = bit_ceil((u32)sz);\n\n    a.resize(n, 0);\n    ntt(a, false);\n \
    \   b.resize(n, 0);\n    ntt(b, false);\n\n    for(int i = 0; i < n; i++)\n  \
    \    a[i] = a[i] * b[i] % mod;\n\n    ntt(a, true);\n\n    a.resize(sz);\n\n \
    \   return a;\n  }\n};\n"
  code: "//remark: MOD = 2^K * C + 1, R is a primitive root modulo MOD\n//remark:\
    \ a.size() <= 2^K must be satisfied\n//some common modulo: 998244353  = 2^23 *\
    \ 119 + 1, R = 3\n//                    469762049  = 2^26 * 7   + 1, R = 3\n//\
    \                    1224736769 = 2^24 * 73  + 1, R = 3\n\ntemplate<int32_t k,\
    \ int32_t c, int32_t r>\nstruct NTT {\n\n  using u32 = uint32_t;\n  static const\
    \ ll mod = (1ll << k) * c + 1;\n\n  static ll binpow(ll a, ll b) {\n    if (b\
    \ == 0)\n      return 1;\n    if (a == 0)\n      return 0;\n    ll d = 1;\n  \
    \  while(b) {\n      if (b & 1) d = d * a % mod;\n      b >>= 1, a = a * a % mod;\n\
    \    }\n    return d;\n  }\n\n  static ll inv(ll a) { return binpow(a, mod - 2);\
    \ }\n  static constexpr ll get_mod() { return mod; }\n\n  static void ntt(vector<ll>\
    \ &a, bool inverse) {\n    static array<ll, k + 1> w = {}, w_inv = {};\n    if\
    \ (w[k] == 0) {\n      w[k] = binpow(r, c);\n      for(int i = k - 1; i >= 0;\
    \ i--)\n        w[i] = w[i + 1] * w[i + 1] % mod;\n      for(int i = 0; i <= k;\
    \ i++)\n        w_inv[i] = inv(w[i]);\n    }\n    int n = ssize(a);\n    vector<ll>\
    \ tmp = a;\n    for(int i = 0; i < ssize(a); i++) {\n      int idx = 0, lgn =\
    \ bit_width((u32)n) - 1;\n      for(int j = lgn - 1; j >= 0; j--)\n        idx\
    \ = (idx << 1) | ((i >> (lgn - j - 1)) & 1);\n      a[idx] = tmp[i];\n    }\n\n\
    \    for(int l = 2; l <= n; l <<= 1) {\n      const ll w_l = (inverse ? w_inv[bit_width((u32)l)\
    \ - 1] : w[bit_width((u32)l) - 1]);\n\n      for(int i = 0; i < n; i += l) {\n\
    \        ll w = 1;\n        for(int j = 0; j < (l >> 1); j++) {\n          ll\
    \ t = a[i + j + l / 2] * w % mod;\n          a[i + j + l / 2] = (a[i + j] - t\
    \ + mod) % mod;\n          a[i + j] = (a[i + j] + t) % mod;\n          w = w *\
    \ w_l % mod;\n        }\n      }\n    }\n\n    if (inverse) {\n      ll Inv =\
    \ inv(n);\n      for(int i = 0; i < ssize(a); i++)\n        a[i] = a[i] * Inv\
    \ % mod;\n    }\n  }\n\n  vector<ll> conv(vector<ll> a, vector<ll> b) {\n    int\
    \ sz = ssize(a) + ssize(b) - 1;\n    int n = bit_ceil((u32)sz);\n\n    a.resize(n,\
    \ 0);\n    ntt(a, false);\n    b.resize(n, 0);\n    ntt(b, false);\n\n    for(int\
    \ i = 0; i < n; i++)\n      a[i] = a[i] * b[i] % mod;\n\n    ntt(a, true);\n\n\
    \    a.resize(sz);\n\n    return a;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/NTT.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/NTT.cpp
layout: document
redirect_from:
- /library/poly/NTT.cpp
- /library/poly/NTT.cpp.html
title: poly/NTT.cpp
---
