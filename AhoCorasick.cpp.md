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
  bundledCode: "#line 1 \"AhoCorasick.cpp\"\n/**\n * template name: AhoCorasick\n\
    \ * author: Misuki\n * last update: 2022/09/11\n */\n\nstruct AhoCorasick {\n\
    \  struct node {\n    static const int sigma = 26;\n    int nxt[sigma];\n    int\
    \ p = -1, link = -1, ex = -1;\n    char ch;\n    bool leaf = false;\n\n    node(int\
    \ _p, char _ch) {\n      fill(nxt, nxt + sigma, -1);\n      ch = _ch, p = _p;\n\
    \    }\n  };\n\n  vector<node> v;\n  AhoCorasick(int sz) {\n    v.reserve(sz);\n\
    \    v.emplace_back(-1, ' ');\n  }\n\n  void insert(string s) {\n    int now =\
    \ 0;\n    for(char X : s) {\n      int id = X - 'a';\n      if (v[now].nxt[id]\
    \ == -1) {\n        v[now].nxt[id] = v.size();\n        v.emplace_back(now, X);\n\
    \      }\n      now = v[now].nxt[id];\n    }\n    v[now].leaf = true;\n  }\n\n\
    \  int go(int now, char ch) {\n    int id = ch - 'a';\n    if (v[now].nxt[id]\
    \ != -1)\n      return v[now].nxt[id];\n    else if (now == 0)\n      return 0;\n\
    \    else\n      return go(v[now].link, ch);\n  }\n\n  int calcLink(int now) {\n\
    \    if (now == 0 or v[now].p == 0)\n      return 0;\n    else\n      return go(v[v[now].p].link,\
    \ v[now].ch);\n  }\n\n  int calcExit(int now) {\n    if (now == 0)\n      return\
    \ -1;\n    else if (v[v[now].link].leaf)\n      return v[now].link;\n    else\n\
    \      return v[v[now].link].ex;\n  }\n\n  void build() {\n    queue<int> q;\n\
    \    q.push(0);\n    while(!q.empty()) {\n      int now = q.front(); q.pop();\n\
    \      v[now].link = calcLink(now);\n      v[now].ex = calcExit(now);\n      for(int\
    \ i = 0; i < node::sigma; i++)\n        if (v[now].nxt[i] != -1)\n          q.push(v[now].nxt[i]);\n\
    \    }\n  }\n\n  string nodeString(int now) {\n    string res;\n    while(now\
    \ != 0)\n      res += v[now].ch, now = v[now].p;\n    reverse(res.begin(), res.end());\n\
    \    return res;\n  }\n};\n"
  code: "/**\n * template name: AhoCorasick\n * author: Misuki\n * last update: 2022/09/11\n\
    \ */\n\nstruct AhoCorasick {\n  struct node {\n    static const int sigma = 26;\n\
    \    int nxt[sigma];\n    int p = -1, link = -1, ex = -1;\n    char ch;\n    bool\
    \ leaf = false;\n\n    node(int _p, char _ch) {\n      fill(nxt, nxt + sigma,\
    \ -1);\n      ch = _ch, p = _p;\n    }\n  };\n\n  vector<node> v;\n  AhoCorasick(int\
    \ sz) {\n    v.reserve(sz);\n    v.emplace_back(-1, ' ');\n  }\n\n  void insert(string\
    \ s) {\n    int now = 0;\n    for(char X : s) {\n      int id = X - 'a';\n   \
    \   if (v[now].nxt[id] == -1) {\n        v[now].nxt[id] = v.size();\n        v.emplace_back(now,\
    \ X);\n      }\n      now = v[now].nxt[id];\n    }\n    v[now].leaf = true;\n\
    \  }\n\n  int go(int now, char ch) {\n    int id = ch - 'a';\n    if (v[now].nxt[id]\
    \ != -1)\n      return v[now].nxt[id];\n    else if (now == 0)\n      return 0;\n\
    \    else\n      return go(v[now].link, ch);\n  }\n\n  int calcLink(int now) {\n\
    \    if (now == 0 or v[now].p == 0)\n      return 0;\n    else\n      return go(v[v[now].p].link,\
    \ v[now].ch);\n  }\n\n  int calcExit(int now) {\n    if (now == 0)\n      return\
    \ -1;\n    else if (v[v[now].link].leaf)\n      return v[now].link;\n    else\n\
    \      return v[v[now].link].ex;\n  }\n\n  void build() {\n    queue<int> q;\n\
    \    q.push(0);\n    while(!q.empty()) {\n      int now = q.front(); q.pop();\n\
    \      v[now].link = calcLink(now);\n      v[now].ex = calcExit(now);\n      for(int\
    \ i = 0; i < node::sigma; i++)\n        if (v[now].nxt[i] != -1)\n          q.push(v[now].nxt[i]);\n\
    \    }\n  }\n\n  string nodeString(int now) {\n    string res;\n    while(now\
    \ != 0)\n      res += v[now].ch, now = v[now].p;\n    reverse(res.begin(), res.end());\n\
    \    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: AhoCorasick.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: AhoCorasick.cpp
layout: document
redirect_from:
- /library/AhoCorasick.cpp
- /library/AhoCorasick.cpp.html
title: AhoCorasick.cpp
---
