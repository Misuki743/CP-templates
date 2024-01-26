---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/fastFactorize.cpp
    title: numtheory/fastFactorize.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bit>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n\
    #include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n\
    #include <cmath>\n#include <compare>\n#include <complex>\n#include <concepts>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numbers>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ranges>\n#include <set>\n#include <span>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"numtheory/fastFactorize.cpp\"\
    \n//source: KACTL(https://github.com/kth-competitive-programming/kactl)\n\null\
    \ modmul(ull a, ull b, ull M) {\n\tll ret = a * b - M * ull(1.L / M * a * b);\n\
    \treturn ret + M * (ret < 0) - M * (ret >= (ll)M);\n}\n\null modpow(ull b, ull\
    \ e, ull mod) {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /= 2)\n\t\
    \tif (e & 1) ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull\
    \ n) {\n\tif (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\tull A[] = {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022},\n\t    s = __builtin_ctzll(n-1),\
    \ d = n >> s;\n\tfor (ull a : A) {   // ^ count trailing zeroes\n\t\tull p = modpow(a%n,\
    \ d, n), i = s;\n\t\twhile (p != 1 && p != n - 1 && a % n && i--)\n\t\t\tp = modmul(p,\
    \ p, n);\n\t\tif (p != n-1 && i != s) return 0;\n\t}\n\treturn 1;\n}\n\null pollard(ull\
    \ n) {\n  static mt19937_64 rng(clock);\n  uniform_int_distribution<ull> unif(0,\
    \ n - 1);\n  ull c = 1;\n\tauto f = [n, &c](ull x) { return modmul(x, x, n) +\
    \ c % n; };\n\tull x = 0, y = 0, t = 30, prd = 2, i = 1, q;\n\twhile (t++ % 40\
    \ || __gcd(prd, n) == 1) {\n\t\tif (x == y) c = unif(rng), x = ++i, y = f(x);\n\
    \t\tif ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;\n\t\tx = f(x), y =\
    \ f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\n\nvector<ull> factor(ull n) {\n\t\
    if (n == 1) return {};\n\tif (isPrime(n)) return {n};\n\tull x = pollard(n);\n\
    \tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(), r.begin(), r.end());\n\
    \treturn l;\n}\n#line 5 \"test/factorize.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int q; cin >> q;\n  while(q--) {\n    ull x; cin >> x;\n\
    \    auto ans = factor(x);\n    R::sort(ans);\n    cout << ssize(ans) << ' ' <<\
    \ ans << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../numtheory/fastFactorize.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int q; cin >> q;\n\
    \  while(q--) {\n    ull x; cin >> x;\n    auto ans = factor(x);\n    R::sort(ans);\n\
    \    cout << ssize(ans) << ' ' << ans << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - numtheory/fastFactorize.cpp
  isVerificationFile: true
  path: test/factorize.test.cpp
  requiredBy: []
  timestamp: '2024-01-23 02:14:10+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/factorize.test.cpp
- /verify/test/factorize.test.cpp.html
title: test/factorize.test.cpp
---
