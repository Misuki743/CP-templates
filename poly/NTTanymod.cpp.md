---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution_1e9+7.test.cpp
    title: test/convolution_1e9+7.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/15581
    - https://math314.hateblo.jp/entry/2015/05/07/014908
  bundledCode: "#line 1 \"poly/NTTanymod.cpp\"\n//reference: https://math314.hateblo.jp/entry/2015/05/07/014908\n\
    //reference: https://judge.yosupo.jp/submission/15581\n//remark: n * mod^2 < prod\
    \ of mods(~= 5e26) should be satisfied\n\ntemplate<class Mint>\nvector<Mint> convAnyMod(vector<Mint>\
    \ a, vector<Mint> b) {\n  using Mint0 = MontgomeryModInt<998244353>;\n  using\
    \ Mint1 = MontgomeryModInt<469762049>;\n  using Mint2 = MontgomeryModInt<167772161>;\n\
    \  NTT<23, 119, 3, Mint0> ntt0;\n  NTT<26, 7, 3, Mint1> ntt1;\n  NTT<25, 5, 3,\
    \ Mint2> ntt2;\n  vector<Mint0> a0(ssize(a)), b0(ssize(b));\n  vector<Mint1> a1(ssize(a)),\
    \ b1(ssize(b));\n  vector<Mint2> a2(ssize(a)), b2(ssize(b));\n  for(int i = 0;\
    \ i < ssize(a); i++)\n    a0[i] = a[i].get(), a1[i] = a[i].get(), a2[i] = a[i].get();\n\
    \  for(int i = 0; i < ssize(b); i++)\n    b0[i] = b[i].get(), b1[i] = b[i].get(),\
    \ b2[i] = b[i].get();\n  vector<Mint0> x = ntt0.conv(a0, b0);\n  vector<Mint1>\
    \ y = ntt1.conv(a1, b1);\n  vector<Mint2> z = ntt2.conv(a2, b2);\n  vector<Mint>\
    \ res(ssize(x));\n  constexpr uint32_t mod0 = ntt0.get_mod(), mod1 = ntt1.get_mod();\n\
    \  static const Mint1 im0 = 1 / Mint1(mod0);\n  static const Mint2 im1 = 1 / Mint2(mod1),\
    \ im0m1 = im1 / mod0;\n  static const Mint m0 = mod0, m0m1 = m0 * mod1;\n  for(int\
    \ i = 0; i < ssize(x); i++) {\n    int y0 = x[i].get();\n    int y1 = (im0 * (y[i]\
    \ - y0)).get();\n    int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();\n    res[i]\
    \ = y0 + m0 * y1 + m0m1 * y2;\n  }\n\n  return res;\n}\n"
  code: "//reference: https://math314.hateblo.jp/entry/2015/05/07/014908\n//reference:\
    \ https://judge.yosupo.jp/submission/15581\n//remark: n * mod^2 < prod of mods(~=\
    \ 5e26) should be satisfied\n\ntemplate<class Mint>\nvector<Mint> convAnyMod(vector<Mint>\
    \ a, vector<Mint> b) {\n  using Mint0 = MontgomeryModInt<998244353>;\n  using\
    \ Mint1 = MontgomeryModInt<469762049>;\n  using Mint2 = MontgomeryModInt<167772161>;\n\
    \  NTT<23, 119, 3, Mint0> ntt0;\n  NTT<26, 7, 3, Mint1> ntt1;\n  NTT<25, 5, 3,\
    \ Mint2> ntt2;\n  vector<Mint0> a0(ssize(a)), b0(ssize(b));\n  vector<Mint1> a1(ssize(a)),\
    \ b1(ssize(b));\n  vector<Mint2> a2(ssize(a)), b2(ssize(b));\n  for(int i = 0;\
    \ i < ssize(a); i++)\n    a0[i] = a[i].get(), a1[i] = a[i].get(), a2[i] = a[i].get();\n\
    \  for(int i = 0; i < ssize(b); i++)\n    b0[i] = b[i].get(), b1[i] = b[i].get(),\
    \ b2[i] = b[i].get();\n  vector<Mint0> x = ntt0.conv(a0, b0);\n  vector<Mint1>\
    \ y = ntt1.conv(a1, b1);\n  vector<Mint2> z = ntt2.conv(a2, b2);\n  vector<Mint>\
    \ res(ssize(x));\n  constexpr uint32_t mod0 = ntt0.get_mod(), mod1 = ntt1.get_mod();\n\
    \  static const Mint1 im0 = 1 / Mint1(mod0);\n  static const Mint2 im1 = 1 / Mint2(mod1),\
    \ im0m1 = im1 / mod0;\n  static const Mint m0 = mod0, m0m1 = m0 * mod1;\n  for(int\
    \ i = 0; i < ssize(x); i++) {\n    int y0 = x[i].get();\n    int y1 = (im0 * (y[i]\
    \ - y0)).get();\n    int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();\n    res[i]\
    \ = y0 + m0 * y1 + m0m1 * y2;\n  }\n\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/NTTanymod.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_1e9+7.test.cpp
documentation_of: poly/NTTanymod.cpp
layout: document
redirect_from:
- /library/poly/NTTanymod.cpp
- /library/poly/NTTanymod.cpp.html
title: poly/NTTanymod.cpp
---