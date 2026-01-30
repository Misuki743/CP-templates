---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: default/ttt.cpp
    title: default/ttt.cpp
  - icon: ':heavy_check_mark:'
    path: geometry/closest_pair.cpp
    title: geometry/closest_pair.cpp
  - icon: ':question:'
    path: geometry/point.cpp
    title: geometry/point.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/closest_pair
    links:
    - https://judge.yosupo.jp/problem/closest_pair
  bundledCode: "#line 1 \"test/closest_pair.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/closest_pair\"\
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
    \ = priority_queue<T, vc<T>, greater<T>>;\ntemplate<typename T> using max_heap\
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
    \    ret[p[i]] = i;\n  return ret;\n}\n\ntemplate<ranges::random_access_range\
    \ rng>\nvi argSort(rng p) {\n  vi id(size(p));\n  iota(id.begin(), id.end(), 0);\n\
    \  ranges::sort(id, {}, [&](int i) { return pair(p[i], i); });\n  return id;\n\
    }\n\ntemplate<ranges::random_access_range rng, class T = ranges::range_value_t<rng>,\
    \ typename F>\nrequires invocable<F, T&>\nvi argSort(rng p, F proj) {\n  vi id(size(p));\n\
    \  iota(id.begin(), id.end(), 0);\n  ranges::sort(id, {}, [&](int i) { return\
    \ pair(proj(p[i]), i); });\n  return id;\n}\n\ntemplate<bool directed>\nvvi read_graph(int\
    \ n, int m, int base) {\n  vvi g(n);\n  for(int i = 0; i < m; i++) {\n    int\
    \ u, v; cin >> u >> v;\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n\
    \    if constexpr (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n\
    }\n\ntemplate<bool directed>\nvvi adjacency_list(int n, vc<pii> e, int base) {\n\
    \  vvi g(n);\n  for(auto [u, v] : e) {\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n\
    \    if constexpr (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n\
    }\n\ntemplate<class T>\nvoid setBit(T &msk, int bit, bool x) { (msk &= ~(T(1)\
    \ << bit)) |= T(x) << bit; }\ntemplate<class T> void onBit(T &msk, int bit) {\
    \ setBit(msk, bit, true); }\ntemplate<class T> void offBit(T &msk, int bit) {\
    \ setBit(msk, bit, false); }\ntemplate<class T> void flipBit(T &msk, int bit)\
    \ { msk ^= T(1) << bit; }\ntemplate<class T> bool getBit(T msk, int bit) { return\
    \ msk >> bit & T(1); }\n\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b <\
    \ 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\n\ntemplate<class T> bool chmin(T &a, T b) { return\
    \ a > b ? a = b, 1 : 0; }\ntemplate<class T> bool chmax(T &a, T b) { return a\
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"default/ttt.cpp\"\n#define rep(i, a, b) for(int\
    \ i = a; i < (b); ++i)\n#define all(x) begin(x), end(x)\n#define sz(x) (int)(x).size()\n\
    typedef long long ll;\ntypedef pair<int, int> pii;\ntypedef vector<int> vi;\n\
    #line 1 \"geometry/point.cpp\"\n//source: KACTL\n/**\n * Author: Ulf Lundstrom\n\
    \ * Date: 2009-02-26\n * License: CC0\n * Source: My head with inspiration from\
    \ tinyKACTL\n * Description: Class to handle points in the plane.\n *  T can be\
    \ e.g. double or long long. (Avoid int.)\n * Status: Works fine, used a lot\n\
    \ */\n\ntemplate <class T> int sgn(T x) { return (x > 0) - (x < 0); }\ntemplate<class\
    \ T>\nstruct Point {\n  typedef Point P;\n  T x, y;\n  explicit Point(T x=0, T\
    \ y=0) : x(x), y(y) {}\n  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y);\
    \ }\n  bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }\n  P operator+(P\
    \ p) const { return P(x+p.x, y+p.y); }\n  P operator-(P p) const { return P(x-p.x,\
    \ y-p.y); }\n  P operator*(T d) const { return P(x*d, y*d); }\n  P operator/(T\
    \ d) const { return P(x/d, y/d); }\n  T dot(P p) const { return x*p.x + y*p.y;\
    \ }\n  T cross(P p) const { return x*p.y - y*p.x; }\n  T cross(P a, P b) const\
    \ { return (a-*this).cross(b-*this); }\n  T dist2() const { return x*x + y*y;\
    \ }\n  double dist() const { return sqrt((double)dist2()); }\n  // angle to x-axis\
    \ in interval [-pi, pi]\n  double angle() const { return atan2(y, x); }\n  P unit()\
    \ const { return *this/dist(); } // makes dist()=1\n  P perp() const { return\
    \ P(-y, x); } // rotates +90 degrees\n  P normal() const { return perp().unit();\
    \ }\n  // returns point rotated 'a' radians ccw around the origin\n  P rotate(double\
    \ a) const {\n    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }\n  friend ostream&\
    \ operator<<(ostream& os, P p) {\n    return os << \"(\" << p.x << \",\" << p.y\
    \ << \")\"; }\n};\n#line 1 \"geometry/closest_pair.cpp\"\n//source: KACTL\n\n\
    typedef Point<ll> P;\npair<P, P> closest(vector<P> v) {\n  assert(sz(v) > 1);\n\
    \  set<P> S;\n  sort(all(v), [](P a, P b) { return a.y < b.y; });\n  pair<ll,\
    \ pair<P, P>> ret{LLONG_MAX, {P(), P()}};\n  int j = 0;\n  for (P p : v) {\n \
    \   P d{1 + (ll)sqrt(ret.first), 0};\n    while (v[j].y <= p.y - d.x) S.erase(v[j++]);\n\
    \    auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);\n    for (; lo\
    \ != hi; ++lo)\n      ret = min(ret, {(*lo - p).dist2(), {*lo, p}});\n    S.insert(p);\n\
    \  }\n  return ret.second;\n}\n#line 7 \"test/closest_pair.test.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t; cin >> t;\n\
    \  while(t--) {\n    int n; cin >> n;\n    vector<P> pt(n);\n    for(auto &[x,\
    \ y] : pt) cin >> x >> y;\n    \n    auto [p, q] = closest(pt);\n    int i = ranges::find(pt,\
    \ p) - pt.begin();\n    int j = 0;\n    while(j == i or q != pt[j]) j++;\n   \
    \ cout << i << ' ' << j << '\\n';\n  }\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/closest_pair\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../default/ttt.cpp\"\n#include \"../geometry/point.cpp\"\
    \n#include \"../geometry/closest_pair.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int t; cin >> t;\n  while(t--) {\n    int n; cin >> n;\n\
    \    vector<P> pt(n);\n    for(auto &[x, y] : pt) cin >> x >> y;\n    \n    auto\
    \ [p, q] = closest(pt);\n    int i = ranges::find(pt, p) - pt.begin();\n    int\
    \ j = 0;\n    while(j == i or q != pt[j]) j++;\n    cout << i << ' ' << j << '\\\
    n';\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - default/ttt.cpp
  - geometry/point.cpp
  - geometry/closest_pair.cpp
  isVerificationFile: true
  path: test/closest_pair.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:10:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/closest_pair.test.cpp
layout: document
redirect_from:
- /verify/test/closest_pair.test.cpp
- /verify/test/closest_pair.test.cpp.html
title: test/closest_pair.test.cpp
---
