---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aho_corasick.test.cpp
    title: test/aho_corasick.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/AhoCorasick.cpp\"\nstruct AhoCorasick {\n  struct\
    \ node {\n    static const int size = 26;\n    int nxt[size], p, link = -1, ex\
    \ = -1, leaf = 0;\n    char ch;\n\n    node(int _p = -1, char _ch = ' ') : p(_p),\
    \ ch(_ch) {\n      fill(nxt, nxt + size, -1);\n    }\n  };\n\n  vector<node> v;\n\
    \  AhoCorasick(int sz) : v(1) {\n    v.reserve(sz);\n  }\n\n  int insert(string\
    \ s) {\n    int now = 0;\n    for(char x : s) {\n      int id = x - 'a';\n   \
    \   if (v[now].nxt[id] == -1) {\n        v[now].nxt[id] = v.size();\n        v.emplace_back(now,\
    \ x);\n      }\n      now = v[now].nxt[id];\n    }\n    v[now].leaf = 1;\n   \
    \ return now;\n  }\n\n  int go(int now, char ch) {\n    int id = ch - 'a';\n \
    \   if (v[now].nxt[id] != -1) return v[now].nxt[id];\n    else if (now == 0) return\
    \ 0;\n    else return go(v[now].link, ch);\n  }\n\n  int calcLink(int now) {\n\
    \    if (now == 0 or v[now].p == 0) return 0;\n    else return go(v[v[now].p].link,\
    \ v[now].ch);\n  }\n\n  int calcExit(int now) {\n    if (now == 0) return -1;\n\
    \    else if (v[v[now].link].leaf) return v[now].link;\n    else return v[v[now].link].ex;\n\
    \  }\n\n  vector<int> build() {\n    vector<int> q(1, 0);\n    for(int i = 0;\
    \ i < ssize(q); i++) {\n      int now = q[i];\n      v[now].link = calcLink(now);\n\
    \      v[now].ex = calcExit(now);\n      for(int j = 0; j < node::size; j++)\n\
    \        if (v[now].nxt[j] != -1)\n          q.emplace_back(v[now].nxt[j]);\n\
    \    }\n    return q;\n  }\n};\n"
  code: "struct AhoCorasick {\n  struct node {\n    static const int size = 26;\n\
    \    int nxt[size], p, link = -1, ex = -1, leaf = 0;\n    char ch;\n\n    node(int\
    \ _p = -1, char _ch = ' ') : p(_p), ch(_ch) {\n      fill(nxt, nxt + size, -1);\n\
    \    }\n  };\n\n  vector<node> v;\n  AhoCorasick(int sz) : v(1) {\n    v.reserve(sz);\n\
    \  }\n\n  int insert(string s) {\n    int now = 0;\n    for(char x : s) {\n  \
    \    int id = x - 'a';\n      if (v[now].nxt[id] == -1) {\n        v[now].nxt[id]\
    \ = v.size();\n        v.emplace_back(now, x);\n      }\n      now = v[now].nxt[id];\n\
    \    }\n    v[now].leaf = 1;\n    return now;\n  }\n\n  int go(int now, char ch)\
    \ {\n    int id = ch - 'a';\n    if (v[now].nxt[id] != -1) return v[now].nxt[id];\n\
    \    else if (now == 0) return 0;\n    else return go(v[now].link, ch);\n  }\n\
    \n  int calcLink(int now) {\n    if (now == 0 or v[now].p == 0) return 0;\n  \
    \  else return go(v[v[now].p].link, v[now].ch);\n  }\n\n  int calcExit(int now)\
    \ {\n    if (now == 0) return -1;\n    else if (v[v[now].link].leaf) return v[now].link;\n\
    \    else return v[v[now].link].ex;\n  }\n\n  vector<int> build() {\n    vector<int>\
    \ q(1, 0);\n    for(int i = 0; i < ssize(q); i++) {\n      int now = q[i];\n \
    \     v[now].link = calcLink(now);\n      v[now].ex = calcExit(now);\n      for(int\
    \ j = 0; j < node::size; j++)\n        if (v[now].nxt[j] != -1)\n          q.emplace_back(v[now].nxt[j]);\n\
    \    }\n    return q;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/AhoCorasick.cpp
  requiredBy: []
  timestamp: '2025-08-23 17:38:12+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aho_corasick.test.cpp
documentation_of: string/AhoCorasick.cpp
layout: document
redirect_from:
- /library/string/AhoCorasick.cpp
- /library/string/AhoCorasick.cpp.html
title: string/AhoCorasick.cpp
---
