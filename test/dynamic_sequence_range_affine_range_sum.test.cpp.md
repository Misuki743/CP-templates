---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: actedmonoid/actedMonoid_affineSum.cpp
    title: actedmonoid/actedMonoid_affineSum.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/treap.cpp
    title: treap
  - icon: ':question:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/dynamic_sequence_range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <variant>\n#include <bit>\n#include <compare>\n#include <concepts>\n#include\
    \ <numbers>\n#include <ranges>\n#include <span>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\nusing namespace\
    \ std;\n\ntemplate<class T1, class T2>\nostream& operator<<(ostream& os, const\
    \ pair<T1, T2> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class\
    \ T, size_t N>\nostream& operator<<(ostream& os, const array<T, N> &arr) {\n \
    \ for(size_t i = 0; T x : arr) {\n    os << x;\n    if (++i != N) os << ' ';\n\
    \  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const\
    \ vector<T> &vec) {\n  for(size_t i = 0; T x : vec) {\n    os << x;\n    if (++i\
    \ != size(vec)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(size_t i = 0; T x : s) {\n\
    \    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n}\ntemplate<class\
    \ T1, class T2>\nostream& operator<<(ostream& os, const map<T1, T2> &m) {\n  for(size_t\
    \ i = 0; pair<T1, T2> x : m) {\n    os << x;\n    if (++i != size(m)) os << '\
    \ ';\n  }\n  return os;\n}\n\n#ifdef DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__),\
    \ cerr << \") = \", _do2(__VA_ARGS__)\ntemplate<typename T> void _do(T &&x) {\
    \ cerr << x; }\ntemplate<typename T, typename ...S> void _do(T &&x, S&&...y) {\
    \ cerr << x << \", \"; _do(y...); }\ntemplate<typename T> void _do2(T &&x) { cerr\
    \ << x << endl; }\ntemplate<typename T, typename ...S> void _do2(T &&x, S&&...y)\
    \ { cerr << x << \", \"; _do2(y...); }\n#else\n#define dbg(...)\n#endif\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<typename T>\
    \ using min_heap = priority_queue<T, vector<T>, greater<T>>;\ntemplate<typename\
    \ T> using max_heap = priority_queue<T>;\n\ntemplate<ranges::forward_range rng,\
    \ class T = ranges::range_value_t<rng>, class OP = plus<T>>\nvoid pSum(rng &&v)\
    \ {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n     \
    \ x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>,\
    \ class OP>\nvoid pSum(rng &&v, OP op) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = op(p, x);\n}\n\ntemplate<ranges::forward_range\
    \ rng>\nvoid Unique(rng &v) {\n  ranges::sort(v);\n  v.resize(unique(v.begin(),\
    \ v.end()) - v.begin());\n}\n\ntemplate<ranges::random_access_range rng>\nrng\
    \ invPerm(rng p) {\n  rng ret = p;\n  for(int i = 0; i < ssize(p); i++)\n    ret[p[i]]\
    \ = i;\n  return ret;\n}\n\ntemplate<ranges::random_access_range rng, ranges::random_access_range\
    \ rng2>\nrng Permute(rng v, rng2 p) {\n  rng ret = v;\n  for(int i = 0; i < ssize(p);\
    \ i++)\n    ret[p[i]] = v[i];\n  return ret;\n}\n\ntemplate<bool directed>\nvector<vector<int>>\
    \ read_graph(int n, int m, int base) {\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 0; i < m; i++) {\n    int u, v; cin >> u >> v;\n    u -= base, v -= base;\n\
    \    g[u].emplace_back(v);\n    if constexpr (!directed)\n      g[v].emplace_back(u);\n\
    \  }\n  return g;\n}\n\ntemplate<bool directed>\nvector<vector<int>> adjacency_list(int\
    \ n, vector<pii> e, int base) {\n  vector<vector<int>> g(n);\n  for(auto [u, v]\
    \ : e) {\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n    if constexpr\
    \ (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n}\n\ntemplate<class\
    \ T>\nvoid setBit(T &msk, int bit, bool x) {\n  msk = (msk & ~(T(1) << bit)) |\
    \ (T(x) << bit);\n}\ntemplate<class T> void flipBit(T &msk, int bit) { msk ^=\
    \ T(1) << bit; }\ntemplate<class T> bool getBit(T msk, int bit) { return msk >>\
    \ bit & T(1); }\n\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b < 0) a *=\
    \ -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\n\ntemplate<class T> bool chmin(T &a, T b) { return\
    \ a > b ? a = b, 1 : 0; }\ntemplate<class T> bool chmax(T &a, T b) { return a\
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"modint/MontgomeryModInt.cpp\"\n//reference:\
    \ https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be an odd prime less than 2^30.\n\ntemplate<uint32_t mod>\n\
    struct MontgomeryModInt {\n  using mint = MontgomeryModInt;\n  using i32 = int32_t;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r()\
    \ {\n    u32 res = 1, base = mod;\n    for(i32 i = 0; i < 31; i++)\n      res\
    \ *= base, base *= base;\n    return -res;\n  }\n\n  static constexpr u32 get_mod()\
    \ {\n    return mod;\n  }\n\n  static constexpr u32 n2 = -u64(mod) % mod; //2^64\
    \ % mod\n  static constexpr u32 r = get_r(); //-P^{-1} % 2^32\n\n  u32 a;\n\n\
    \  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * r) * mod) >>\
    \ 32;\n  }\n\n  static u32 transform(const u64 &b) {\n    return reduce(u64(b)\
    \ * n2);\n  }\n\n  MontgomeryModInt() : a(0) {}\n  MontgomeryModInt(const int64_t\
    \ &b) \n    : a(transform(b % mod + mod)) {}\n\n  mint pow(u64 k) const {\n  \
    \  mint res(1), base(*this);\n    while(k) {\n      if (k & 1) \n        res *=\
    \ base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse()\
    \ const { return (*this).pow(mod - 2); }\n\n  u32 get() const {\n    u32 res =\
    \ reduce(a);\n    return res >= mod ? res - mod : res;\n  }\n\n  mint& operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  mint& operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2\
    \ * mod;\n    return *this;\n  }\n\n  mint& operator*=(const mint &b) {\n    a\
    \ = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint& operator/=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.inverse().a);\n    return *this;\n  }\n\
    \n  mint operator-() { return mint() - mint(*this); }\n  bool operator==(mint\
    \ b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod :\
    \ b.a);\n  }\n  bool operator!=(mint b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n\n  friend mint operator+(mint\
    \ c, mint d) { return c += d; }\n  friend mint operator-(mint c, mint d) { return\
    \ c -= d; }\n  friend mint operator*(mint c, mint d) { return c *= d; }\n  friend\
    \ mint operator/(mint c, mint d) { return c /= d; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b.get();\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"ds/treap.cpp\"\
    \nmt19937 rng(clock);\n\ntemplate<class M, M(*Mid)(), M(*Mop)(const M&, const\
    \ M&), class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const M&, const\
    \ T&)>\nstruct treap {\n  struct node {\n    int pri, size = 1;\n    bool rev\
    \ = false;\n    node *l = nullptr, *r = nullptr;\n    M data, prod;\n    T tag;\n\
    \    node(M init = M()) : pri(rng()), data(init), prod(init), tag(Tid()) {}\n\
    \  };\n\n  static int size(node *v) { return v ? v -> size : 0; }\n  static M\
    \ get(node *v) { return v ? v -> prod : Mid(); }\n\n  static node* build(vector<M>\
    \ init) {\n    node* r = nullptr;\n    for(M &x : init) r = merge(r, new node(x));\n\
    \    return r;\n  }\n\n  static void apply(node *v, T x, bool rev) {\n    if (!v)\
    \ return;\n    if (x != Tid()) {\n      v -> data = act(v -> data, x);\n     \
    \ v -> prod = act(v -> prod, x);\n      v -> tag = Top(v -> tag, x);\n    }\n\
    \    if (rev) {\n      v -> rev ^= 1;\n      swap(v -> l, v -> r);\n    }\n  }\n\
    \n  static void push(node *v) {\n    if (!v) return;\n    for(node* c : {v ->\
    \ l, v -> r})\n      apply(c, v -> tag, v -> rev);\n    v -> tag = Tid(), v ->\
    \ rev = false;\n  }\n\n  static void pull(node *v) {\n    if (!v) return;\n  \
    \  v -> size = 1, v -> prod = v -> data;\n    if (node* lc = v -> l; lc) {\n \
    \     v -> size += lc -> size;\n      v -> prod = Mop(lc -> prod, v -> prod);\n\
    \    }\n    if (node* rc = v -> r; rc) {\n      v -> size += rc -> size;\n   \
    \   v -> prod = Mop(v -> prod, rc -> prod);\n    }\n  }\n\n  static void split(node\
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
    \    tmp[1] = nullptr;\n    root = uncut(tmp);\n  }\n};\n#line 1 \"actedmonoid/actedMonoid_affineSum.cpp\"\
    \ntemplate<class U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n\
    \  static M Mid() { return M{0, 0}; }\n  static M Mop(const M &a, const M &b)\
    \ { return {a[0] + b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T\
    \ Tid() { return T{1, 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0]\
    \ * b[0], a[1] * b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return\
    \ {a[0] * b[0] + a[1] * b[1], a[1]}; }\n};\n#line 7 \"test/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n\nusing am = actedMonoid_affineSum<mint>;\nusing Treap = treap<am::M, am::Mid,\
    \ am::Mop, am::T, am::Tid, am::Top, am::act>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<array<mint, 2>> a(n,\
    \ {0, 1});\n  for(auto &[x, _] : a)\n    cin >> x;\n\n  Treap::node* tr = Treap::build(a);\n\
    \n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int i, x; cin\
    \ >> i >> x;\n      Treap::insert(tr, i, {x, 1});\n    } else if (t == 1) {\n\
    \      int i; cin >> i;\n      Treap::erase(tr, i);\n    } else if (t == 2) {\n\
    \      int l, r; cin >> l >> r;\n      Treap::modify(tr, l, r, am::Tid(), true);\n\
    \    } else if (t == 3) {\n      int l, r, b, c; cin >> l >> r >> b >> c;\n  \
    \    Treap::modify(tr, l, r, {b, c});\n    } else if (t == 4) {\n      int l,\
    \ r; cin >> l >> r;\n      cout << Treap::query(tr, l, r)[0] << '\\n';\n    }\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../ds/treap.cpp\"\n#include \"../actedmonoid/actedMonoid_affineSum.cpp\"\
    \n\nusing am = actedMonoid_affineSum<mint>;\nusing Treap = treap<am::M, am::Mid,\
    \ am::Mop, am::T, am::Tid, am::Top, am::act>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<array<mint, 2>> a(n,\
    \ {0, 1});\n  for(auto &[x, _] : a)\n    cin >> x;\n\n  Treap::node* tr = Treap::build(a);\n\
    \n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int i, x; cin\
    \ >> i >> x;\n      Treap::insert(tr, i, {x, 1});\n    } else if (t == 1) {\n\
    \      int i; cin >> i;\n      Treap::erase(tr, i);\n    } else if (t == 2) {\n\
    \      int l, r; cin >> l >> r;\n      Treap::modify(tr, l, r, am::Tid(), true);\n\
    \    } else if (t == 3) {\n      int l, r, b, c; cin >> l >> r >> b >> c;\n  \
    \    Treap::modify(tr, l, r, {b, c});\n    } else if (t == 4) {\n      int l,\
    \ r; cin >> l >> r;\n      cout << Treap::query(tr, l, r)[0] << '\\n';\n    }\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - ds/treap.cpp
  - actedmonoid/actedMonoid_affineSum.cpp
  isVerificationFile: true
  path: test/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/dynamic_sequence_range_affine_range_sum.test.cpp
---
