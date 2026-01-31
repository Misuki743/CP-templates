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
  bundledCode: "#line 1 \"ds/DSU/queue_DSU.cpp\"\n//#include \"ds/DSU/rollback_DSU.cpp\"\
    \n\nstruct queue_DSU {\n  int fa = 0, fb = 0;\n  rollback_DSU dsu;\n  string s;\n\
    \  vector<int> ts;\n  vector<pii> op;\n\n  queue_DSU(int size) : dsu(size) {}\n\
    \n  bool merge(int u, int v) {\n    op.emplace_back(u, v);\n    s += 'B', fb++;\n\
    \    ts.emplace_back(dsu.time());\n    return dsu.merge(u, v);\n  }\n  \n  void\
    \ undo(bool fake = false) {\n    if (s.back() == 'B') {\n      int ga = 0, gb\
    \ = 0;\n      vi ta, tb;\n      vc<pii> opa, opb;\n      int i = ssize(s) - 1;\n\
    \      while(i + 1 == ssize(s) or (gb > ga and ga != fa)) {\n        if (s[i]\
    \ == 'A')\n          ga++, ta.emplace_back(ts[i]), opa.emplace_back(op[i--]);\n\
    \        else\n          gb++, tb.emplace_back(ts[i]), opb.emplace_back(op[i--]);\n\
    \      }\n      i++;\n      if (ga == 0) {\n        dsu.rollback(ts[0]);\n   \
    \     vector<int>().swap(ts);\n        ranges::reverse(op);\n        for(auto\
    \ [u, v] : op) {\n          ts.emplace_back(dsu.time());\n          dsu.merge(u,\
    \ v);\n        }\n        fill(s.begin(), s.end(), 'A');\n        fa = ssize(s),\
    \ fb = 0;\n      } else {\n        dsu.rollback(ts[i]);\n        for(auto [u,\
    \ v] : opb | views::reverse) {\n          ts[i] = dsu.time();\n          s[i]\
    \ = 'B';\n          op[i++] = pair(u, v);\n          dsu.merge(u, v);\n      \
    \  }\n        for(auto [u, v] : opa | views::reverse) {\n          ts[i] = dsu.time();\n\
    \          s[i] = 'A';\n          op[i++] = pair(u, v);\n          dsu.merge(u,\
    \ v);\n        }\n      }\n    }\n\n    if (!fake)\n      dsu.rollback(ts.back());\n\
    \    s.pop_back(), fa--;\n    ts.pop_back();\n    op.pop_back();\n  }\n\n  int\
    \ cc() { return (ssize(dsu.his) - dsu.nxt) / 2; }\n};\n"
  code: "//#include \"ds/DSU/rollback_DSU.cpp\"\n\nstruct queue_DSU {\n  int fa =\
    \ 0, fb = 0;\n  rollback_DSU dsu;\n  string s;\n  vector<int> ts;\n  vector<pii>\
    \ op;\n\n  queue_DSU(int size) : dsu(size) {}\n\n  bool merge(int u, int v) {\n\
    \    op.emplace_back(u, v);\n    s += 'B', fb++;\n    ts.emplace_back(dsu.time());\n\
    \    return dsu.merge(u, v);\n  }\n  \n  void undo(bool fake = false) {\n    if\
    \ (s.back() == 'B') {\n      int ga = 0, gb = 0;\n      vi ta, tb;\n      vc<pii>\
    \ opa, opb;\n      int i = ssize(s) - 1;\n      while(i + 1 == ssize(s) or (gb\
    \ > ga and ga != fa)) {\n        if (s[i] == 'A')\n          ga++, ta.emplace_back(ts[i]),\
    \ opa.emplace_back(op[i--]);\n        else\n          gb++, tb.emplace_back(ts[i]),\
    \ opb.emplace_back(op[i--]);\n      }\n      i++;\n      if (ga == 0) {\n    \
    \    dsu.rollback(ts[0]);\n        vector<int>().swap(ts);\n        ranges::reverse(op);\n\
    \        for(auto [u, v] : op) {\n          ts.emplace_back(dsu.time());\n   \
    \       dsu.merge(u, v);\n        }\n        fill(s.begin(), s.end(), 'A');\n\
    \        fa = ssize(s), fb = 0;\n      } else {\n        dsu.rollback(ts[i]);\n\
    \        for(auto [u, v] : opb | views::reverse) {\n          ts[i] = dsu.time();\n\
    \          s[i] = 'B';\n          op[i++] = pair(u, v);\n          dsu.merge(u,\
    \ v);\n        }\n        for(auto [u, v] : opa | views::reverse) {\n        \
    \  ts[i] = dsu.time();\n          s[i] = 'A';\n          op[i++] = pair(u, v);\n\
    \          dsu.merge(u, v);\n        }\n      }\n    }\n\n    if (!fake)\n   \
    \   dsu.rollback(ts.back());\n    s.pop_back(), fa--;\n    ts.pop_back();\n  \
    \  op.pop_back();\n  }\n\n  int cc() { return (ssize(dsu.his) - dsu.nxt) / 2;\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU/queue_DSU.cpp
  requiredBy: []
  timestamp: '2026-01-31 20:47:40+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/DSU/queue_DSU.cpp
layout: document
redirect_from:
- /library/ds/DSU/queue_DSU.cpp
- /library/ds/DSU/queue_DSU.cpp.html
title: ds/DSU/queue_DSU.cpp
---
