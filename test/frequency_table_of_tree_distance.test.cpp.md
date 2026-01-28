---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/centroidTree.cpp
    title: ds/centroidTree.cpp
  - icon: ':x:'
    path: ds_problem/frequency_of_tree_distance.cpp
    title: ds_problem/frequency_of_tree_distance.cpp
  - icon: ':question:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  - icon: ':x:'
    path: numtheory/crt.cpp
    title: numtheory/crt.cpp
  - icon: ':question:'
    path: poly/NTTmint.cpp
    title: poly/NTTmint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/frequency_table_of_tree_distance.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"poly/NTTmint.cpp\"\
    \n//reference: https://judge.yosupo.jp/submission/69896\n//remark: MOD = 2^K *\
    \ C + 1, R is a primitive root modulo MOD\n//remark: a.size() <= 2^K must be satisfied\n\
    //some common modulo: 998244353  = 2^23 * 119 + 1, R = 3\n//                 \
    \   469762049  = 2^26 * 7   + 1, R = 3\n//                    1224736769 = 2^24\
    \ * 73  + 1, R = 3\n\ntemplate<int32_t k = 23, int32_t c = 119, int32_t r = 3,\
    \ class Mint = MontgomeryModInt<998244353>>\nstruct NTT {\n\n  using u32 = uint32_t;\n\
    \  static constexpr u32 mod = (1 << k) * c + 1;\n  static constexpr u32 get_mod()\
    \ { return mod; }\n\n  static void ntt(vector<Mint> &a, bool inverse) {\n    static\
    \ array<Mint, 30> w, w_inv;\n    if (w[0] == 0) {\n      Mint root = 2;\n    \
    \  while(root.pow((mod - 1) / 2) == 1) root += 1;\n      for(int i = 0; i < 30;\
    \ i++)\n        w[i] = -(root.pow((mod - 1) >> (i + 2))), w_inv[i] = 1 / w[i];\n\
    \    }\n    int n = ssize(a);\n    if (not inverse) {\n      for(int m = n; m\
    \ >>= 1; ) {\n        Mint ww = 1;\n        for(int s = 0, l = 0; s < n; s +=\
    \ 2 * m) {\n          for(int i = s, j = s + m; i < s + m; i++, j++) {\n     \
    \       Mint x = a[i], y = a[j] * ww;\n            a[i] = x + y, a[j] = x - y;\n\
    \          }\n          ww *= w[__builtin_ctz(++l)];\n        }\n      }\n   \
    \ } else {\n      for(int m = 1; m < n; m *= 2) {\n        Mint ww = 1;\n    \
    \    for(int s = 0, l = 0; s < n; s += 2 * m) {\n          for(int i = s, j =\
    \ s + m; i < s + m; i++, j++) {\n            Mint x = a[i], y = a[j];\n      \
    \      a[i] = x + y, a[j] = (x - y) * ww;\n          }\n          ww *= w_inv[__builtin_ctz(++l)];\n\
    \        }\n      }\n      Mint inv = 1 / Mint(n);\n      for(Mint &x : a) x *=\
    \ inv;\n    }\n  }\n\n  static vector<Mint> conv(vector<Mint> a, vector<Mint>\
    \ b) {\n    int sz = ssize(a) + ssize(b) - 1;\n    int n = bit_ceil((u32)sz);\n\
    \n    a.resize(n, 0);\n    ntt(a, false);\n    b.resize(n, 0);\n    ntt(b, false);\n\
    \n    for(int i = 0; i < n; i++)\n      a[i] *= b[i];\n\n    ntt(a, true);\n\n\
    \    a.resize(sz);\n\n    return a;\n  }\n};\n#line 1 \"ds/centroidTree.cpp\"\n\
    pair<vector<vector<int>>, int> centroidTree(vector<vector<int>> &g) {\n  int n\
    \ = ssize(g);\n  vector<vector<int>> g2(n);\n  vector<int> sz(n);\n  vector<bool>\
    \ block(n, false);\n\n  auto calc = [&](int v, int p, auto self) -> void {\n \
    \   sz[v] = 1;\n    for(int x : g[v]) {\n      if (x == p or block[x]) continue;\n\
    \      self(x, v, self);\n      sz[v] += sz[x];\n    }\n  };\n\n  auto dfs = [&](int\
    \ v, auto self) -> int {\n    calc(v, -1, calc);\n\n    int c = v, p = -1;\n \
    \   bool move;\n    do {\n      move = false;\n      for(int x : g[c]) {\n   \
    \     if (x == p or block[x] or 2 * sz[x] <= sz[v]) continue;\n        move =\
    \ true, p = c, c = x;\n        break;\n      }\n    } while(move);\n\n    block[c]\
    \ = true;\n    for(int x : g[c]) {\n      if (block[x]) continue;\n      x = self(x,\
    \ self);\n      g2[c].emplace_back(x);\n      g2[x].emplace_back(c);\n    }\n\n\
    \    return c;\n  };\n\n  int root = dfs(0, dfs);\n\n  return make_pair(g2, root);\n\
    }\n#line 1 \"numtheory/crt.cpp\"\n//source: AtCoder Library (https://github.com/atcoder/ac-library)\n\
    \n#include <utility>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n// @param\
    \ m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long x, long\
    \ long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// (rem, mod)\nstd::pair<long long, long long> crt(const std::vector<long long>&\
    \ r,\n                                    const std::vector<long long>& m) {\n\
    \    assert(r.size() == m.size());\n    int n = int(r.size());\n    // Contracts:\
    \ 0 <= r0 < m0\n    long long r0 = 0, m0 = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n        assert(1 <= m[i]);\n        long long r1 = safe_mod(r[i], m[i]),\
    \ m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n       \
    \     std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n           \
    \ if (r0 % m1 != r1) return {0, 0};\n            continue;\n        }\n      \
    \  // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)\n\n        // (r0, m0),\
    \ (r1, m1) -> (r2, m2 = lcm(m0, m1));\n        // r2 % m0 = r0\n        // r2\
    \ % m1 = r1\n        // -> (r0 + x*m0) % m1 = r1\n        // -> x*u0*g = r1-r0\
    \ (mod u1*g) (u0*g = m0, u1*g = m1)\n        // -> x = (r1 - r0) / g * inv(u0)\
    \ (mod u1)\n\n        // im = inv(u0) (mod u1) (0 <= im < u1)\n        long long\
    \ g, im;\n        std::tie(g, im) = inv_gcd(m0, m1);\n\n        long long u1 =\
    \ (m1 / g);\n        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)\n        if ((r1\
    \ - r0) % g) return {0, 0};\n\n        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1\
    \ / g = lcm(m0, m1)\n        long long x = (r1 - r0) / g % u1 * im % u1;\n\n \
    \       // |r0| + |m0 * x|\n        // < m0 + m0 * (u1 - 1)\n        // = m0 +\
    \ m0 * m1 / g - m0\n        // = lcm(m0, m1)\n        r0 += x * m0;\n        m0\
    \ *= u1;  // -> lcm(m0, m1)\n        if (r0 < 0) r0 += m0;\n    }\n    return\
    \ {r0, m0};\n}\n#line 1 \"ds_problem/frequency_of_tree_distance.cpp\"\ntemplate<int32_t\
    \ k = 23, int32_t c = 119, int32_t r = 3, class Mint = MontgomeryModInt<998244353>>\n\
    vector<Mint> frequency_of_tree_distance(vector<vector<int>> g) {\n  const int\
    \ n = ssize(g);\n  NTT<k, c, r, Mint> Ntt;\n\n  auto [T, R] = centroidTree(g);\n\
    \  vector<bool> vis(n, false);\n  auto calc = [&](int s, int d0) {\n    vector<Mint>\
    \ freq(1);\n    auto dfs = [&](int v, int p, int d, auto &self) -> void {\n  \
    \    if (ssize(freq) <= d) freq.emplace_back(0);\n      if (d > 0) freq[d] +=\
    \ 1;\n      for(int x : g[v])\n        if (x != p and !vis[x])\n          self(x,\
    \ v, d + 1, self);\n    };\n    dfs(s, -1, d0, dfs);\n    return freq;\n  };\n\
    \n  auto self_conv = [&](vector<Mint> f) {\n    int sz = bit_ceil(2 * f.size());\n\
    \    f.resize(sz);\n    Ntt.ntt(f, false);\n    for(Mint &x : f) x *= x;\n   \
    \ Ntt.ntt(f, true);\n    return f;\n  };\n\n  vector<Mint> ans(n);\n  auto dfs\
    \ = [&](int v, int p, auto &self) -> void {\n    {\n      auto freq_all = calc(v,\
    \ 0);\n      freq_all[0] = 1;\n      auto F = self_conv(freq_all);\n      for(int\
    \ i = 0; i < n and i < ssize(F); i++)\n        ans[i] += F[i];\n      vis[v] =\
    \ true;\n      for(int x : g[v]) {\n        if (vis[x]) continue;\n        auto\
    \ G = self_conv(calc(x, 1));\n        for(int i = 0; i < n and i < ssize(G); i++)\n\
    \          ans[i] -= G[i];\n      }\n    }\n    for(int x : T[v])\n      if (x\
    \ != p)\n        self(x, v, self);\n  };\n  dfs(R, -1, dfs);\n\n  ans.erase(ans.begin());\n\
    \  for(Mint &x : ans) x *= (Mint::get_mod() + 1) / 2;\n  return ans;\n}\n#line\
    \ 9 \"test/frequency_table_of_tree_distance.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 1; i < n; i++) {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v),\
    \ g[v].emplace_back(u);\n  }\n\n  auto ans1 = frequency_of_tree_distance(g);\n\
    \  auto ans2 = frequency_of_tree_distance<26, 7, 3, MontgomeryModInt<(7 << 26)\
    \ | 1>>(g);\n  for(int i = 0; i < n - 1; i++) {\n    vector<ll> r = {ans1[i].get(),\
    \ ans2[i].get()};\n    vector<ll> m = {998244353, (7 << 26) | 1};\n    cout <<\
    \ crt(r, m).first << \" \\n\"[i + 1 == n - 1];\n  }\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../poly/NTTmint.cpp\"\n#include \"../ds/centroidTree.cpp\"\n#include\
    \ \"../numtheory/crt.cpp\"\n#include \"../ds_problem/frequency_of_tree_distance.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n;\
    \ cin >> n;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n   \
    \ int u, v; cin >> u >> v;\n    g[u].emplace_back(v), g[v].emplace_back(u);\n\
    \  }\n\n  auto ans1 = frequency_of_tree_distance(g);\n  auto ans2 = frequency_of_tree_distance<26,\
    \ 7, 3, MontgomeryModInt<(7 << 26) | 1>>(g);\n  for(int i = 0; i < n - 1; i++)\
    \ {\n    vector<ll> r = {ans1[i].get(), ans2[i].get()};\n    vector<ll> m = {998244353,\
    \ (7 << 26) | 1};\n    cout << crt(r, m).first << \" \\n\"[i + 1 == n - 1];\n\
    \  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - poly/NTTmint.cpp
  - ds/centroidTree.cpp
  - numtheory/crt.cpp
  - ds_problem/frequency_of_tree_distance.cpp
  isVerificationFile: true
  path: test/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/frequency_table_of_tree_distance.test.cpp
- /verify/test/frequency_table_of_tree_distance.test.cpp.html
title: test/frequency_table_of_tree_distance.test.cpp
---
