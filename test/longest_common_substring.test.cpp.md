---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: string/longestCommonSubstring.cpp
    title: string/longestCommonSubstring.cpp
  - icon: ':heavy_check_mark:'
    path: string/suffixArray.cpp
    title: string/suffixArray.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_common_substring
    links:
    - https://judge.yosupo.jp/problem/longest_common_substring
  bundledCode: "#line 1 \"test/longest_common_substring.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/longest_common_substring\"\n\n#line 1 \"default/t.cpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <compare>\n#include <complex>\n#include <concepts>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numbers>\n#include\
    \ <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n#include\
    \ <ranges>\n#include <set>\n#include <span>\n#include <sstream>\n#include <stack>\n\
    #include <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <variant>\n\n#define INT128_MAX (__int128)(((unsigned __int128) 1 <<\
    \ ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX\
    \ - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>, class\
    \ OP = plus<T>>\nvoid pSum(rng &&v) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>, class OP>\nvoid pSum(rng &&v, OP\
    \ op) {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n \
    \     x = p = op(p, x);\n}\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b\
    \ < 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const pair<T, T> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\n\
    template<class T, size_t N>\nostream& operator<<(ostream& os, const array<T, N>\
    \ &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const vector<T> &vec) {\n  for(const T\
    \ &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(const T &x : s)\n    os <<\
    \ x << ' ';\n  return os;\n}\n#line 1 \"string/suffixArray.cpp\"\n//source: AtCoderLibrary(ACL)\n\
    // usage: suffix_array(vector<> s)\n//        lcp_array(vector<> s, vector<int>\
    \ sa)\n\nstd::vector<int> sa_naive(const std::vector<int>& s) {\n    int n = int(s.size());\n\
    \    std::vector<int> sa(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    std::sort(sa.begin(),\
    \ sa.end(), [&](int l, int r) {\n        if (l == r) return false;\n        while\
    \ (l < n && r < n) {\n            if (s[l] != s[r]) return s[l] < s[r];\n    \
    \        l++;\n            r++;\n        }\n        return l == n;\n    });\n\
    \    return sa;\n}\n\nstd::vector<int> sa_doubling(const std::vector<int>& s)\
    \ {\n    int n = int(s.size());\n    std::vector<int> sa(n), rnk = s, tmp(n);\n\
    \    std::iota(sa.begin(), sa.end(), 0);\n    for (int k = 1; k < n; k *= 2) {\n\
    \        auto cmp = [&](int x, int y) {\n            if (rnk[x] != rnk[y]) return\
    \ rnk[x] < rnk[y];\n            int rx = x + k < n ? rnk[x + k] : -1;\n      \
    \      int ry = y + k < n ? rnk[y + k] : -1;\n            return rx < ry;\n  \
    \      };\n        std::sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]] =\
    \ 0;\n        for (int i = 1; i < n; i++) {\n            tmp[sa[i]] = tmp[sa[i\
    \ - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        std::swap(tmp,\
    \ rnk);\n    }\n    return sa;\n}\n\n// SA-IS, linear-time suffix array construction\n\
    // Reference:\n// G. Nong, S. Zhang, and W. H. Chan,\n// Two Efficient Algorithms\
    \ for Linear Time Suffix Array Construction\ntemplate <int THRESHOLD_NAIVE = 10,\
    \ int THRESHOLD_DOUBLING = 40>\nstd::vector<int> sa_is(const std::vector<int>&\
    \ s, int upper) {\n    int n = int(s.size());\n    if (n == 0) return {};\n  \
    \  if (n == 1) return {0};\n    if (n == 2) {\n        if (s[0] < s[1]) {\n  \
    \          return {0, 1};\n        } else {\n            return {1, 0};\n    \
    \    }\n    }\n    if (n < THRESHOLD_NAIVE) {\n        return sa_naive(s);\n \
    \   }\n    if (n < THRESHOLD_DOUBLING) {\n        return sa_doubling(s);\n   \
    \ }\n\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int\
    \ i = n - 2; i >= 0; i--) {\n        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] :\
    \ (s[i] < s[i + 1]);\n    }\n    std::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n    for (int i = 0; i < n; i++) {\n        if (!ls[i]) {\n          \
    \  sum_s[s[i]]++;\n        } else {\n            sum_l[s[i] + 1]++;\n        }\n\
    \    }\n    for (int i = 0; i <= upper; i++) {\n        sum_s[i] += sum_l[i];\n\
    \        if (i < upper) sum_l[i + 1] += sum_s[i];\n    }\n\n    auto induce =\
    \ [&](const std::vector<int>& lms) {\n        std::fill(sa.begin(), sa.end(),\
    \ -1);\n        std::vector<int> buf(upper + 1);\n        std::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n        for (auto d : lms) {\n            if (d\
    \ == n) continue;\n            sa[buf[s[d]]++] = d;\n        }\n        std::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for\
    \ (int i = 0; i < n; i++) {\n            int v = sa[i];\n            if (v >=\
    \ 1 && !ls[v - 1]) {\n                sa[buf[s[v - 1]]++] = v - 1;\n         \
    \   }\n        }\n        std::copy(sum_l.begin(), sum_l.end(), buf.begin());\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int v = sa[i];\n    \
    \        if (v >= 1 && ls[v - 1]) {\n                sa[--buf[s[v - 1] + 1]] =\
    \ v - 1;\n            }\n        }\n    };\n\n    std::vector<int> lms_map(n +\
    \ 1, -1);\n    int m = 0;\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms_map[i] = m++;\n        }\n    }\n    std::vector<int>\
    \ lms;\n    lms.reserve(m);\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms.push_back(i);\n        }\n    }\n\n    induce(lms);\n\
    \n    if (m) {\n        std::vector<int> sorted_lms;\n        sorted_lms.reserve(m);\n\
    \        for (int v : sa) {\n            if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \        }\n        std::vector<int> rec_s(m);\n        int rec_upper = 0;\n \
    \       rec_s[lms_map[sorted_lms[0]]] = 0;\n        for (int i = 1; i < m; i++)\
    \ {\n            int l = sorted_lms[i - 1], r = sorted_lms[i];\n            int\
    \ end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n            int end_r\
    \ = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n            bool same = true;\n\
    \            if (end_l - l != end_r - r) {\n                same = false;\n  \
    \          } else {\n                while (l < end_l) {\n                   \
    \ if (s[l] != s[r]) {\n                        break;\n                    }\n\
    \                    l++;\n                    r++;\n                }\n     \
    \           if (l == n || s[l] != s[r]) same = false;\n            }\n       \
    \     if (!same) rec_upper++;\n            rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n\
    \        }\n\n        auto rec_sa =\n            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n\n        for (int i = 0; i < m; i++) {\n            sorted_lms[i]\
    \ = lms[rec_sa[i]];\n        }\n        induce(sorted_lms);\n    }\n    return\
    \ sa;\n}\n\nstd::vector<int> suffix_array(const std::vector<int>& s, int upper)\
    \ {\n    assert(0 <= upper);\n    for (int d : s) {\n        assert(0 <= d &&\
    \ d <= upper);\n    }\n    auto sa = sa_is(s, upper);\n    return sa;\n}\n\ntemplate\
    \ <class T> std::vector<int> suffix_array(const std::vector<T>& s) {\n    int\
    \ n = int(s.size());\n    std::vector<int> idx(n);\n    iota(idx.begin(), idx.end(),\
    \ 0);\n    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r];\
    \ });\n    std::vector<int> s2(n);\n    int now = 0;\n    for (int i = 0; i <\
    \ n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]]) now++;\n        s2[idx[i]]\
    \ = now;\n    }\n    return sa_is(s2, now);\n}\n\nstd::vector<int> suffix_array(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return sa_is(s2,\
    \ 255);\n}\n\n// Reference:\n// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and\
    \ K. Park,\n// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays\
    \ and Its\n// Applications\ntemplate <class T>\nstd::vector<int> lcp_array(const\
    \ std::vector<T>& s,\n                           const std::vector<int>& sa) {\n\
    \    int n = int(s.size());\n    assert(n >= 1);\n    std::vector<int> rnk(n);\n\
    \    for (int i = 0; i < n; i++) {\n        rnk[sa[i]] = i;\n    }\n    std::vector<int>\
    \ lcp(n - 1);\n    int h = 0;\n    for (int i = 0; i < n; i++) {\n        if (h\
    \ > 0) h--;\n        if (rnk[i] == 0) continue;\n        int j = sa[rnk[i] - 1];\n\
    \        for (; j + h < n && i + h < n; h++) {\n            if (s[j + h] != s[i\
    \ + h]) break;\n        }\n        lcp[rnk[i] - 1] = h;\n    }\n    return lcp;\n\
    }\n\nstd::vector<int> lcp_array(const std::string& s, const std::vector<int>&\
    \ sa) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return lcp_array(s2,\
    \ sa);\n}\n#line 1 \"string/longestCommonSubstring.cpp\"\n//#include<string/suffixArray.cpp>\n\
    \narray<int, 4> longestCommonSubstring(string s, string t) {\n  t = s + '#' +\
    \ t;\n  auto sa = suffix_array(t);\n  auto lcp = lcp_array(t, sa);\n  array<int,\
    \ 4> res = {};\n  for(int i = 0; i < ssize(lcp); i++) {\n    if (lcp[i] <= res[1]\
    \ - res[0]) continue;\n    if (sa[i] < ssize(s) and sa[i + 1] > ssize(s))\n  \
    \    res = {sa[i], sa[i] + lcp[i], sa[i + 1] - (int)(ssize(s) + 1), sa[i + 1]\
    \ - (int)(ssize(s) + 1) + lcp[i]};\n    else if (sa[i] > ssize(s) and sa[i + 1]\
    \ < ssize(s))\n      res = {sa[i + 1], sa[i + 1] + lcp[i], sa[i] - (int)(ssize(s)\
    \ + 1), sa[i] - (int)(ssize(s) + 1) + lcp[i]};\n  }\n  return res;\n}\n#line 6\
    \ \"test/longest_common_substring.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  string s, t; cin >> s >> t;\n  cout << longestCommonSubstring(s,\
    \ t) << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_common_substring\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../string/suffixArray.cpp\"\n#include\
    \ \"../string/longestCommonSubstring.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  string s, t; cin >> s >> t;\n  cout << longestCommonSubstring(s,\
    \ t) << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - string/suffixArray.cpp
  - string/longestCommonSubstring.cpp
  isVerificationFile: true
  path: test/longest_common_substring.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 18:02:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/longest_common_substring.test.cpp
layout: document
redirect_from:
- /verify/test/longest_common_substring.test.cpp
- /verify/test/longest_common_substring.test.cpp.html
title: test/longest_common_substring.test.cpp
---
