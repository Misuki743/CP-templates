---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':x:'
    path: test/vertex_get_range_contour_add_on_tree.test.cpp
    title: test/vertex_get_range_contour_add_on_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/pbdsSet.cpp\"\n//#include<ext/pb_ds/assoc_container.hpp>\n\
    //#include<ext/pb_ds/tree_policy.hpp>\n\n//usage: order_of_key(x) : number of\
    \ items strictly smaller than x\n//       find_by_order(k): K-th element in a\
    \ set (0-based)\n\nusing orderedSet = __gnu_pbds::tree<pii, __gnu_pbds::null_type,\
    \ less<pii>,\n  __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n"
  code: "//#include<ext/pb_ds/assoc_container.hpp>\n//#include<ext/pb_ds/tree_policy.hpp>\n\
    \n//usage: order_of_key(x) : number of items strictly smaller than x\n//     \
    \  find_by_order(k): K-th element in a set (0-based)\n\nusing orderedSet = __gnu_pbds::tree<pii,\
    \ __gnu_pbds::null_type, less<pii>,\n  __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pbdsSet.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/vertex_get_range_contour_add_on_tree.test.cpp
documentation_of: ds/pbdsSet.cpp
layout: document
redirect_from:
- /library/ds/pbdsSet.cpp
- /library/ds/pbdsSet.cpp.html
title: ds/pbdsSet.cpp
---
