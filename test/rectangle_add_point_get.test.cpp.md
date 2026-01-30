---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/fenwickTree2D.cpp
    title: ds/fenwickTree2D.cpp
  - icon: ':x:'
    path: ds_problem/rectangleAddPointGet.cpp
    title: ds_problem/rectangleAddPointGet.cpp
  - icon: ':x:'
    path: misc/compression.cpp
    title: compression
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_add_point_get
    links:
    - https://judge.yosupo.jp/problem/rectangle_add_point_get
  bundledCode: "#line 1 \"test/rectangle_add_point_get.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\n\n#line 1 \"default/t.cpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n#include <bit>\n#include\
    \ <compare>\n#include <concepts>\n#include <numbers>\n#include <ranges>\n#include\
    \ <span>\n\n#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128)\
    \ * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\ntemplate<size_t I = 0, typename... args>\nostream& print_tuple(ostream&\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"ds/fenwickTree2D.cpp\"\n//source: KACTL\n\
    \n/**\n * Author: Lukas Polacek\n * Date: 2009-10-30\n * License: CC0\n * Source:\
    \ folklore/TopCoder\n * Description: Computes partial sums a[0] + a[1] + ... +\
    \ a[pos - 1], and updates single elements a[i],\n * taking the difference between\
    \ the old and new value.\n * Time: Both operations are $O(\\log N)$.\n * Status:\
    \ Stress-tested\n */\ntemplate<class T>\nstruct FT {\n\tvector<T> s;\n\tFT(int\
    \ n) : s(n) {}\n\tvoid update(int pos, T dif) { // a[pos] += dif\n\t\tfor (; pos\
    \ < ssize(s); pos |= pos + 1) s[pos] += dif;\n\t}\n\tT query(int pos) { // sum\
    \ of values in [0, pos)\n\t\tT res = 0;\n\t\tfor (; pos > 0; pos &= pos - 1) res\
    \ += s[pos-1];\n\t\treturn res;\n\t}\n\tint lower_bound(T sum) {// min pos st\
    \ sum of [0, pos] >= sum\n\t\t// Returns n if no sum is >= sum, or -1 if empty\
    \ sum is.\n\t\tif (sum <= 0) return -1;\n\t\tint pos = 0;\n\t\tfor (int pw = 1\
    \ << 25; pw; pw >>= 1) {\n\t\t\tif (pos + pw <= ssize(s) && s[pos + pw-1] < sum)\n\
    \t\t\t\tpos += pw, sum -= s[pos-1];\n\t\t}\n\t\treturn pos;\n\t}\n};\n\n/**\n\
    \ * Author: Simon Lindholm\n * Date: 2017-05-11\n * License: CC0\n * Source: folklore\n\
    \ * Description: Computes sums a[i,j] for all i<I, j<J, and increases single elements\
    \ a[i,j].\n *  Requires that the elements to be updated are known in advance (call\
    \ fakeUpdate() before init()).\n * Time: $O(\\log^2 N)$. (Use persistent segment\
    \ trees for $O(\\log N)$.)\n * Status: stress-tested\n */\ntemplate<class T1,\
    \ class T2>\nstruct FT2 {\n\tvector<vector<T1>> ys; vector<FT<T2>> ft;\n\tFT2(int\
    \ limx) : ys(limx) {}\n\tvoid fakeUpdate(int x, T1 y) {\n\t\tfor (; x < ssize(ys);\
    \ x |= x + 1) ys[x].push_back(y);\n\t}\n\tvoid init() {\n\t\tfor (vector<T1>&\
    \ v : ys) ranges::sort(v), ft.emplace_back(ssize(v));\n\t}\n\tint ind(int x, T1\
    \ y) {\n\t\treturn (int)(ranges::lower_bound(ys[x], y) - ys[x].begin()); }\n\t\
    void update(int x, T1 y, T2 dif) {\n\t\tfor (; x < ssize(ys); x |= x + 1)\n\t\t\
    \tft[x].update(ind(x, y), dif);\n\t}\n\tT2 query(int x, T1 y) {\n\t\tT2 sum =\
    \ 0;\n\t\tfor (; x; x &= x - 1)\n\t\t\tsum += ft[x-1].query(ind(x-1, y));\n\t\t\
    return sum;\n\t}\n};\n#line 1 \"misc/compression.cpp\"\ntemplate<class T, bool\
    \ duplicate = false>\nstruct compression {\n  vector<int> ord;\n  vector<T> val;\n\
    \n  compression(vector<T> &init) : val(init) { precompute(); }\n  compression(int\
    \ size = 0) { val.reserve(size); }\n\n  void precompute() {\n    vector<T> init\
    \ = val;\n    ord.resize(ssize(val));\n    ranges::sort(val);\n    if constexpr\
    \ (duplicate) {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(),\
    \ cnt.end(), 0);\n      for(int i = 0; i < ssize(ord); i++)\n        ord[i] =\
    \ cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ ranges::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val);\
    \ }\n  template<ranges::range rng, class proj = identity>\n  void mapping(rng\
    \ &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<ranges::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n#line 1 \"ds_problem/rectangleAddPointGet.cpp\"\
    \n//#include<ds/fenwickTree2D.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T1, class T2>\nvector<T2> rectAddPointGet(vector<tuple<T1, T1, T1, T1, T2>>\
    \ &rect, vector<array<T1, 2>> &query, vector<int> updT) {\n  compression<T1> xs(ssize(query));\n\
    \  xs.insert(query, [](auto &x) { return x[0]; });\n  xs.precompute();\n  xs.mapping(query,\
    \ [](auto &x) -> T1& { return x[0]; });\n  xs.mapping(rect, [](auto &x) -> T1&\
    \ { return get<0>(x); });\n  xs.mapping(rect, [](auto &x) -> T1& { return get<1>(x);\
    \ });\n\n  FT2<T1, T2> bit(xs.size());\n  for(auto &[l, r, d, u, w] : rect) {\n\
    \    bit.fakeUpdate(l, d);\n    bit.fakeUpdate(r, u);\n    bit.fakeUpdate(l, u);\n\
    \    bit.fakeUpdate(r, d);\n  }\n  bit.init();\n\n  vector<T2> ans(ssize(query));\n\
    \  for(int i = 0, ptr = 0; auto &[x, y] : query) {\n    while(ptr < ssize(rect)\
    \ and updT[ptr] <= i) {\n      auto [l, r, d, u, w] = rect[ptr++];\n      bit.update(l,\
    \ d, w);\n      bit.update(r, u, w);\n      bit.update(l, u, -w);\n      bit.update(r,\
    \ d, -w);\n    }\n    ans[i++] = bit.query(x + 1, y + 1);\n  }\n\n  return ans;\n\
    }\n#line 7 \"test/rectangle_add_point_get.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<tuple<int, int, int,\
    \ int, ll>> rect(n);\n  for(auto &[l, r, d, u, w] : rect)\n    cin >> l >> d >>\
    \ r >> u >> w;\n  vector<array<int, 2>> query;\n  vector<int> updT(n, 0);\n  while(q--)\
    \ {\n    int op; cin >> op;\n    if (op == 0) {\n      int l, d, r, u; cin >>\
    \ l >> d >> r >> u;\n      ll w; cin >> w;\n      rect.emplace_back(l, r, d, u,\
    \ w);\n      updT.emplace_back(ssize(query));\n    } else if (op == 1) {\n   \
    \   int x, y; cin >> x >> y;\n      query.push_back({x, y});\n    }\n  }\n\n \
    \ for(ll ans : rectAddPointGet<int, ll>(rect, query, updT))\n    cout << ans <<\
    \ '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/fenwickTree2D.cpp\"\n#include\
    \ \"../misc/compression.cpp\"\n#include \"../ds_problem/rectangleAddPointGet.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<tuple<int, int, int, int, ll>> rect(n);\n  for(auto\
    \ &[l, r, d, u, w] : rect)\n    cin >> l >> d >> r >> u >> w;\n  vector<array<int,\
    \ 2>> query;\n  vector<int> updT(n, 0);\n  while(q--) {\n    int op; cin >> op;\n\
    \    if (op == 0) {\n      int l, d, r, u; cin >> l >> d >> r >> u;\n      ll\
    \ w; cin >> w;\n      rect.emplace_back(l, r, d, u, w);\n      updT.emplace_back(ssize(query));\n\
    \    } else if (op == 1) {\n      int x, y; cin >> x >> y;\n      query.push_back({x,\
    \ y});\n    }\n  }\n\n  for(ll ans : rectAddPointGet<int, ll>(rect, query, updT))\n\
    \    cout << ans << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/fenwickTree2D.cpp
  - misc/compression.cpp
  - ds_problem/rectangleAddPointGet.cpp
  isVerificationFile: true
  path: test/rectangle_add_point_get.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:10:37+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/rectangle_add_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/rectangle_add_point_get.test.cpp
- /verify/test/rectangle_add_point_get.test.cpp.html
title: test/rectangle_add_point_get.test.cpp
---
