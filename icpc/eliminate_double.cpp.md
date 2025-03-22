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
  bundledCode: "#line 1 \"icpc/eliminate_double.cpp\"\n//source: KACTL\n\ndouble det(vector<vector<double>>&\
    \ a) {\n\tint n = sz(a); double res = 1;\n\trep(i,0,n) {\n\t\tint b = i;\n\t\t\
    rep(j,i+1,n) if (fabs(a[j][i]) > fabs(a[b][i])) b = j;\n\t\tif (i != b) swap(a[i],\
    \ a[b]), res *= -1;\n\t\tres *= a[i][i];\n\t\tif (res == 0) return 0;\n\t\trep(j,i+1,n)\
    \ {\n\t\t\tdouble v = a[j][i] / a[i][i];\n\t\t\tif (v != 0) rep(k,i+1,n) a[j][k]\
    \ -= v * a[i][k];\n\t\t}\n\t}\n\treturn res;\n}\nk\nint matInv(vector<vector<double>>&\
    \ A) {\n\tint n = sz(A); vi col(n);\n\tvector<vector<double>> tmp(n, vector<double>(n));\n\
    \trep(i,0,n) tmp[i][i] = 1, col[i] = i;\n\n\trep(i,0,n) {\n\t\tint r = i, c =\
    \ i;\n\t\trep(j,i,n) rep(k,i,n)\n\t\t\tif (fabs(A[j][k]) > fabs(A[r][c]))\n\t\t\
    \t\tr = j, c = k;\n\t\tif (fabs(A[r][c]) < 1e-12) return i;\n\t\tA[i].swap(A[r]);\
    \ tmp[i].swap(tmp[r]);\n\t\trep(j,0,n)\n\t\t\tswap(A[j][i], A[j][c]), swap(tmp[j][i],\
    \ tmp[j][c]);\n\t\tswap(col[i], col[c]);\n\t\tdouble v = A[i][i];\n\t\trep(j,i+1,n)\
    \ {\n\t\t\tdouble f = A[j][i] / v;\n\t\t\tA[j][i] = 0;\n\t\t\trep(k,i+1,n) A[j][k]\
    \ -= f*A[i][k];\n\t\t\trep(k,0,n) tmp[j][k] -= f*tmp[i][k];\n\t\t}\n\t\trep(j,i+1,n)\
    \ A[i][j] /= v;\n\t\trep(j,0,n) tmp[i][j] /= v;\n\t\tA[i][i] = 1;\n\t}\n\n\t///\
    \ forget A at this point, just eliminate tmp backward\n\tfor (int i = n-1; i >\
    \ 0; --i) rep(j,0,i) {\n\t\tdouble v = A[j][i];\n\t\trep(k,0,n) tmp[j][k] -= v*tmp[i][k];\n\
    \t}\n\n\trep(i,0,n) rep(j,0,n) A[col[i]][col[j]] = tmp[i][j];\n\treturn n; //rank\n\
    }\n\ntypedef vector<double> vd;\nconst double eps = 1e-12;\n\n//Solves $A * x\
    \ = b$. If there are multiple solutions, an arbitrary one is returned.\n//Returns\
    \ rank, or -1 if no solutions. Data in $A$ and $b$ is lost.\nint solveLinear(vector<vd>&\
    \ A, vd& b, vd& x) {\n\tint n = sz(A), m = sz(x), rank = 0, br, bc;\n\tif (n)\
    \ assert(sz(A[0]) == m);\n\tvi col(m); iota(all(col), 0);\n\n\trep(i,0,n) {\n\t\
    \tdouble v, bv = 0;\n\t\trep(r,i,n) rep(c,i,m)\n\t\t\tif ((v = fabs(A[r][c]))\
    \ > bv)\n\t\t\t\tbr = r, bc = c, bv = v;\n\t\tif (bv <= eps) {\n\t\t\trep(j,i,n)\
    \ if (fabs(b[j]) > eps) return -1;\n\t\t\tbreak;\n\t\t}\n\t\tswap(A[i], A[br]);\n\
    \t\tswap(b[i], b[br]);\n\t\tswap(col[i], col[bc]);\n\t\trep(j,0,n) swap(A[j][i],\
    \ A[j][bc]);\n\t\tbv = 1/A[i][i];\n\t\trep(j,i+1,n) {\n\t\t\tdouble fac = A[j][i]\
    \ * bv;\n\t\t\tb[j] -= fac * b[i];\n\t\t\trep(k,i+1,m) A[j][k] -= fac*A[i][k];\n\
    \t\t}\n\t\trank++;\n\t}\n\n\tx.assign(m, 0);\n\tfor (int i = rank; i--;) {\n\t\
    \tb[i] /= A[i][i];\n\t\tx[col[i]] = b[i];\n\t\trep(j,0,i) b[j] -= A[j][i] * b[i];\n\
    \t}\n\treturn rank; // (multiple solutions if rank < m)\n}\n"
  code: "//source: KACTL\n\ndouble det(vector<vector<double>>& a) {\n\tint n = sz(a);\
    \ double res = 1;\n\trep(i,0,n) {\n\t\tint b = i;\n\t\trep(j,i+1,n) if (fabs(a[j][i])\
    \ > fabs(a[b][i])) b = j;\n\t\tif (i != b) swap(a[i], a[b]), res *= -1;\n\t\t\
    res *= a[i][i];\n\t\tif (res == 0) return 0;\n\t\trep(j,i+1,n) {\n\t\t\tdouble\
    \ v = a[j][i] / a[i][i];\n\t\t\tif (v != 0) rep(k,i+1,n) a[j][k] -= v * a[i][k];\n\
    \t\t}\n\t}\n\treturn res;\n}\nk\nint matInv(vector<vector<double>>& A) {\n\tint\
    \ n = sz(A); vi col(n);\n\tvector<vector<double>> tmp(n, vector<double>(n));\n\
    \trep(i,0,n) tmp[i][i] = 1, col[i] = i;\n\n\trep(i,0,n) {\n\t\tint r = i, c =\
    \ i;\n\t\trep(j,i,n) rep(k,i,n)\n\t\t\tif (fabs(A[j][k]) > fabs(A[r][c]))\n\t\t\
    \t\tr = j, c = k;\n\t\tif (fabs(A[r][c]) < 1e-12) return i;\n\t\tA[i].swap(A[r]);\
    \ tmp[i].swap(tmp[r]);\n\t\trep(j,0,n)\n\t\t\tswap(A[j][i], A[j][c]), swap(tmp[j][i],\
    \ tmp[j][c]);\n\t\tswap(col[i], col[c]);\n\t\tdouble v = A[i][i];\n\t\trep(j,i+1,n)\
    \ {\n\t\t\tdouble f = A[j][i] / v;\n\t\t\tA[j][i] = 0;\n\t\t\trep(k,i+1,n) A[j][k]\
    \ -= f*A[i][k];\n\t\t\trep(k,0,n) tmp[j][k] -= f*tmp[i][k];\n\t\t}\n\t\trep(j,i+1,n)\
    \ A[i][j] /= v;\n\t\trep(j,0,n) tmp[i][j] /= v;\n\t\tA[i][i] = 1;\n\t}\n\n\t///\
    \ forget A at this point, just eliminate tmp backward\n\tfor (int i = n-1; i >\
    \ 0; --i) rep(j,0,i) {\n\t\tdouble v = A[j][i];\n\t\trep(k,0,n) tmp[j][k] -= v*tmp[i][k];\n\
    \t}\n\n\trep(i,0,n) rep(j,0,n) A[col[i]][col[j]] = tmp[i][j];\n\treturn n; //rank\n\
    }\n\ntypedef vector<double> vd;\nconst double eps = 1e-12;\n\n//Solves $A * x\
    \ = b$. If there are multiple solutions, an arbitrary one is returned.\n//Returns\
    \ rank, or -1 if no solutions. Data in $A$ and $b$ is lost.\nint solveLinear(vector<vd>&\
    \ A, vd& b, vd& x) {\n\tint n = sz(A), m = sz(x), rank = 0, br, bc;\n\tif (n)\
    \ assert(sz(A[0]) == m);\n\tvi col(m); iota(all(col), 0);\n\n\trep(i,0,n) {\n\t\
    \tdouble v, bv = 0;\n\t\trep(r,i,n) rep(c,i,m)\n\t\t\tif ((v = fabs(A[r][c]))\
    \ > bv)\n\t\t\t\tbr = r, bc = c, bv = v;\n\t\tif (bv <= eps) {\n\t\t\trep(j,i,n)\
    \ if (fabs(b[j]) > eps) return -1;\n\t\t\tbreak;\n\t\t}\n\t\tswap(A[i], A[br]);\n\
    \t\tswap(b[i], b[br]);\n\t\tswap(col[i], col[bc]);\n\t\trep(j,0,n) swap(A[j][i],\
    \ A[j][bc]);\n\t\tbv = 1/A[i][i];\n\t\trep(j,i+1,n) {\n\t\t\tdouble fac = A[j][i]\
    \ * bv;\n\t\t\tb[j] -= fac * b[i];\n\t\t\trep(k,i+1,m) A[j][k] -= fac*A[i][k];\n\
    \t\t}\n\t\trank++;\n\t}\n\n\tx.assign(m, 0);\n\tfor (int i = rank; i--;) {\n\t\
    \tb[i] /= A[i][i];\n\t\tx[col[i]] = b[i];\n\t\trep(j,0,i) b[j] -= A[j][i] * b[i];\n\
    \t}\n\treturn rank; // (multiple solutions if rank < m)\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/eliminate_double.cpp
  requiredBy: []
  timestamp: '2025-03-22 15:11:28+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/eliminate_double.cpp
layout: document
redirect_from:
- /library/icpc/eliminate_double.cpp
- /library/icpc/eliminate_double.cpp.html
title: icpc/eliminate_double.cpp
---
