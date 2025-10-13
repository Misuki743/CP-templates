---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/frequency_table_of_tree_distance.test.cpp
    title: test/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/atcoder/ac-library)
  bundledCode: "#line 1 \"numtheory/crt.cpp\"\n//source: AtCoder Library (https://github.com/atcoder/ac-library)\n\
    \n#include <utility>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n// @param\
    \ m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long x, long\
    \ long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// (rem, mod)\nstd::pair<long long, long long> crt(const std::vector<long long>&\
    \ r,\n                                    const std::vector<long long>& m) {\n\
    \    assert(r.size() == m.size());\n    int n = int(r.size());\n    // Contracts:\
    \ 0 <= r0 < m0\n    long long r0 = 0, m0 = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n        assert(1 <= m[i]);\n        long long r1 = safe_mod(r[i], m[i]),\
    \ m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n       \
    \     std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n           \
    \ if (r0 % m1 != r1) return {0, 0};\n            continue;\n        }\n      \
    \  // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)\n\n        // (r0, m0),\
    \ (r1, m1) -> (r2, m2 = lcm(m0, m1));\n        // r2 % m0 = r0\n        // r2\
    \ % m1 = r1\n        // -> (r0 + x*m0) % m1 = r1\n        // -> x*u0*g = r1-r0\
    \ (mod u1*g) (u0*g = m0, u1*g = m1)\n        // -> x = (r1 - r0) / g * inv(u0)\
    \ (mod u1)\n\n        // im = inv(u0) (mod u1) (0 <= im < u1)\n        long long\
    \ g, im;\n        std::tie(g, im) = inv_gcd(m0, m1);\n\n        long long u1 =\
    \ (m1 / g);\n        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)\n        if ((r1\
    \ - r0) % g) return {0, 0};\n\n        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1\
    \ / g = lcm(m0, m1)\n        long long x = (r1 - r0) / g % u1 * im % u1;\n\n \
    \       // |r0| + |m0 * x|\n        // < m0 + m0 * (u1 - 1)\n        // = m0 +\
    \ m0 * m1 / g - m0\n        // = lcm(m0, m1)\n        r0 += x * m0;\n        m0\
    \ *= u1;  // -> lcm(m0, m1)\n        if (r0 < 0) r0 += m0;\n    }\n    return\
    \ {r0, m0};\n}\n"
  code: "//source: AtCoder Library (https://github.com/atcoder/ac-library)\n\n#include\
    \ <utility>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n// @param m `1\
    \ <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long x, long long\
    \ m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n// @param b `1\
    \ <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g\n\
    constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {\n\
    \    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// (rem, mod)\nstd::pair<long long, long long> crt(const std::vector<long long>&\
    \ r,\n                                    const std::vector<long long>& m) {\n\
    \    assert(r.size() == m.size());\n    int n = int(r.size());\n    // Contracts:\
    \ 0 <= r0 < m0\n    long long r0 = 0, m0 = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n        assert(1 <= m[i]);\n        long long r1 = safe_mod(r[i], m[i]),\
    \ m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n       \
    \     std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n           \
    \ if (r0 % m1 != r1) return {0, 0};\n            continue;\n        }\n      \
    \  // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)\n\n        // (r0, m0),\
    \ (r1, m1) -> (r2, m2 = lcm(m0, m1));\n        // r2 % m0 = r0\n        // r2\
    \ % m1 = r1\n        // -> (r0 + x*m0) % m1 = r1\n        // -> x*u0*g = r1-r0\
    \ (mod u1*g) (u0*g = m0, u1*g = m1)\n        // -> x = (r1 - r0) / g * inv(u0)\
    \ (mod u1)\n\n        // im = inv(u0) (mod u1) (0 <= im < u1)\n        long long\
    \ g, im;\n        std::tie(g, im) = inv_gcd(m0, m1);\n\n        long long u1 =\
    \ (m1 / g);\n        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)\n        if ((r1\
    \ - r0) % g) return {0, 0};\n\n        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1\
    \ / g = lcm(m0, m1)\n        long long x = (r1 - r0) / g % u1 * im % u1;\n\n \
    \       // |r0| + |m0 * x|\n        // < m0 + m0 * (u1 - 1)\n        // = m0 +\
    \ m0 * m1 / g - m0\n        // = lcm(m0, m1)\n        r0 += x * m0;\n        m0\
    \ *= u1;  // -> lcm(m0, m1)\n        if (r0 < 0) r0 += m0;\n    }\n    return\
    \ {r0, m0};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/crt.cpp
  requiredBy: []
  timestamp: '2024-09-22 15:08:26+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/frequency_table_of_tree_distance.test.cpp
documentation_of: numtheory/crt.cpp
layout: document
redirect_from:
- /library/numtheory/crt.cpp
- /library/numtheory/crt.cpp.html
title: numtheory/crt.cpp
---
