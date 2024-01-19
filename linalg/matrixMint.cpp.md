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
  bundledCode: "#line 1 \"linalg/matrixMint.cpp\"\n/**\n * template name: matrixMint\n\
    \ * author: Misuki\n * include: mint\n * reference: kactl (for det() and inv())\n\
    \ * last update: 2024/01/17\n * verify: Library Checker - Matrix Product\n * \
    \        Library Checker - Determinant of Matrix\n *         Library Checker -\
    \ Inverse Matrix\n *         Library Checker - Pow of Matrix\n */\n\ntemplate<class\
    \ Mint>\nstruct matrix : vector<vector<Mint>> {\n  matrix(int n, int m) : vector<vector<Mint>>(n,\
    \ vector<Mint>(m, 0)) {}\n  matrix(int n) : vector<vector<Mint>>(n, vector<Mint>(n,\
    \ 0)) {}\n\n  int n() const { return ssize(*this); }\n  int m() const { return\
    \ ssize((*this)[0]); }\n\n  static matrix I(int n) {\n    auto res = matrix(n,\
    \ n);\n    for(int i = 0; i < n; i++)\n      res[i][i] = 1;\n    return res;\n\
    \  }\n\n  matrix& operator+=(const matrix &b) {\n    assert(n() == b.n());\n \
    \   assert(m() == b.m());\n    for(int i = 0; i < n(); i++)\n      for(int j =\
    \ 0; j < m(); j++)\n        (*this)[i][j] += b[i][j];\n    return *this;\n  }\n\
    \n  matrix& operator-=(const matrix &b) {\n    assert(n() == b.n());\n    assert(m()\
    \ == b.m());\n    for(int i = 0; i < n(); i++)\n      for(int j = 0; j < m();\
    \ j++)\n        (*this)[i][j] -= b[i][j];\n    return *this;\n  }\n\n  matrix&\
    \ operator*=(const matrix &b) {\n    assert(m() == b.n());\n    auto res = matrix(n(),\
    \ b.m());\n    for(int i = 0; i < n(); i++)\n      for(int j = 0; j < b.m(); j++)\n\
    \        for(int k = 0; k < m(); k++)\n          res[i][j] += (*this)[i][k] *\
    \ b[k][j];\n    this -> swap(res);\n    return *this;\n  }\n\n  matrix pow(ll\
    \ k) const {\n    assert(n() == m());\n    auto res = I(n()), base = *this;\n\
    \    while(k) {\n      if (k & 1) res *= base;\n      base *= base, k >>= 1;\n\
    \    }\n    return res;\n  }\n\n  Mint det() const {\n    Mint res = 1;\n    auto\
    \ a = *this;\n    for(int i = 0; i < n(); i++) {\n      for(int j = i + 1; j <\
    \ m(); j++) {\n        while(a[j][i] != 0) {\n          Mint t = a[i][i] / a[j][i];\n\
    \          if (t != 0)\n            for(int k = i; k < n(); k++)\n           \
    \   a[i][k] -= a[j][k] * t;\n          swap(a[i], a[j]);\n          res = -res;\n\
    \        }\n      }\n      res *= a[i][i];\n      if (res == 0) return 0;\n  \
    \  }\n    return res;\n  }\n\n  matrix inv() const {\n    assert(n() == m());\n\
    \    matrix a = *this, tmp = I(n());\n    vector<int> col(n());\n    for(int i\
    \ = 0; i < n(); i++) col[i] = i;\n\n    for(int i = 0; i < n(); i++) {\n     \
    \ int r = i, c = i;\n      for(int j = i; j < n(); j++) {\n        for(int k =\
    \ i; k < n(); k++) {\n          if (a[j][k] != 0) {\n            r = j, c = k;\n\
    \            goto found;\n          }\n        }\n      }\n      return matrix(0);\n\
    \      found:\n      a[i].swap(a[r]), tmp[i].swap(tmp[r]);\n      for(int j =\
    \ 0; j < n(); j++)\n        swap(a[j][i], a[j][c]), swap(tmp[j][i], tmp[j][c]);\n\
    \      swap(col[i], col[c]);\n      Mint v = 1 / a[i][i];\n      for(int j = i\
    \ + 1; j < n(); j++) {\n        Mint f = a[j][i] * v;\n        a[j][i] = 0;\n\
    \        for(int k = i + 1; k < n(); k++)\n          a[j][k] -= f * a[i][k];\n\
    \        for(int k = 0; k < n(); k++)\n          tmp[j][k] -= f * tmp[i][k];\n\
    \      }\n      for(int j = i + 1; j < n(); j++) \n        a[i][j] *= v;\n   \
    \   for(int j = 0; j < n(); j++) \n        tmp[i][j] *= v;\n      a[i][i] = 1;\n\
    \    }\n\n    for(int i = n() - 1; i > 0; i--) {\n      for(int j = 0; j < i;\
    \ j++) {\n        Mint v = a[j][i];\n        for(int k = 0; k < n(); k++)\n  \
    \        tmp[j][k] -= v * tmp[i][k];\n      }\n    }\n\n    for(int i = 0; i <\
    \ n(); i++)\n      for(int j = 0; j < n(); j++)\n        a[col[i]][col[j]] = tmp[i][j];\n\
    \    return a;\n  }\n\n  matrix operator-() { return matrix(n(), m()) - (*this);\
    \ }\n  \n  friend matrix operator+(matrix a, matrix b) { return a += b; }\n  friend\
    \ matrix operator-(matrix a, matrix b) { return a -= b; }\n  friend matrix operator*(matrix\
    \ a, matrix b) { return a *= b; }\n  \n  friend ostream& operator<<(ostream& os,\
    \ const matrix& b) {\n    for(int i = 0; i < b.n(); i++) {\n      os << '\\n';\n\
    \      for(int j = 0; j < b.m(); j++)\n        os << b[i][j] << ' ';\n    }\n\
    \    return os;\n  }\n  friend istream& operator>>(istream& is, matrix& b) {\n\
    \    for(int i = 0; i < b.n(); i++)\n      for(int j = 0; j < b.m(); j++)\n  \
    \      is >> b[i][j];\n    return is;\n  }\n};\n"
  code: "/**\n * template name: matrixMint\n * author: Misuki\n * include: mint\n\
    \ * reference: kactl (for det() and inv())\n * last update: 2024/01/17\n * verify:\
    \ Library Checker - Matrix Product\n *         Library Checker - Determinant of\
    \ Matrix\n *         Library Checker - Inverse Matrix\n *         Library Checker\
    \ - Pow of Matrix\n */\n\ntemplate<class Mint>\nstruct matrix : vector<vector<Mint>>\
    \ {\n  matrix(int n, int m) : vector<vector<Mint>>(n, vector<Mint>(m, 0)) {}\n\
    \  matrix(int n) : vector<vector<Mint>>(n, vector<Mint>(n, 0)) {}\n\n  int n()\
    \ const { return ssize(*this); }\n  int m() const { return ssize((*this)[0]);\
    \ }\n\n  static matrix I(int n) {\n    auto res = matrix(n, n);\n    for(int i\
    \ = 0; i < n; i++)\n      res[i][i] = 1;\n    return res;\n  }\n\n  matrix& operator+=(const\
    \ matrix &b) {\n    assert(n() == b.n());\n    assert(m() == b.m());\n    for(int\
    \ i = 0; i < n(); i++)\n      for(int j = 0; j < m(); j++)\n        (*this)[i][j]\
    \ += b[i][j];\n    return *this;\n  }\n\n  matrix& operator-=(const matrix &b)\
    \ {\n    assert(n() == b.n());\n    assert(m() == b.m());\n    for(int i = 0;\
    \ i < n(); i++)\n      for(int j = 0; j < m(); j++)\n        (*this)[i][j] -=\
    \ b[i][j];\n    return *this;\n  }\n\n  matrix& operator*=(const matrix &b) {\n\
    \    assert(m() == b.n());\n    auto res = matrix(n(), b.m());\n    for(int i\
    \ = 0; i < n(); i++)\n      for(int j = 0; j < b.m(); j++)\n        for(int k\
    \ = 0; k < m(); k++)\n          res[i][j] += (*this)[i][k] * b[k][j];\n    this\
    \ -> swap(res);\n    return *this;\n  }\n\n  matrix pow(ll k) const {\n    assert(n()\
    \ == m());\n    auto res = I(n()), base = *this;\n    while(k) {\n      if (k\
    \ & 1) res *= base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\
    \n  Mint det() const {\n    Mint res = 1;\n    auto a = *this;\n    for(int i\
    \ = 0; i < n(); i++) {\n      for(int j = i + 1; j < m(); j++) {\n        while(a[j][i]\
    \ != 0) {\n          Mint t = a[i][i] / a[j][i];\n          if (t != 0)\n    \
    \        for(int k = i; k < n(); k++)\n              a[i][k] -= a[j][k] * t;\n\
    \          swap(a[i], a[j]);\n          res = -res;\n        }\n      }\n    \
    \  res *= a[i][i];\n      if (res == 0) return 0;\n    }\n    return res;\n  }\n\
    \n  matrix inv() const {\n    assert(n() == m());\n    matrix a = *this, tmp =\
    \ I(n());\n    vector<int> col(n());\n    for(int i = 0; i < n(); i++) col[i]\
    \ = i;\n\n    for(int i = 0; i < n(); i++) {\n      int r = i, c = i;\n      for(int\
    \ j = i; j < n(); j++) {\n        for(int k = i; k < n(); k++) {\n          if\
    \ (a[j][k] != 0) {\n            r = j, c = k;\n            goto found;\n     \
    \     }\n        }\n      }\n      return matrix(0);\n      found:\n      a[i].swap(a[r]),\
    \ tmp[i].swap(tmp[r]);\n      for(int j = 0; j < n(); j++)\n        swap(a[j][i],\
    \ a[j][c]), swap(tmp[j][i], tmp[j][c]);\n      swap(col[i], col[c]);\n      Mint\
    \ v = 1 / a[i][i];\n      for(int j = i + 1; j < n(); j++) {\n        Mint f =\
    \ a[j][i] * v;\n        a[j][i] = 0;\n        for(int k = i + 1; k < n(); k++)\n\
    \          a[j][k] -= f * a[i][k];\n        for(int k = 0; k < n(); k++)\n   \
    \       tmp[j][k] -= f * tmp[i][k];\n      }\n      for(int j = i + 1; j < n();\
    \ j++) \n        a[i][j] *= v;\n      for(int j = 0; j < n(); j++) \n        tmp[i][j]\
    \ *= v;\n      a[i][i] = 1;\n    }\n\n    for(int i = n() - 1; i > 0; i--) {\n\
    \      for(int j = 0; j < i; j++) {\n        Mint v = a[j][i];\n        for(int\
    \ k = 0; k < n(); k++)\n          tmp[j][k] -= v * tmp[i][k];\n      }\n    }\n\
    \n    for(int i = 0; i < n(); i++)\n      for(int j = 0; j < n(); j++)\n     \
    \   a[col[i]][col[j]] = tmp[i][j];\n    return a;\n  }\n\n  matrix operator-()\
    \ { return matrix(n(), m()) - (*this); }\n  \n  friend matrix operator+(matrix\
    \ a, matrix b) { return a += b; }\n  friend matrix operator-(matrix a, matrix\
    \ b) { return a -= b; }\n  friend matrix operator*(matrix a, matrix b) { return\
    \ a *= b; }\n  \n  friend ostream& operator<<(ostream& os, const matrix& b) {\n\
    \    for(int i = 0; i < b.n(); i++) {\n      os << '\\n';\n      for(int j = 0;\
    \ j < b.m(); j++)\n        os << b[i][j] << ' ';\n    }\n    return os;\n  }\n\
    \  friend istream& operator>>(istream& is, matrix& b) {\n    for(int i = 0; i\
    \ < b.n(); i++)\n      for(int j = 0; j < b.m(); j++)\n        is >> b[i][j];\n\
    \    return is;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/matrixMint.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/matrixMint.cpp
layout: document
redirect_from:
- /library/linalg/matrixMint.cpp
- /library/linalg/matrixMint.cpp.html
title: linalg/matrixMint.cpp
---
