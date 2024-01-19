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
  bundledCode: "#line 1 \"ds/pbdsSet.cpp\"\n/**\n * template name: pbdsSet\n * author:\
    \ __Shioko(Misuki)\n * last update: 2022/01/13\n * header: bits/extc++.h (ext/pb_ds/assoc_container.hpp\
    \ and ext/pb_ds/tree_policy.hpp for cf)\n * usage: order_of_key(x) : number of\
    \ items strictly smaller than x\n *        find_by_order(k): K-th element in a\
    \ set (0-based)\n */\n\n\nusing orderedSet = __gnu_pbds::tree<pii, __gnu_pbds::null_type,\
    \ less<pii>,\n  __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n"
  code: "/**\n * template name: pbdsSet\n * author: __Shioko(Misuki)\n * last update:\
    \ 2022/01/13\n * header: bits/extc++.h (ext/pb_ds/assoc_container.hpp and ext/pb_ds/tree_policy.hpp\
    \ for cf)\n * usage: order_of_key(x) : number of items strictly smaller than x\n\
    \ *        find_by_order(k): K-th element in a set (0-based)\n */\n\n\nusing orderedSet\
    \ = __gnu_pbds::tree<pii, __gnu_pbds::null_type, less<pii>,\n  __gnu_pbds::rb_tree_tag,\
    \ __gnu_pbds::tree_order_statistics_node_update>;\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pbdsSet.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/pbdsSet.cpp
layout: document
redirect_from:
- /library/ds/pbdsSet.cpp
- /library/ds/pbdsSet.cpp.html
title: ds/pbdsSet.cpp
---
