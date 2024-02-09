---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/treap.cpp
    title: ds/treap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_reverse_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
  bundledCode: "#line 1 \"test/range_reverse_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"ds/treap.cpp\"\nmt19937\
    \ rng(clock);\n\ntemplate<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const\
    \ M&, const M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>\n\
    struct treap {\n  struct node {\n    int pri, size = 1;\n    bool rev = false;\n\
    \    node *l = nullptr, *r = nullptr;\n    M data, prod;\n    T tag;\n    node()\
    \ : pri(rng()), data(Munit()), prod(Munit()), tag(Tunit()) {}\n    node(M init)\
    \ : pri(rng()), data(init), prod(init), tag(Tunit()) {}\n  };\n\n  static int\
    \ size(node *v) { return v ? v -> size : 0; }\n  static M get(node *v) { return\
    \ v ? v -> prod : Munit(); }\n\n  static node* build(vector<M> init) {\n    node*\
    \ res = nullptr;\n    for(M &x : init)\n      res = merge(res, new node(x));\n\
    \    return res;\n  }\n\n  static void apply(node *v, T x, bool rev) {\n    if\
    \ (!v) return;\n    if (x != Tunit()) {\n      v -> data = comp(v -> data, x);\n\
    \      v -> prod = comp(v -> prod, x);\n      v -> tag = Tope(v -> tag, x);\n\
    \    }\n    if (rev) {\n      v -> rev ^= 1;\n      swap(v -> l, v -> r);\n  \
    \  }\n  }\n\n  static void push(node *v) {\n    if (!v) return;\n    for(node*\
    \ c : {v -> l, v -> r})\n      apply(c, v -> tag, v -> rev);\n    v -> tag = Tunit(),\
    \ v -> rev = false;\n  }\n\n  static void pull(node *v) {\n    if (!v) return;\n\
    \    v -> size = 1, v -> prod = v -> data;\n    if (node* lc = v -> l; lc) {\n\
    \      v -> size += lc -> size;\n      v -> prod = Mope(lc -> prod, v -> prod);\n\
    \    }\n    if (node* rc = v -> r; rc) {\n      v -> size += rc -> size;\n   \
    \   v -> prod = Mope(v -> prod, rc -> prod);\n    }\n  }\n\n  static void split(node\
    \ *v, int x, node *&l, node *&r, int add = 0) {\n    if (!v) {\n      l = r =\
    \ nullptr;\n      return;\n    }\n    push(v);\n    if (int key = add + size(v\
    \ -> l); key < x)\n      split(v -> r, x, v -> r, r, add + size(v -> l) + 1),\
    \ l = v;\n    else\n      split(v -> l, x, l, v -> l, add), r = v;\n    pull(v);\n\
    \  }\n\n  static node* merge(node *l, node *r) {\n    if (!l or !r) return l ?\
    \ l : r;\n    push(l), push(r);\n    if (l -> pri < r -> pri) {\n      l -> r\
    \ = merge(l -> r, r);\n      pull(l);\n      return l;\n    } else {\n      r\
    \ -> l = merge(l, r -> l);\n      pull(r);\n      return r;\n    }\n  }\n\n  static\
    \ array<node*, 3> cut(node *root, int l, int r) {\n    array<node*, 3> tmp = {};\n\
    \    split(root, l, tmp[0], tmp[1]);\n    split(tmp[1], r - l, tmp[1], tmp[2]);\n\
    \    return tmp;\n  }\n\n  static node* uncut(array<node*, 3> roots) {\n    return\
    \ merge(roots[0], merge(roots[1], roots[2]));\n  }\n\n  static void modify(node\
    \ *root, int l, int r, T x, bool rev = false) {\n    auto tmp = cut(root, l, r);\n\
    \    apply(tmp[1], x, rev);\n    uncut(tmp);\n  }\n\n  static M query(node *root,\
    \ int l, int r) {\n    auto tmp = cut(root, l, r);\n    M res = get(tmp[1]);\n\
    \    uncut(tmp);\n    return res;\n  }\n\n  static void insert(node *&root, int\
    \ i, M x) {\n    array<node*, 3> tmp = {};\n    tmp[1] = new node(x);\n    split(root,\
    \ i, tmp[0], tmp[2]);\n    root = uncut(tmp);\n  }\n\n  static void erase(node\
    \ *&root, int i) {\n    auto tmp = cut(root, i, i + 1);\n    delete tmp[1];\n\
    \    tmp[1] = nullptr;\n    root = uncut(tmp);\n  }\n};\n#line 5 \"test/range_reverse_range_sum.test.cpp\"\
    \n\nll Munit() { return 0ll; }\nbool Tunit() { return true; }\nll Mope(const ll\
    \ &a, const ll &b) { return a + b; }\nbool Tope(const bool&, const bool&) { return\
    \ true; }\nll comp(const ll &a, const bool&) { return a; }\n\nusing Treap = treap<ll,\
    \ bool, Munit, Tunit, Mope, Tope, comp>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a)\n    cin >> x;\n\n  Treap::node* tr = Treap::build(a);\n\n  while(q--)\
    \ {\n    int t, l, r; cin >> t >> l >> r;\n    if (t == 0)\n      Treap::modify(tr,\
    \ l, r, Tunit(), true);\n    else\n      cout << Treap::query(tr, l, r) << '\\\
    n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/treap.cpp\"\n\nll Munit()\
    \ { return 0ll; }\nbool Tunit() { return true; }\nll Mope(const ll &a, const ll\
    \ &b) { return a + b; }\nbool Tope(const bool&, const bool&) { return true; }\n\
    ll comp(const ll &a, const bool&) { return a; }\n\nusing Treap = treap<ll, bool,\
    \ Munit, Tunit, Mope, Tope, comp>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a)\n    cin >> x;\n\n  Treap::node* tr = Treap::build(a);\n\n  while(q--)\
    \ {\n    int t, l, r; cin >> t >> l >> r;\n    if (t == 0)\n      Treap::modify(tr,\
    \ l, r, Tunit(), true);\n    else\n      cout << Treap::query(tr, l, r) << '\\\
    n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/treap.cpp
  isVerificationFile: true
  path: test/range_reverse_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-28 22:59:51+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range_reverse_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/range_reverse_range_sum.test.cpp
- /verify/test/range_reverse_range_sum.test.cpp.html
title: test/range_reverse_range_sum.test.cpp
---
