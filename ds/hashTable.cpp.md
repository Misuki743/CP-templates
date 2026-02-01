---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/associative_array.test.cpp
    title: test/associative_array.test.cpp
  - icon: ':x:'
    path: test/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':x:'
    path: test/vertex_get_range_contour_add_on_tree.test.cpp
    title: test/vertex_get_range_contour_add_on_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/62393
  bundledCode: "#line 1 \"ds/hashTable.cpp\"\n//source: https://codeforces.com/blog/entry/62393\n\
    //#include<ext/pb_ds/assoc_container.hpp>\n//#include<ext/pb_ds/tree_policy.hpp>\n\
    \nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t x) {\n       \
    \ x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\nusing namespace __gnu_pbds;\n\
    \n//gp_hash_table<ll, int, custom_hash> m({}, {}, {}, {}, {1 << 16});\n"
  code: "//source: https://codeforces.com/blog/entry/62393\n//#include<ext/pb_ds/assoc_container.hpp>\n\
    //#include<ext/pb_ds/tree_policy.hpp>\n\nstruct custom_hash {\n    static uint64_t\
    \ splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n        x = (x ^\
    \ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \        return x ^ (x >> 31);\n    }\n\n    size_t operator()(uint64_t x) const\
    \ {\n        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\nusing namespace __gnu_pbds;\n\
    \n//gp_hash_table<ll, int, custom_hash> m({}, {}, {}, {}, {1 << 16});\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/hashTable.cpp
  requiredBy: []
  timestamp: '2024-11-19 21:59:27+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/associative_array.test.cpp
  - test/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/vertex_get_range_contour_add_on_tree.test.cpp
documentation_of: ds/hashTable.cpp
layout: document
redirect_from:
- /library/ds/hashTable.cpp
- /library/ds/hashTable.cpp.html
title: ds/hashTable.cpp
---
