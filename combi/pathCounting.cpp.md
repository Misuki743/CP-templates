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
  bundledCode: "#line 1 \"combi/pathCounting.cpp\"\n//Given initial state f and transition\
    \ g and lowerbound constraint lb,\n//which should be non-decreasing, compute result\
    \ after transite (|lb| - 1) times\n//in O(n(D + |g|)lg(n(D + |g|))lgn + (|f| +\
    \ |g|)lg(|f| + |g|)) time complexity.\n\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/FPS.cpp>\n//#include<poly/NTTmint.cpp>\n\ntemplate<class Mint>\n\
    FPS<Mint> pathCounting(FPS<Mint> f, FPS<Mint> g, vector<int> lb) {\n  auto calc\
    \ = [&](int l, int r, FPS<Mint> f, auto self) -> FPS<Mint> {\n    if (l == r)\
    \ {\n      dbg(r);\n      dbg(f << lb[r]);\n      return f; \n    } else if (l\
    \ + 1 == r) {\n      dbg(r);\n      dbg((f * g) << lb[l]);\n      return (f *\
    \ g) >> (lb[r] - lb[l]);\n    } else {\n      FPS<Mint> ret = (f >> (lb[r] - lb[l]))\
    \ * g.pow(r - l);\n      if (l == 1 and r == 3) {\n        dbg(f >> 2);\n    \
    \    dbg(g.pow(2));\n        dbg(ret);\n      }\n      int mid = (l + r) / 2;\n\
    \      FPS<Mint> tmp = self(l, mid, FPS<Mint>(f.begin(), f.begin() + min((int)f.size(),\
    \ lb[r] - lb[l])), self);\n      return ret + self(mid, r, tmp, self);\n    }\n\
    \  };\n\n  return calc(0, ssize(lb) - 1, f >> lb[0], calc) << lb.back();\n}\n"
  code: "//Given initial state f and transition g and lowerbound constraint lb,\n\
    //which should be non-decreasing, compute result after transite (|lb| - 1) times\n\
    //in O(n(D + |g|)lg(n(D + |g|))lgn + (|f| + |g|)lg(|f| + |g|)) time complexity.\n\
    \n//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/FPS.cpp>\n//#include<poly/NTTmint.cpp>\n\
    \ntemplate<class Mint>\nFPS<Mint> pathCounting(FPS<Mint> f, FPS<Mint> g, vector<int>\
    \ lb) {\n  auto calc = [&](int l, int r, FPS<Mint> f, auto self) -> FPS<Mint>\
    \ {\n    if (l == r) {\n      dbg(r);\n      dbg(f << lb[r]);\n      return f;\
    \ \n    } else if (l + 1 == r) {\n      dbg(r);\n      dbg((f * g) << lb[l]);\n\
    \      return (f * g) >> (lb[r] - lb[l]);\n    } else {\n      FPS<Mint> ret =\
    \ (f >> (lb[r] - lb[l])) * g.pow(r - l);\n      if (l == 1 and r == 3) {\n   \
    \     dbg(f >> 2);\n        dbg(g.pow(2));\n        dbg(ret);\n      }\n     \
    \ int mid = (l + r) / 2;\n      FPS<Mint> tmp = self(l, mid, FPS<Mint>(f.begin(),\
    \ f.begin() + min((int)f.size(), lb[r] - lb[l])), self);\n      return ret + self(mid,\
    \ r, tmp, self);\n    }\n  };\n\n  return calc(0, ssize(lb) - 1, f >> lb[0], calc)\
    \ << lb.back();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/pathCounting.cpp
  requiredBy: []
  timestamp: '2024-05-11 22:13:26+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: combi/pathCounting.cpp
layout: document
redirect_from:
- /library/combi/pathCounting.cpp
- /library/combi/pathCounting.cpp.html
title: combi/pathCounting.cpp
---
