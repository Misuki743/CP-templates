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
  bundledCode: "#line 1 \"poly/semiOnlineConvolution.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\ntemplate<class Mint>\n\
    FPS<Mint> semiOnlineConvolution(FPS<Mint> f, FPS<Mint> g) {\n  auto calc = [&](int\
    \ l, int r, auto self) -> void {\n    if (l + 1 >= r) return;\n    int mid = (l\
    \ + r) / 2;\n    self(l, mid, self);\n    {\n      FPS<Mint> ff(f.begin() + l,\
    \ f.begin() + mid);\n      FPS<Mint> gg(g.begin(), g.begin() + min(r - l, (int)g.size()));\n\
    \      auto h = ff * gg;\n      for(int i = mid - l; i < ssize(h) and i + l <\
    \ ssize(f); i++)\n        f[i + l] += h[i];\n    }\n    self(mid, r, self);\n\
    \  };\n\n  calc(0, ssize(f), calc);\n\n  return f;\n}\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\
    \ntemplate<class Mint>\nFPS<Mint> semiOnlineConvolution(FPS<Mint> f, FPS<Mint>\
    \ g) {\n  auto calc = [&](int l, int r, auto self) -> void {\n    if (l + 1 >=\
    \ r) return;\n    int mid = (l + r) / 2;\n    self(l, mid, self);\n    {\n   \
    \   FPS<Mint> ff(f.begin() + l, f.begin() + mid);\n      FPS<Mint> gg(g.begin(),\
    \ g.begin() + min(r - l, (int)g.size()));\n      auto h = ff * gg;\n      for(int\
    \ i = mid - l; i < ssize(h) and i + l < ssize(f); i++)\n        f[i + l] += h[i];\n\
    \    }\n    self(mid, r, self);\n  };\n\n  calc(0, ssize(f), calc);\n\n  return\
    \ f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/semiOnlineConvolution.cpp
  requiredBy: []
  timestamp: '2024-05-11 22:13:26+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/semiOnlineConvolution.cpp
layout: document
redirect_from:
- /library/poly/semiOnlineConvolution.cpp
- /library/poly/semiOnlineConvolution.cpp.html
title: poly/semiOnlineConvolution.cpp
---
