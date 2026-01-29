---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combi/chromaticNumber.cpp
    title: combi/chromaticNumber.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamicMontgomeryModInt.cpp
    title: modint/dynamicMontgomeryModInt.cpp
  - icon: ':question:'
    path: numtheory/factorize_pollard_rho.cpp
    title: numtheory/factorize_pollard_rho.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/chromatic_number.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\
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
    \ std;\n\ntemplate<size_t I = 0, typename... args>\nostream& print_tuple(ostream&\
    \ os, const tuple<args...> tu) {\n  os << get<I>(tu);\n  if constexpr (I + 1 !=\
    \ sizeof...(args)) {\n    os << ' ';\n    print_tuple<I + 1>(os, tu);\n  }\n \
    \ return os;\n}\ntemplate<typename... args>\nostream& operator<<(ostream& os,\
    \ const tuple<args...> tu) {\n  return print_tuple(os, tu);\n}\ntemplate<class\
    \ T1, class T2>\nostream& operator<<(ostream& os, const pair<T1, T2> pr) {\n \
    \ return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(size_t i = 0;\
    \ T x : arr) {\n    os << x;\n    if (++i != N) os << ' ';\n  }\n  return os;\n\
    }\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T> &vec) {\n\
    \  for(size_t i = 0; T x : vec) {\n    os << x;\n    if (++i != size(vec)) os\
    \ << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const set<T> &s) {\n  for(size_t i = 0; T x : s) {\n    os << x;\n    if\
    \ (++i != size(s)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const multiset<T> &s) {\n  for(size_t i = 0; T x : s)\
    \ {\n    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n}\n\
    template<class T1, class T2>\nostream& operator<<(ostream& os, const map<T1, T2>\
    \ &m) {\n  for(size_t i = 0; pair<T1, T2> x : m) {\n    os << x.first << \" :\
    \ \" << x.second;\n    if (++i != size(m)) os << \", \";\n  }\n  return os;\n\
    }\n\n#ifdef DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__), cerr << \"\
    ) = \", _do2(__VA_ARGS__)\ntemplate<typename T> void _do(T &&x) { cerr << x; }\n\
    template<typename T, typename ...S> void _do(T &&x, S&&...y) { cerr << x << \"\
    , \"; _do(y...); }\ntemplate<typename T> void _do2(T &&x) { cerr << x << endl;\
    \ }\ntemplate<typename T, typename ...S> void _do2(T &&x, S&&...y) { cerr << x\
    \ << \", \"; _do2(y...); }\n#else\n#define dbg(...)\n#endif\n\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\nusing ldb = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<typename T> using vc\
    \ = vector<T>;\ntemplate<typename T> using vvc = vc<vc<T>>;\ntemplate<typename\
    \ T> using vvvc = vc<vvc<T>>;\n\nusing vi = vc<int>;\nusing vll = vc<ll>;\nusing\
    \ vvi = vvc<int>;\nusing vvll = vvc<ll>;\n\ntemplate<typename T> using min_heap\
    \ = priority_queue<T, vector<T>, greater<T>>;\ntemplate<typename T> using max_heap\
    \ = priority_queue<T>;\n\ntemplate<typename R, typename F, typename... Args>\n\
    concept R_invocable = requires(F&& f, Args&&... args) {\n  { std::invoke(std::forward<F>(f),\
    \ std::forward<Args>(args)...) } -> std::same_as<R>;\n};\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>, typename F>\nrequires R_invocable<T,\
    \ F, T, T>\nvoid pSum(rng &&v, F f) {\n  if (!v.empty())\n    for(T p = *v.begin();\
    \ T &x : v | views::drop(1))\n      x = p = f(p, x);\n}\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>>\nvoid pSum(rng &&v) {\n  if (!v.empty())\n\
    \    for(T p = *v.begin(); T &x : v | views::drop(1))\n      x = p = p + x;\n\
    }\n\ntemplate<ranges::forward_range rng>\nvoid Unique(rng &v) {\n  ranges::sort(v);\n\
    \  v.resize(unique(v.begin(), v.end()) - v.begin());\n}\n\ntemplate<ranges::random_access_range\
    \ rng>\nrng invPerm(rng p) {\n  rng ret = p;\n  for(int i = 0; i < ssize(p); i++)\n\
    \    ret[p[i]] = i;\n  return ret;\n}\n\ntemplate<bool directed>\nvector<vector<int>>\
    \ read_graph(int n, int m, int base) {\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 0; i < m; i++) {\n    int u, v; cin >> u >> v;\n    u -= base, v -= base;\n\
    \    g[u].emplace_back(v);\n    if constexpr (!directed)\n      g[v].emplace_back(u);\n\
    \  }\n  return g;\n}\n\ntemplate<bool directed>\nvector<vector<int>> adjacency_list(int\
    \ n, vector<pii> e, int base) {\n  vector<vector<int>> g(n);\n  for(auto [u, v]\
    \ : e) {\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n    if constexpr\
    \ (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n}\n\ntemplate<class\
    \ T>\nvoid setBit(T &msk, int bit, bool x) { (msk &= ~(T(1) << bit)) |= T(x) <<\
    \ bit; }\ntemplate<class T> void onBit(T &msk, int bit) { setBit(msk, bit, true);\
    \ }\ntemplate<class T> void offBit(T &msk, int bit) { setBit(msk, bit, false);\
    \ }\ntemplate<class T> void flipBit(T &msk, int bit) { msk ^= T(1) << bit; }\n\
    template<class T> bool getBit(T msk, int bit) { return msk >> bit & T(1); }\n\n\
    template<class T>\nT floorDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return\
    \ a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class T>\nT ceilDiv(T a, T b)\
    \ {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ? (a + b - 1) / b : a / b;\n\
    }\n\ntemplate<class T> bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }\n\
    template<class T> bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n\n#line\
    \ 1 \"modint/dynamicMontgomeryModInt.cpp\"\n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be an odd prime less than 2^30.\n\ntemplate<uint32_t ver>\n\
    struct MontgomeryModInt {\n  using mint = MontgomeryModInt;\n  using i32 = int32_t;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod, n2, r;\n\
    \n  static constexpr u32 get_r() {\n    u32 res = 1, base = mod;\n    for(i32\
    \ i = 0; i < 31; i++)\n      res *= base, base *= base;\n    return -res;\n  }\n\
    \n  static constexpr u32 get_mod() {\n    return mod;\n  }\n\n  static void set_mod(u32\
    \ _mod) {\n    mod = _mod;\n    n2 = -u64(mod) % mod;\n    r = get_r();\n  }\n\
    \n  u32 a;\n\n  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b)\
    \ * r) * mod) >> 32;\n  }\n\n  static u32 transform(const u64 &b) {\n    return\
    \ reduce(u64(b) * n2);\n  }\n\n  MontgomeryModInt() : a(0) {}\n  MontgomeryModInt(const\
    \ int64_t &b) \n    : a(transform(b % mod + mod)) {}\n\n  mint pow(u64 k) const\
    \ {\n    mint res(1), base(*this);\n    while(k) {\n      if (k & 1) \n      \
    \  res *= base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\n\
    \  mint inverse() const { return (*this).pow(mod - 2); }\n\n  u32 get() const\
    \ {\n    u32 res = reduce(a);\n    return res >= mod ? res - mod : res;\n  }\n\
    \n  mint& operator+=(const mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a\
    \ += 2 * mod;\n    return *this;\n  }\n\n  mint& operator-=(const mint &b) {\n\
    \    if (i32(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint& operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint&\
    \ operator/=(const mint &b) {\n    a = reduce(u64(a) * b.inverse().a);\n    return\
    \ *this;\n  }\n\n  mint operator-() { return mint() - mint(*this); }\n  bool operator==(mint\
    \ b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod :\
    \ b.a);\n  }\n  bool operator!=(mint b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n\n  friend mint operator+(mint\
    \ c, mint d) { return c += d; }\n  friend mint operator-(mint c, mint d) { return\
    \ c -= d; }\n  friend mint operator*(mint c, mint d) { return c *= d; }\n  friend\
    \ mint operator/(mint c, mint d) { return c /= d; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b.get();\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<0>;\ntemplate<> uint32_t mint::mod\
    \ = 0;\ntemplate<> uint32_t mint::n2 = 0;\ntemplate<> uint32_t mint::r = 0;\n\
    #line 1 \"numtheory/factorize_pollard_rho.cpp\"\n//source: KACTL(https://github.com/kth-competitive-programming/kactl)\n\
    \null modmul(ull a, ull b, ull M) {\n\tll ret = a * b - M * ull(1.L / M * a *\
    \ b);\n\treturn ret + M * (ret < 0) - M * (ret >= (ll)M);\n}\n\null modpow(ull\
    \ b, ull e, ull mod) {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /=\
    \ 2)\n\t\tif (e & 1) ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull\
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
    \treturn l;\n}\n#line 1 \"combi/chromaticNumber.cpp\"\n//#include \"modint/dynamicMontgomeryModInt.cpp\"\
    \n//#include \"numtheory/fastFactorize.cpp\"\n\ntemplate<> uint32_t MontgomeryModInt<123>::mod\
    \ = 0;\ntemplate<> uint32_t MontgomeryModInt<123>::n2 = 0;\ntemplate<> uint32_t\
    \ MontgomeryModInt<123>::r = 0;\nint chromatic_number(vector<vector<bool>> g)\
    \ {\n  const int n = ssize(g);\n\n  mt19937 rng(clock);\n  uniform_int_distribution<int>\
    \ unif(1 << 29, 1 << 30);\n  int p = 4;\n  while(!isPrime(p)) p = unif(rng);\n\
    \  using Mint = MontgomeryModInt<123>;\n  Mint::set_mod(p);\n\n  vector<Mint>\
    \ I(1 << n);\n  I[0] = 1;\n  for(unsigned msk = 1; msk < (1 << n); msk++) {\n\
    \    int v = countr_zero(bit_floor(msk));\n    I[msk] = I[msk ^ (1 << v)];\n \
    \   unsigned msk2 = msk ^ (1 << v);\n    for(int x = 0; x < n; x++)\n      if\
    \ (g[v][x] and (msk2 >> x & 1))\n        msk2 ^= 1 << x;\n    I[msk] += I[msk2];\n\
    \  }\n\n  auto check = [&](int c) {\n    if (c == n) return true;\n    Mint cnt\
    \ = 0;\n    for(unsigned msk = 0; msk < (1 << n); msk++)\n      cnt += I[msk].pow(c)\
    \ * (popcount(msk ^ ((1 << n) - 1)) % 2 == 1 ? -1 : 1);\n    return cnt != 0;\n\
    \  };\n\n  int c = 1;\n  while(!check(c)) c++;\n\n  return c;\n}\n#line 7 \"test/chromatic_number.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector g(n, vector<bool>(n, false));\n  for(int i = 0;\
    \ i < m; i++) {\n    int u, v; cin >> u >> v;\n    g[u][v] = g[v][u] = true;\n\
    \  }\n\n  cout << chromatic_number(g) << '\\n';\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n\
    #include \"../default/t.cpp\"\n#include \"modint/dynamicMontgomeryModInt.cpp\"\
    \n#include \"numtheory/factorize_pollard_rho.cpp\"\n#include \"combi/chromaticNumber.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector g(n, vector<bool>(n, false));\n  for(int i = 0;\
    \ i < m; i++) {\n    int u, v; cin >> u >> v;\n    g[u][v] = g[v][u] = true;\n\
    \  }\n\n  cout << chromatic_number(g) << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - modint/dynamicMontgomeryModInt.cpp
  - numtheory/factorize_pollard_rho.cpp
  - combi/chromaticNumber.cpp
  isVerificationFile: true
  path: test/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2026-01-30 01:25:42+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/chromatic_number.test.cpp
- /verify/test/chromatic_number.test.cpp.html
title: test/chromatic_number.test.cpp
---
