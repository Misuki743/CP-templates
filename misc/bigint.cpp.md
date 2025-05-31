---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/addition_of_big_integers.test.cpp
    title: test/addition_of_big_integers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/addition_of_big_integers_2.test.cpp
    title: test/addition_of_big_integers_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/multiplication_of_big_intergers.test.cpp
    title: test/multiplication_of_big_intergers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/multiplication_of_big_intergers_2.test.cpp
    title: test/multiplication_of_big_intergers_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/bigint.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n\ntemplate<bool fast_mul = true>\nstruct bigint\
    \ {\n  int sgn;\n  vector<int> val;\n  static constexpr int LOG = fast_mul ? 1\
    \ : 9;\n  static constexpr int W = fast_mul ? 10 : 1'000'000'000;\n\n  bigint(string\
    \ s = \"0\") {\n    if (!s.empty() and s[0] == '-') {\n      sgn = -1;\n     \
    \ s.erase(s.begin());\n    } else {\n      sgn = 1;\n    }\n    s.insert(0, (LOG\
    \ - ssize(s) % LOG) % LOG, '0');\n    if (s.empty()) s = string(LOG, '0');\n \
    \   val.resize(size(s) / LOG);\n    ranges::reverse(s);\n    for(int i = ssize(s)\
    \ - 1; i >= 0; i--)\n      val[i / LOG] = val[i / LOG] * 10 + (s[i] - '0');\n\
    \  }\n\n  int log10() {\n    assert(sgn == 1);\n    int x = LOG * (ssize(val)\
    \ - 1), y = val.back();\n    while(y) x++, y /= 10;\n    return x - 1;\n  }\n\n\
    \  void norm() {\n    if (sgn == -1 and ssize(val) == 1 and val[0] == 0)\n   \
    \   sgn = 1;\n  }\n\n  bool abs_less(const bigint &b) const {\n    if (size(val)\
    \ != size(b.val))\n      return size(val) < size(b.val);\n    for(int i = ssize(val)\
    \ - 1; i >= 0; i--)\n      if (val[i] != b.val[i])\n        return val[i] < b.val[i];\n\
    \    return false;\n  }\n\n  bigint& operator+=(const bigint &b) {\n    if (sgn\
    \ != b.sgn) {\n      *this -= -b;\n    } else if (abs_less(b)) {\n      *this\
    \ = b + *this;\n    } else {\n      for(int i = 0; i < min(ssize(val), ssize(b.val));\
    \ i++) {\n        val[i] += b.val[i];\n        if (int q = val[i] / W; q > 0)\
    \ {\n          if (i + 1 == ssize(val)) val.emplace_back();\n          val[i]\
    \ -= q * W, val[i + 1] += q;\n        }\n      }\n      int j = min(ssize(val),\
    \ ssize(b.val));\n      while(j < ssize(val) and val[j] >= W) {\n        int q\
    \ = val[j] / W;\n        if (j + 1 == ssize(val)) val.emplace_back();\n      \
    \  val[j] -= q * W, val[j + 1] += q, j++;\n      }\n    }\n    norm();\n    return\
    \ *this;\n  }\n\n  bigint& operator-=(const bigint &b) {\n    if (sgn != b.sgn)\
    \ {\n      *this += -b;\n    } else if (abs_less(b)) {\n      *this = b - *this,\
    \ sgn = -sgn;\n    } else {\n      for(int i = 0; i < min(ssize(val), ssize(b.val));\
    \ i++) {\n        val[i] -= b.val[i];\n        if (val[i] < 0)\n          val[i]\
    \ += W, val[i + 1] -= 1;\n      }\n      int j = min(ssize(val), ssize(b.val));\n\
    \      while(j < ssize(val) and val[j] < 0)\n        val[j] += W, val[j + 1] -=\
    \ 1, j++;\n      while(ssize(val) > 1 and val.back() == 0) val.pop_back();\n \
    \   }\n    norm();\n    return *this;\n  }\n\n  bigint& operator*=(const bigint\
    \ &b) {\n    if constexpr (LOG == 1) {\n      static NTT ntt;\n      vector<mint>\
    \ c(size(val)), d(size(b.val));\n      for(int i = 0; i < ssize(c); i++) c[i]\
    \ = val[i];\n      for(int i = 0; i < ssize(d); i++) d[i] = b.val[i];\n      c\
    \ = ntt.conv(c, d);\n      vector<int> tmp(ssize(c));\n      for(int i = 0; i\
    \ < ssize(c); i++)\n        tmp[i] = c[i].get();\n      for(int i = 0; i < ssize(tmp);\
    \ i++) {\n        if (int q = tmp[i] / W; q > 0) {\n          if (i + 1 == ssize(tmp))\
    \ tmp.emplace_back();\n          tmp[i] -= q * W, tmp[i + 1] += q;\n        }\n\
    \      }\n      val.swap(tmp);\n    } else {\n      vector<int> tmp(ssize(val)\
    \ + ssize(b.val) + 1);\n      for(int i = 0; i < ssize(val); i++) {\n        for(int\
    \ j = 0; j < ssize(b.val); j++) {\n          if (int q = tmp[i + j] / W; q > 0)\n\
    \            tmp[i + j] -= q * W, tmp[i + j + 1] += q;\n          ll x = (ll)val[i]\
    \ * b.val[j];\n          tmp[i + j] += x % W, tmp[i + j + 1] += x / W;\n     \
    \     if (int q = tmp[i + j] / W; q > 0)\n            tmp[i + j] -= q * W, tmp[i\
    \ + j + 1] += q;\n        }\n      }\n      val.swap(tmp);\n    }\n    while(ssize(val)\
    \ > 1 and val.back() == 0) val.pop_back();\n    sgn *= b.sgn;\n    norm();\n \
    \   return *this;\n  }\n\n  bool operator<(const bigint &b) const {\n    if (sgn\
    \ != b.sgn) return sgn == -1;\n    else if (sgn == 1) return abs_less(b);\n  \
    \  else return b.abs_less(*this);\n  }\n  bool operator>(const bigint &b) const\
    \ { return b < *this; }\n  bool operator<=(const bigint &b) const { return !(*this\
    \ > b); }\n  bool operator>=(const bigint &b) const { return !(*this < b); }\n\
    \  bool operator==(const bigint &b) const { return sgn == b.sgn and val == b.val;\
    \ }\n  friend bigint operator+(bigint a, bigint b) { return a += b; }\n  friend\
    \ bigint operator-(bigint a, bigint b) { return a -= b; }\n  friend bigint operator*(bigint\
    \ a, bigint b) { return a *= b; }\n\n  bigint operator-() const {\n    bigint\
    \ b = *this;\n    b.sgn = -b.sgn;\n    return b;\n  }\n\n  string to_string()\
    \ const {\n    string s;\n    for(int i = 0; i < ssize(val); i++) {\n      int\
    \ x = val[i];\n      for(int j = 0; j < LOG; j++)\n        s += '0' + (x % 10),\
    \ x /= 10;\n    }\n    while(ssize(s) > 1 and s.back() == '0') s.pop_back();\n\
    \    if (sgn == -1) s += '-';\n    ranges::reverse(s);\n    return s;\n  }\n\n\
    \  friend ostream& operator<<(ostream& os, const bigint& b) {\n    return os <<\
    \ b.to_string();\n  }\n};\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/NTTmint.cpp>\n\n\
    template<bool fast_mul = true>\nstruct bigint {\n  int sgn;\n  vector<int> val;\n\
    \  static constexpr int LOG = fast_mul ? 1 : 9;\n  static constexpr int W = fast_mul\
    \ ? 10 : 1'000'000'000;\n\n  bigint(string s = \"0\") {\n    if (!s.empty() and\
    \ s[0] == '-') {\n      sgn = -1;\n      s.erase(s.begin());\n    } else {\n \
    \     sgn = 1;\n    }\n    s.insert(0, (LOG - ssize(s) % LOG) % LOG, '0');\n \
    \   if (s.empty()) s = string(LOG, '0');\n    val.resize(size(s) / LOG);\n   \
    \ ranges::reverse(s);\n    for(int i = ssize(s) - 1; i >= 0; i--)\n      val[i\
    \ / LOG] = val[i / LOG] * 10 + (s[i] - '0');\n  }\n\n  int log10() {\n    assert(sgn\
    \ == 1);\n    int x = LOG * (ssize(val) - 1), y = val.back();\n    while(y) x++,\
    \ y /= 10;\n    return x - 1;\n  }\n\n  void norm() {\n    if (sgn == -1 and ssize(val)\
    \ == 1 and val[0] == 0)\n      sgn = 1;\n  }\n\n  bool abs_less(const bigint &b)\
    \ const {\n    if (size(val) != size(b.val))\n      return size(val) < size(b.val);\n\
    \    for(int i = ssize(val) - 1; i >= 0; i--)\n      if (val[i] != b.val[i])\n\
    \        return val[i] < b.val[i];\n    return false;\n  }\n\n  bigint& operator+=(const\
    \ bigint &b) {\n    if (sgn != b.sgn) {\n      *this -= -b;\n    } else if (abs_less(b))\
    \ {\n      *this = b + *this;\n    } else {\n      for(int i = 0; i < min(ssize(val),\
    \ ssize(b.val)); i++) {\n        val[i] += b.val[i];\n        if (int q = val[i]\
    \ / W; q > 0) {\n          if (i + 1 == ssize(val)) val.emplace_back();\n    \
    \      val[i] -= q * W, val[i + 1] += q;\n        }\n      }\n      int j = min(ssize(val),\
    \ ssize(b.val));\n      while(j < ssize(val) and val[j] >= W) {\n        int q\
    \ = val[j] / W;\n        if (j + 1 == ssize(val)) val.emplace_back();\n      \
    \  val[j] -= q * W, val[j + 1] += q, j++;\n      }\n    }\n    norm();\n    return\
    \ *this;\n  }\n\n  bigint& operator-=(const bigint &b) {\n    if (sgn != b.sgn)\
    \ {\n      *this += -b;\n    } else if (abs_less(b)) {\n      *this = b - *this,\
    \ sgn = -sgn;\n    } else {\n      for(int i = 0; i < min(ssize(val), ssize(b.val));\
    \ i++) {\n        val[i] -= b.val[i];\n        if (val[i] < 0)\n          val[i]\
    \ += W, val[i + 1] -= 1;\n      }\n      int j = min(ssize(val), ssize(b.val));\n\
    \      while(j < ssize(val) and val[j] < 0)\n        val[j] += W, val[j + 1] -=\
    \ 1, j++;\n      while(ssize(val) > 1 and val.back() == 0) val.pop_back();\n \
    \   }\n    norm();\n    return *this;\n  }\n\n  bigint& operator*=(const bigint\
    \ &b) {\n    if constexpr (LOG == 1) {\n      static NTT ntt;\n      vector<mint>\
    \ c(size(val)), d(size(b.val));\n      for(int i = 0; i < ssize(c); i++) c[i]\
    \ = val[i];\n      for(int i = 0; i < ssize(d); i++) d[i] = b.val[i];\n      c\
    \ = ntt.conv(c, d);\n      vector<int> tmp(ssize(c));\n      for(int i = 0; i\
    \ < ssize(c); i++)\n        tmp[i] = c[i].get();\n      for(int i = 0; i < ssize(tmp);\
    \ i++) {\n        if (int q = tmp[i] / W; q > 0) {\n          if (i + 1 == ssize(tmp))\
    \ tmp.emplace_back();\n          tmp[i] -= q * W, tmp[i + 1] += q;\n        }\n\
    \      }\n      val.swap(tmp);\n    } else {\n      vector<int> tmp(ssize(val)\
    \ + ssize(b.val) + 1);\n      for(int i = 0; i < ssize(val); i++) {\n        for(int\
    \ j = 0; j < ssize(b.val); j++) {\n          if (int q = tmp[i + j] / W; q > 0)\n\
    \            tmp[i + j] -= q * W, tmp[i + j + 1] += q;\n          ll x = (ll)val[i]\
    \ * b.val[j];\n          tmp[i + j] += x % W, tmp[i + j + 1] += x / W;\n     \
    \     if (int q = tmp[i + j] / W; q > 0)\n            tmp[i + j] -= q * W, tmp[i\
    \ + j + 1] += q;\n        }\n      }\n      val.swap(tmp);\n    }\n    while(ssize(val)\
    \ > 1 and val.back() == 0) val.pop_back();\n    sgn *= b.sgn;\n    norm();\n \
    \   return *this;\n  }\n\n  bool operator<(const bigint &b) const {\n    if (sgn\
    \ != b.sgn) return sgn == -1;\n    else if (sgn == 1) return abs_less(b);\n  \
    \  else return b.abs_less(*this);\n  }\n  bool operator>(const bigint &b) const\
    \ { return b < *this; }\n  bool operator<=(const bigint &b) const { return !(*this\
    \ > b); }\n  bool operator>=(const bigint &b) const { return !(*this < b); }\n\
    \  bool operator==(const bigint &b) const { return sgn == b.sgn and val == b.val;\
    \ }\n  friend bigint operator+(bigint a, bigint b) { return a += b; }\n  friend\
    \ bigint operator-(bigint a, bigint b) { return a -= b; }\n  friend bigint operator*(bigint\
    \ a, bigint b) { return a *= b; }\n\n  bigint operator-() const {\n    bigint\
    \ b = *this;\n    b.sgn = -b.sgn;\n    return b;\n  }\n\n  string to_string()\
    \ const {\n    string s;\n    for(int i = 0; i < ssize(val); i++) {\n      int\
    \ x = val[i];\n      for(int j = 0; j < LOG; j++)\n        s += '0' + (x % 10),\
    \ x /= 10;\n    }\n    while(ssize(s) > 1 and s.back() == '0') s.pop_back();\n\
    \    if (sgn == -1) s += '-';\n    ranges::reverse(s);\n    return s;\n  }\n\n\
    \  friend ostream& operator<<(ostream& os, const bigint& b) {\n    return os <<\
    \ b.to_string();\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/bigint.cpp
  requiredBy: []
  timestamp: '2025-05-31 21:52:56+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/multiplication_of_big_intergers_2.test.cpp
  - test/multiplication_of_big_intergers.test.cpp
  - test/addition_of_big_integers_2.test.cpp
  - test/addition_of_big_integers.test.cpp
documentation_of: misc/bigint.cpp
layout: document
redirect_from:
- /library/misc/bigint.cpp
- /library/misc/bigint.cpp.html
title: misc/bigint.cpp
---
