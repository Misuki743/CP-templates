---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/counting_eulerian_circuits.test.cpp
    title: test/counting_eulerian_circuits.test.cpp
  - icon: ':x:'
    path: test/counting_spanning_tree_directed.test.cpp
    title: test/counting_spanning_tree_directed.test.cpp
  - icon: ':x:'
    path: test/counting_spanning_tree_undirected.test.cpp
    title: test/counting_spanning_tree_undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/determinant_of_matrix.test.cpp
    title: test/determinant_of_matrix.test.cpp
  - icon: ':x:'
    path: test/inverse_matrix.test.cpp
    title: test/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix_product.test.cpp
    title: test/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix_rank.test.cpp
    title: test/matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_matrix.test.cpp
    title: test/pow_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/system_of_linear_equations.test.cpp
    title: test/system_of_linear_equations.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/matrixMint.cpp\"\ntemplate<class Mint>\nstruct matrix\
    \ : vector<vector<Mint>> {\n  matrix(int n, int m) : vector<vector<Mint>>(n, vector<Mint>(m,\
    \ 0)) {}\n  matrix(int n) : vector<vector<Mint>>(n, vector<Mint>(n, 0)) {}\n\n\
    \  int n() const { return ssize(*this); }\n  int m() const { return ssize((*this)[0]);\
    \ }\n\n  static matrix I(int n) {\n    auto res = matrix(n, n);\n    for(int i\
    \ = 0; i < n; i++)\n      res[i][i] = 1;\n    return res;\n  }\n\n  matrix& operator+=(const\
    \ matrix &b) {\n    assert(n() == b.n());\n    assert(m() == b.m());\n    for(int\
    \ i = 0; i < n(); i++)\n      for(int j = 0; j < m(); j++)\n        (*this)[i][j]\
    \ += b[i][j];\n    return *this;\n  }\n\n  matrix& operator-=(const matrix &b)\
    \ {\n    assert(n() == b.n());\n    assert(m() == b.m());\n    for(int i = 0;\
    \ i < n(); i++)\n      for(int j = 0; j < m(); j++)\n        (*this)[i][j] -=\
    \ b[i][j];\n    return *this;\n  }\n\n  matrix& operator*=(const matrix &b) {\n\
    \    assert(m() == b.n());\n    auto res = matrix(n(), b.m());\n    for(int i\
    \ = 0; i < n(); i++)\n      for(int k = 0; k < m(); k++)\n        for(int j =\
    \ 0; j < b.m(); j++)\n          res[i][j] += (*this)[i][k] * b[k][j];\n    this\
    \ -> swap(res);\n    return *this;\n  }\n\n  matrix pow(ll k) const {\n    assert(n()\
    \ == m());\n    auto res = I(n()), base = *this;\n    while(k) {\n      if (k\
    \ & 1) res *= base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\
    \n  tuple<matrix, vector<int>, int> eliminate() {\n    int sgn = 1;\n    matrix\
    \ M = *this;\n    vector<int> pivot_row;\n    for(int row = 0, col = 0; row <\
    \ n() and col < m(); col++) {\n      int p_row = -1;\n      for(int i = row; i\
    \ < n() and p_row == -1; i++)\n        if (M[i][col] != 0) \n          p_row =\
    \ i;\n      if (p_row == -1) continue;\n      pivot_row.emplace_back(row);\n \
    \     if (row != p_row) {\n        for(int j = col; j < m(); j++)\n          swap(M[row][j],\
    \ M[p_row][j]);\n        sgn *= -1;\n      }\n      for(int i = 0; i < n(); i++)\
    \ {\n        if (i == row or M[i][col] == 0) continue;\n        Mint s = M[i][col]\
    \ / M[row][col];\n        for(int j = col; j < m(); j++)\n          M[i][j] -=\
    \ M[row][j] * s;\n      }\n      row++;\n    }\n    return {M, pivot_row, sgn};\n\
    \  }\n\n  Mint det() {\n    assert(n() == m());\n    auto [M, pr, sgn] = eliminate();\n\
    \    if (ssize(pr) != n()) {\n      return Mint(0);\n    } else {\n      Mint\
    \ d = sgn;\n      for(int i = 0; i < n(); i++)\n        d *= M[i][i];\n      return\
    \ d;\n    }\n  }\n\n  int rank() {\n    return get<1>(eliminate()).size();\n \
    \ }\n\n  pair<bool, matrix> inv() {\n    assert(n() == m());\n    matrix M(n(),\
    \ 2 * n());\n    for(int i = 0; i < n(); i++) {\n      for(int j = 0; j < n();\
    \ j++)\n        M[i][j] = (*this)[i][j];\n      M[i][n() + i] = 1;\n    }\n  \
    \  matrix tmp = get<0>(M.eliminate());\n    matrix MI(n(), n());\n    for(int\
    \ i = 0; i < n(); i++) {\n      if (tmp[i][i] == 0) return {false, matrix(0, 0)};\n\
    \      Mint r = tmp[i][i].inverse();\n      for(int j = 0; j < n(); j++)\n   \
    \     MI[i][j] = tmp[i][j + n()] * r;\n    }\n    return {true, MI};\n  }\n\n\
    \  pair<vector<Mint>, matrix> solve_linear(vector<Mint> b) {\n    assert(n() ==\
    \ ssize(b));\n\n    matrix M(n(), m() + 1);\n    for(int i = 0; i < n(); i++)\
    \ {\n      for(int j = 0; j < m(); j++)\n        M[i][j] = (*this)[i][j];\n  \
    \    M[i][m()] = b[i];\n    }\n\n    auto [N, pr, _] = M.eliminate();\n    vector<Mint>\
    \ x(m());\n    vector<int> where(m(), -1), inv_where(m(), -1);\n    for(int row\
    \ : pr) {\n      int col = 0;\n      while(N[row][col] == 0) col++;\n      if\
    \ (col < m())\n        where[col] = row, inv_where[row] = col;\n    }\n\n    for(int\
    \ i = 0; i < m(); i++)\n      if (where[i] != -1)\n        x[i] = N[where[i]][m()]\
    \ / N[where[i]][i];\n\n    for(int i = 0; i < n(); i++) {\n      Mint s = -N[i][m()];\n\
    \      for(int j = 0; j < m(); j++)\n        s += x[j] * N[i][j];\n      if (s\
    \ != Mint(0))\n        return {vector<Mint>(), matrix(0)};\n    }\n\n    matrix\
    \ basis(m() - ssize(pr), m());\n    for(int col = 0, last_row = 0, k = 0; col\
    \ < m(); col++) {\n      if (where[col] != -1) {\n        last_row = where[col];\n\
    \      } else {\n        basis[k][col] = 1;\n        for(int i = 0; i <= last_row;\
    \ i++)\n          basis[k][inv_where[i]] = -N[i][col] / N[i][inv_where[i]];\n\
    \        k++;\n      }\n    }\n\n    return {x, basis};\n  }\n\n  matrix operator-()\
    \ { return matrix(n(), m()) - (*this); }\n  \n  friend matrix operator+(matrix\
    \ a, matrix b) { return a += b; }\n  friend matrix operator-(matrix a, matrix\
    \ b) { return a -= b; }\n  friend matrix operator*(matrix a, matrix b) { return\
    \ a *= b; }\n  \n  friend ostream& operator<<(ostream& os, const matrix& b) {\n\
    \    for(int i = 0; i < b.n(); i++) {\n      os << '\\n';\n      for(int j = 0;\
    \ j < b.m(); j++)\n        os << b[i][j] << ' ';\n    }\n    return os;\n  }\n\
    \  friend istream& operator>>(istream& is, matrix& b) {\n    for(int i = 0; i\
    \ < b.n(); i++)\n      for(int j = 0; j < b.m(); j++)\n        is >> b[i][j];\n\
    \    return is;\n  }\n};\n"
  code: "template<class Mint>\nstruct matrix : vector<vector<Mint>> {\n  matrix(int\
    \ n, int m) : vector<vector<Mint>>(n, vector<Mint>(m, 0)) {}\n  matrix(int n)\
    \ : vector<vector<Mint>>(n, vector<Mint>(n, 0)) {}\n\n  int n() const { return\
    \ ssize(*this); }\n  int m() const { return ssize((*this)[0]); }\n\n  static matrix\
    \ I(int n) {\n    auto res = matrix(n, n);\n    for(int i = 0; i < n; i++)\n \
    \     res[i][i] = 1;\n    return res;\n  }\n\n  matrix& operator+=(const matrix\
    \ &b) {\n    assert(n() == b.n());\n    assert(m() == b.m());\n    for(int i =\
    \ 0; i < n(); i++)\n      for(int j = 0; j < m(); j++)\n        (*this)[i][j]\
    \ += b[i][j];\n    return *this;\n  }\n\n  matrix& operator-=(const matrix &b)\
    \ {\n    assert(n() == b.n());\n    assert(m() == b.m());\n    for(int i = 0;\
    \ i < n(); i++)\n      for(int j = 0; j < m(); j++)\n        (*this)[i][j] -=\
    \ b[i][j];\n    return *this;\n  }\n\n  matrix& operator*=(const matrix &b) {\n\
    \    assert(m() == b.n());\n    auto res = matrix(n(), b.m());\n    for(int i\
    \ = 0; i < n(); i++)\n      for(int k = 0; k < m(); k++)\n        for(int j =\
    \ 0; j < b.m(); j++)\n          res[i][j] += (*this)[i][k] * b[k][j];\n    this\
    \ -> swap(res);\n    return *this;\n  }\n\n  matrix pow(ll k) const {\n    assert(n()\
    \ == m());\n    auto res = I(n()), base = *this;\n    while(k) {\n      if (k\
    \ & 1) res *= base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\
    \n  tuple<matrix, vector<int>, int> eliminate() {\n    int sgn = 1;\n    matrix\
    \ M = *this;\n    vector<int> pivot_row;\n    for(int row = 0, col = 0; row <\
    \ n() and col < m(); col++) {\n      int p_row = -1;\n      for(int i = row; i\
    \ < n() and p_row == -1; i++)\n        if (M[i][col] != 0) \n          p_row =\
    \ i;\n      if (p_row == -1) continue;\n      pivot_row.emplace_back(row);\n \
    \     if (row != p_row) {\n        for(int j = col; j < m(); j++)\n          swap(M[row][j],\
    \ M[p_row][j]);\n        sgn *= -1;\n      }\n      for(int i = 0; i < n(); i++)\
    \ {\n        if (i == row or M[i][col] == 0) continue;\n        Mint s = M[i][col]\
    \ / M[row][col];\n        for(int j = col; j < m(); j++)\n          M[i][j] -=\
    \ M[row][j] * s;\n      }\n      row++;\n    }\n    return {M, pivot_row, sgn};\n\
    \  }\n\n  Mint det() {\n    assert(n() == m());\n    auto [M, pr, sgn] = eliminate();\n\
    \    if (ssize(pr) != n()) {\n      return Mint(0);\n    } else {\n      Mint\
    \ d = sgn;\n      for(int i = 0; i < n(); i++)\n        d *= M[i][i];\n      return\
    \ d;\n    }\n  }\n\n  int rank() {\n    return get<1>(eliminate()).size();\n \
    \ }\n\n  pair<bool, matrix> inv() {\n    assert(n() == m());\n    matrix M(n(),\
    \ 2 * n());\n    for(int i = 0; i < n(); i++) {\n      for(int j = 0; j < n();\
    \ j++)\n        M[i][j] = (*this)[i][j];\n      M[i][n() + i] = 1;\n    }\n  \
    \  matrix tmp = get<0>(M.eliminate());\n    matrix MI(n(), n());\n    for(int\
    \ i = 0; i < n(); i++) {\n      if (tmp[i][i] == 0) return {false, matrix(0, 0)};\n\
    \      Mint r = tmp[i][i].inverse();\n      for(int j = 0; j < n(); j++)\n   \
    \     MI[i][j] = tmp[i][j + n()] * r;\n    }\n    return {true, MI};\n  }\n\n\
    \  pair<vector<Mint>, matrix> solve_linear(vector<Mint> b) {\n    assert(n() ==\
    \ ssize(b));\n\n    matrix M(n(), m() + 1);\n    for(int i = 0; i < n(); i++)\
    \ {\n      for(int j = 0; j < m(); j++)\n        M[i][j] = (*this)[i][j];\n  \
    \    M[i][m()] = b[i];\n    }\n\n    auto [N, pr, _] = M.eliminate();\n    vector<Mint>\
    \ x(m());\n    vector<int> where(m(), -1), inv_where(m(), -1);\n    for(int row\
    \ : pr) {\n      int col = 0;\n      while(N[row][col] == 0) col++;\n      if\
    \ (col < m())\n        where[col] = row, inv_where[row] = col;\n    }\n\n    for(int\
    \ i = 0; i < m(); i++)\n      if (where[i] != -1)\n        x[i] = N[where[i]][m()]\
    \ / N[where[i]][i];\n\n    for(int i = 0; i < n(); i++) {\n      Mint s = -N[i][m()];\n\
    \      for(int j = 0; j < m(); j++)\n        s += x[j] * N[i][j];\n      if (s\
    \ != Mint(0))\n        return {vector<Mint>(), matrix(0)};\n    }\n\n    matrix\
    \ basis(m() - ssize(pr), m());\n    for(int col = 0, last_row = 0, k = 0; col\
    \ < m(); col++) {\n      if (where[col] != -1) {\n        last_row = where[col];\n\
    \      } else {\n        basis[k][col] = 1;\n        for(int i = 0; i <= last_row;\
    \ i++)\n          basis[k][inv_where[i]] = -N[i][col] / N[i][inv_where[i]];\n\
    \        k++;\n      }\n    }\n\n    return {x, basis};\n  }\n\n  matrix operator-()\
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
  timestamp: '2025-03-10 03:52:29+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/determinant_of_matrix.test.cpp
  - test/matrix_product.test.cpp
  - test/counting_spanning_tree_directed.test.cpp
  - test/system_of_linear_equations.test.cpp
  - test/matrix_rank.test.cpp
  - test/inverse_matrix.test.cpp
  - test/pow_of_matrix.test.cpp
  - test/counting_spanning_tree_undirected.test.cpp
  - test/counting_eulerian_circuits.test.cpp
documentation_of: linalg/matrixMint.cpp
layout: document
redirect_from:
- /library/linalg/matrixMint.cpp
- /library/linalg/matrixMint.cpp.html
title: linalg/matrixMint.cpp
---
