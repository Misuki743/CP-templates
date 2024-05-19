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
  bundledCode: "#line 1 \"numtheory/sumOfFloorOfLinear.cpp\"\n//source: atcoder library\n\
    \n//compute sum_{i = 0}^{n - 1} floor((ai + b) / m)\nunsigned long long floor_sum_unsigned(unsigned\
    \ long long n,\n                                      unsigned long long m,\n\
    \                                      unsigned long long a,\n               \
    \                       unsigned long long b) {\n    unsigned long long ans =\
    \ 0;\n    while (true) {\n        if (a >= m) {\n            ans += n * (n - 1)\
    \ / 2 * (a / m);\n            a %= m;\n        }\n        if (b >= m) {\n    \
    \        ans += n * (b / m);\n            b %= m;\n        }\n\n        unsigned\
    \ long long y_max = a * n + b;\n        if (y_max < m) break;\n        // y_max\
    \ < m * (n + 1)\n        // floor(y_max / m) <= n\n        n = (unsigned long\
    \ long)(y_max / m);\n        b = (unsigned long long)(y_max % m);\n        std::swap(m,\
    \ a);\n    }\n    return ans;\n}\n\nlong long floor_sum(long long n, long long\
    \ m, long long a, long long b) {\n    assert(0 <= n && n < (1LL << 32));\n   \
    \ assert(1 <= m && m < (1LL << 32));\n    unsigned long long ans = 0;\n    if\
    \ (a < 0) {\n        unsigned long long a2 = safe_mod(a, m);\n        ans -= 1ULL\
    \ * n * (n - 1) / 2 * ((a2 - a) / m);\n        a = a2;\n    }\n    if (b < 0)\
    \ {\n        unsigned long long b2 = safe_mod(b, m);\n        ans -= 1ULL * n\
    \ * ((b2 - b) / m);\n        b = b2;\n    }\n    return ans + floor_sum_unsigned(n,\
    \ m, a, b);\n}\n"
  code: "//source: atcoder library\n\n//compute sum_{i = 0}^{n - 1} floor((ai + b)\
    \ / m)\nunsigned long long floor_sum_unsigned(unsigned long long n,\n        \
    \                              unsigned long long m,\n                       \
    \               unsigned long long a,\n                                      unsigned\
    \ long long b) {\n    unsigned long long ans = 0;\n    while (true) {\n      \
    \  if (a >= m) {\n            ans += n * (n - 1) / 2 * (a / m);\n            a\
    \ %= m;\n        }\n        if (b >= m) {\n            ans += n * (b / m);\n \
    \           b %= m;\n        }\n\n        unsigned long long y_max = a * n + b;\n\
    \        if (y_max < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max\
    \ / m) <= n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned\
    \ long long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\
    \nlong long floor_sum(long long n, long long m, long long a, long long b) {\n\
    \    assert(0 <= n && n < (1LL << 32));\n    assert(1 <= m && m < (1LL << 32));\n\
    \    unsigned long long ans = 0;\n    if (a < 0) {\n        unsigned long long\
    \ a2 = safe_mod(a, m);\n        ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\n\
    \        a = a2;\n    }\n    if (b < 0) {\n        unsigned long long b2 = safe_mod(b,\
    \ m);\n        ans -= 1ULL * n * ((b2 - b) / m);\n        b = b2;\n    }\n   \
    \ return ans + floor_sum_unsigned(n, m, a, b);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/sumOfFloorOfLinear.cpp
  requiredBy: []
  timestamp: '2024-05-19 17:15:40+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/sumOfFloorOfLinear.cpp
layout: document
redirect_from:
- /library/numtheory/sumOfFloorOfLinear.cpp
- /library/numtheory/sumOfFloorOfLinear.cpp.html
title: numtheory/sumOfFloorOfLinear.cpp
---
