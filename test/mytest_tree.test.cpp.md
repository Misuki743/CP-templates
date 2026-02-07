---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_bit.cpp
    title: enumerate/enumerate_bit.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_label_tree.cpp
    title: enumerate/enumerate_label_tree.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_twelvefold.cpp
    title: enumerate/enumerate_twelvefold.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_unlabel_rooted_tree.cpp
    title: enumerate/enumerate_unlabel_rooted_tree.cpp
  - icon: ':heavy_check_mark:'
    path: tree/prufer_recover.cpp
    title: tree/prufer_recover.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"tree/prufer_recover.cpp\"\n//empty vector\
    \ would be assumed to be n = 2\nvc<pii> prufer_recover(vi prufer_code) {\n  const\
    \ int n = ssize(prufer_code) + 2;\n  assert(prufer_code.empty() or (ranges::min(prufer_code)\
    \ >= 0 and ranges::max(prufer_code) < n));\n  vi d(n, 1);\n  for(int x : prufer_code)\
    \ d[x]++;\n  min_heap<int> leaf;\n  for(int v = 0; v < n; v++)\n    if (d[v] ==\
    \ 1)\n      leaf.emplace(v);\n  vc<pii> edges;\n  for(int x : prufer_code) {\n\
    \    int v = leaf.top(); leaf.pop();\n    edges.emplace_back(v, x);\n    if (--d[x]\
    \ == 1)\n      leaf.emplace(x);\n  }\n  int v = leaf.top(); leaf.pop();\n  edges.emplace_back(v,\
    \ leaf.top());\n  return edges;\n}\n#line 1 \"enumerate/enumerate_bit.cpp\"\n\n\
    template<typename F, typename INT>\nrequires invocable<F, INT>\nvoid enumerate_subset(INT\
    \ msk, F f) {\n  for(INT x = msk; x > 0; x = (x - 1) & msk)\n    f(x);\n  f(0);\n\
    }\n#line 1 \"enumerate/enumerate_twelvefold.cpp\"\n//#include \"enumerate/bit.cpp\"\
    \n\ntemplate<typename F>\nrequires invocable<F, vector<int>>\nvoid enumerate_cartesian_power(int\
    \ n, int k, F f) {\n  assert(min(n, k) >= 0);\n  vector<int> p(k);\n  auto dfs\
    \ = [&](int i, auto &self) -> void {\n    if (i == k) {\n      f(p);\n    } else\
    \ {\n      for(int x = 0; x < n; x++) {\n        p[i] = x;\n        self(i + 1,\
    \ self);\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<int>>\nvoid enumerate_permutation(int n, F f) {\n  assert(n\
    \ >= 0);\n  vector<int> p(n);\n  iota(p.begin(), p.end(), 0);\n  do { f(p); }\
    \ while(next_permutation(p.begin(), p.end()));\n}\n\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<int>>\nvoid enumerate_combination(int n, int k, F f) {\n\
    \  assert(min(n, k) >= 0);\n  vector<int> p;\n  auto dfs = [&](auto &self) ->\
    \ void {\n    if (ssize(p) == k) {\n      f(p);\n    } else {\n      for(int x\
    \ = (p.empty() ? 0 : p.back() + 1); x + k - ssize(p) <= n; x++) {\n        p.emplace_back(x);\n\
    \        self(self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(dfs);\n\
    }\n\ntemplate<typename F>\nrequires invocable<F, vector<int>>\nvoid enumerate_set_partition(int\
    \ n, F f) {\n  assert(n >= 0);\n  vector<int> p;\n  int msk = (1 << n) - 1;\n\
    \  auto dfs = [&](auto &self) -> void {\n    if (msk == 0) {\n      f(p);\n  \
    \  } else {\n      int x = msk & (-msk);\n      msk ^= x;\n      enumerate_subset(msk,\
    \ [&](int sub) {\n        p.emplace_back(sub | x);\n        msk ^= sub;\n    \
    \    self(self);\n        msk ^= sub;\n        p.pop_back();\n      });\n    \
    \  msk ^= x;\n    }\n  };\n  dfs(dfs);\n}\n\ntemplate<typename F>\nrequires invocable<F,\
    \ vector<int>>\nvoid enumerate_multisubset(int n, int sum, F f) {\n  assert(min(n,\
    \ sum) >= 0);\n  vector<int> p(n);\n  auto dfs = [&](int i, auto &self) -> void\
    \ {\n    if (i == n) {\n      if (sum == 0) f(p);\n    } else {\n      for(int\
    \ x = sum; x >= 0; x--) {\n        p[i] = x, sum -= x;\n        self(i + 1, self);\n\
    \        sum += x;\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\ntemplate<typename\
    \ F>\nrequires invocable<F, vector<int>>\nvoid enumerate_integer_partition(int\
    \ n, F f) {\n  assert(n >= 0);\n  vector<int> p;\n  auto dfs = [&](int s, auto\
    \ &self) -> void {\n    if (s == 0) {\n      f(p);\n    } else {\n      for(int\
    \ x = (p.empty() ? s : min(p.back(), s)); x > 0; x--) {\n        p.emplace_back(x);\n\
    \        self(s - x, self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(n,\
    \ dfs);\n}\n#line 1 \"enumerate/enumerate_label_tree.cpp\"\n//#include \"tree/prufer_recover.cpp\"\
    \n//#include \"enumerate/enumerate_bit.cpp\"\n//#include \"enumerate/enumerate_twelvefold.cpp\"\
    \n\ntemplate<typename F>\nrequires invocable<F, vector<vector<int>>>\nvoid enumerate_label_tree(int\
    \ n, F f) {\n  assert(n > 0);\n  if (n == 1) {\n    f(vector<vector<int>>(1));\n\
    \  } else {\n    enumerate_cartesian_power(n, n - 2, [n, f](vector<int> a) {\n\
    \      f(adjacency_list<false>(n, prufer_recover(a), 0));\n    });\n  }\n}\n#line\
    \ 1 \"enumerate/enumerate_unlabel_rooted_tree.cpp\"\n//number of unlabel rooted\
    \ tree (1-based)\n//1, 1, 2, 4, 9,\n//20, 48, 115, 286, 719,\n//1842, 4766, 12486,\
    \ 32973, 87811,\n//235381, 634847, 1721159, 4688676, 12826228,\n//35221832, 97055181,\
    \ 268282855, 743724984, 2067174645\n\n//root is 0\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<vector<int>>>\nvoid enumerate_unlabel_rooted_tree(int n,\
    \ F f) {\n  const int LIM = 25;\n  assert(0 < n and n <= LIM);\n\n  vector hash(1,\
    \ array<int, LIM>{-1});\n  array<int, LIM + 2> st;\n  fill(st.begin(), st.end(),\
    \ INT_MAX);\n  st[0] = -1, st[1] = 0;\n\n  auto size = [&](int id) {\n    int\
    \ r = 1;\n    while(st[r] <= id) r++;\n    return r - 1;\n  };\n\n  for(int m\
    \ = 2; m <= n; m++) {\n    st[m] = ssize(hash);\n    array<int, LIM> h;\n    int\
    \ nxt = 0;\n    auto dfs = [&](int pre_id, int sum, auto &self) -> void {\n  \
    \    if (sum == 0) {\n        h[nxt++] = -1;\n        hash.emplace_back(h);\n\
    \        nxt--;\n      } else {\n        for(int x = min(pre_id, st[sum + 1] -\
    \ 1); x >= 0; x--) {\n          h[nxt++] = x;\n          self(x, sum - size(x),\
    \ self);\n          nxt--;\n        }\n      }\n    };\n    dfs(INT_MAX, m - 1,\
    \ dfs);\n  }\n  st[n + 1] = ssize(hash);\n\n  for(int id = st[n]; id < st[n +\
    \ 1]; id++) {\n    vector<vector<int>> g(n);\n    int nxt = 0;\n    auto dfs =\
    \ [&](int v, int id, auto &self) -> void {\n      if (id == 0) return;\n     \
    \ for(int i = 0; hash[id][i] != -1; i++) {\n        g[v].emplace_back(nxt), g[nxt].emplace_back(v);\n\
    \        self(nxt++, hash[id][i], self);\n      }\n    };\n    dfs(nxt++, id,\
    \ dfs);\n    f(g);\n  }\n}\n#line 1 \"tree/tree.cpp\"\nclass tree {\n  using i32\
    \ = int32_t;\n\n  vc<i32> ord;\n\n  public:\n\n  int n, root;\n  vc<int> p, sz,\
    \ dep, jp;\n\n  tree(vc<pii> e, int _root = 0) : n(size(e) + 1), root(_root) {\n\
    \    vc<i32> d(n), adj(n);\n    for(auto [u, v] : e)\n      d[u]++, d[v]++, adj[u]\
    \ ^= v, adj[v] ^= u;\n    d[root] = 0;\n    calc(d, adj);\n  }\n\n  tree(vi pa)\
    \ : n(size(pa)) {\n    root = ranges::find(pa, -1) - pa.begin();\n    vc<i32>\
    \ d(n), adj(n);\n    for(int v = 0; v < n; v++)\n      if (pa[v] != -1)\n    \
    \    d[v]++, d[pa[v]]++, adj[v] ^= pa[v], adj[pa[v]] ^= v;\n    d[root] = 0;\n\
    \    calc(d, adj);\n  }\n\n  void calc(vc<i32> d, vc<i32> adj) {\n    sz = vi(n,\
    \ 1);\n    p = dep = jp = vi(n);\n\n    ord.reserve(n - 1);\n    for(int i = 0;\
    \ i < n; i++) {\n      int v = i;\n      while(d[v] == 1) {\n        ord.emplace_back(v);\n\
    \        p[v] = adj[v], sz[p[v]] += sz[v];\n        d[v] = 0, d[p[v]]--, adj[p[v]]\
    \ ^= v;\n        v = p[v];\n      }\n    }\n\n    assert(ssize(ord) == n - 1);\n\
    \n    p[root] = jp[root] = root;\n    for(i32 v : ord | views::reverse) {\n  \
    \    dep[v] = dep[p[v]] + 1;\n      if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n\
    \        jp[v] = jp[jp[p[v]]];\n      else\n        jp[v] = p[v];\n    }\n  }\n\
    \n  int jump(int v, int k) {\n    k = min(k, dep[v]);\n    while(k) {\n      if\
    \ (int d = dep[v] - dep[jp[v]]; d <= k)\n        v = jp[v], k -= d;\n      else\n\
    \        v = p[v], k -= 1;\n    }\n    return v;\n  }\n\n  int lca(int u, int\
    \ v) {\n    if (dep[u] < dep[v])\n      swap(u, v);\n    u = jump(u, dep[u] -\
    \ dep[v]);\n    if (u == v) return u;\n    while(p[u] != p[v]) {\n      if (jp[u]\
    \ != jp[v]) u = jp[u], v = jp[v];\n      else u = p[u], v = p[v];\n    }\n   \
    \ return p[u];\n  }\n\n  int kth(int s, int t, int k) {\n    int m = lca(s, t);\n\
    \    if (dep[s] + dep[t] - 2 * dep[m] < k)\n      return -1;\n    else if (dep[s]\
    \ - dep[m] >= k)\n      return jump(s, k);\n    else\n      return jump(t, dep[s]\
    \ + dep[t] - 2 * dep[m] - k);\n  }\n\n  int dis(int u, int v) {\n    return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n  }\n\n  int median(int u, int v, int w) {\n\
    \    return lca(u, v) ^ lca(u, w) ^ lca(v, w);\n  }\n\n  auto centroid() {\n \
    \   array<int, 2> r = {-1, -1};\n    vector<bool> ok(n, true);\n    for(int v\
    \ = 0; v < n; v++) {\n      if (2 * (n - sz[v]) > n)\n        ok[v] = false;\n\
    \      if (v != root and 2 * sz[v] > n)\n        ok[p[v]] = false;\n    }\n  \
    \  for(int v = 0; v < n; v++)\n      if (ok[v])\n        r[1] = v, swap(r[0],\
    \ r[1]);\n    return r;\n  }\n};\n#line 10 \"test/mytest_tree.test.cpp\"\n\nvoid\
    \ check(vector<vector<int>> g, int root) {\n  const int n = ssize(g);\n  vector<int>\
    \ p(n, root), sz(n, 1), dep(n);\n  auto dfs = [&](int v, auto &self) -> void {\n\
    \    for(int x : g[v]) {\n      if (x == p[v]) continue;\n      p[x] = v, dep[x]\
    \ = dep[v] + 1;\n      self(x, self);\n      sz[v] += sz[x];\n    }\n  };\n  dfs(root,\
    \ dfs);\n\n  vector<pii> e;\n  for(int u = 0; u < n; u++)\n    for(int v : g[u])\n\
    \      if (u < v)\n        e.emplace_back(u, v);\n\n  tree T(e, root);\n  assert(tie(T.p,\
    \ T.sz, T.dep) == tie(p, sz, dep));\n}\n\nauto random_relabel(vector<vector<int>>\
    \ g) {\n  mt19937 rng(clock);\n  const int n = ssize(g);\n  vector<int> p(n);\n\
    \  iota(p.begin(), p.end(), 0);\n  shuffle(p.begin(), p.end(), rng);\n  vector<vector<int>>\
    \ g2(n);\n  for(int u = 0; u < n; u++)\n    for(int v : g[u])\n      g2[p[u]].eb(p[v]);\n\
    \  return pair(g2, p[0]);\n}\n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n\
    \  cout << a + b << '\\n';\n}\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  mt19937 rng(clock);\n\n  for(int n = 1; n <= 7; n++) {\n\
    \    enumerate_label_tree(n, [&](vector<vector<int>> g) {\n      for(int root\
    \ = 0; root < n; root++)\n        check(g, root);\n    });\n  }\n\n  for(int n\
    \ = 1; n <= 15; n++) {\n    enumerate_unlabel_rooted_tree(n, [&](vector<vector<int>>\
    \ g) {\n      check(g, 0);\n      auto [gp, root] = random_relabel(g);\n     \
    \ check(gp, root);\n    });\n  }\n\n  //path\n  for(int n = 1; n <= 100; n++)\
    \ {\n    vector<vector<int>> g(n);\n    for(int i = 1; i < n; i++)\n      g[i].emplace_back(i\
    \ - 1), g[i - 1].emplace_back(i);\n    check(g, 0);\n    check(g, n / 2);\n  \
    \  check(g, n - 1);\n    auto [gp, root] = random_relabel(g);\n    check(gp, root);\n\
    \  }\n\n  //star\n  for(int n = 2; n <= 100; n++) {\n    for(int root : {0, n\
    \ / 2, n - 1}) {\n      vector<vector<int>> g(n);\n      for(int i = 0; i < n;\
    \ i++)\n        if (i != root)\n          g[root].emplace_back(i), g[i].emplace_back(root);\n\
    \      check(g, root);\n    }\n  }\n\n  //almost path\n  for(int tc = 0; tc <\
    \ 30; tc++) {\n    int n = 500;\n    vector<vector<int>> g(n);\n    for(int v\
    \ = 1; v < n; v++) {\n      int x = rng() % min(v, 5);\n      g[v].emplace_back(x),\
    \ g[x].emplace_back(v);\n    }\n    check(g, 0);\n    auto [gp, root] = random_relabel(g);\n\
    \    check(gp, root);\n  }\n\n  a_plus_b();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../tree/prufer_recover.cpp\"\n#include \"../enumerate/enumerate_bit.cpp\"\
    \n#include \"../enumerate/enumerate_twelvefold.cpp\"\n#include \"../enumerate/enumerate_label_tree.cpp\"\
    \n#include \"../enumerate/enumerate_unlabel_rooted_tree.cpp\"\n#include \"../tree/tree.cpp\"\
    \n\nvoid check(vector<vector<int>> g, int root) {\n  const int n = ssize(g);\n\
    \  vector<int> p(n, root), sz(n, 1), dep(n);\n  auto dfs = [&](int v, auto &self)\
    \ -> void {\n    for(int x : g[v]) {\n      if (x == p[v]) continue;\n      p[x]\
    \ = v, dep[x] = dep[v] + 1;\n      self(x, self);\n      sz[v] += sz[x];\n   \
    \ }\n  };\n  dfs(root, dfs);\n\n  vector<pii> e;\n  for(int u = 0; u < n; u++)\n\
    \    for(int v : g[u])\n      if (u < v)\n        e.emplace_back(u, v);\n\n  tree\
    \ T(e, root);\n  assert(tie(T.p, T.sz, T.dep) == tie(p, sz, dep));\n}\n\nauto\
    \ random_relabel(vector<vector<int>> g) {\n  mt19937 rng(clock);\n  const int\
    \ n = ssize(g);\n  vector<int> p(n);\n  iota(p.begin(), p.end(), 0);\n  shuffle(p.begin(),\
    \ p.end(), rng);\n  vector<vector<int>> g2(n);\n  for(int u = 0; u < n; u++)\n\
    \    for(int v : g[u])\n      g2[p[u]].eb(p[v]);\n  return pair(g2, p[0]);\n}\n\
    \nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n}\n\
    \nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  mt19937 rng(clock);\n\
    \n  for(int n = 1; n <= 7; n++) {\n    enumerate_label_tree(n, [&](vector<vector<int>>\
    \ g) {\n      for(int root = 0; root < n; root++)\n        check(g, root);\n \
    \   });\n  }\n\n  for(int n = 1; n <= 15; n++) {\n    enumerate_unlabel_rooted_tree(n,\
    \ [&](vector<vector<int>> g) {\n      check(g, 0);\n      auto [gp, root] = random_relabel(g);\n\
    \      check(gp, root);\n    });\n  }\n\n  //path\n  for(int n = 1; n <= 100;\
    \ n++) {\n    vector<vector<int>> g(n);\n    for(int i = 1; i < n; i++)\n    \
    \  g[i].emplace_back(i - 1), g[i - 1].emplace_back(i);\n    check(g, 0);\n   \
    \ check(g, n / 2);\n    check(g, n - 1);\n    auto [gp, root] = random_relabel(g);\n\
    \    check(gp, root);\n  }\n\n  //star\n  for(int n = 2; n <= 100; n++) {\n  \
    \  for(int root : {0, n / 2, n - 1}) {\n      vector<vector<int>> g(n);\n    \
    \  for(int i = 0; i < n; i++)\n        if (i != root)\n          g[root].emplace_back(i),\
    \ g[i].emplace_back(root);\n      check(g, root);\n    }\n  }\n\n  //almost path\n\
    \  for(int tc = 0; tc < 30; tc++) {\n    int n = 500;\n    vector<vector<int>>\
    \ g(n);\n    for(int v = 1; v < n; v++) {\n      int x = rng() % min(v, 5);\n\
    \      g[v].emplace_back(x), g[x].emplace_back(v);\n    }\n    check(g, 0);\n\
    \    auto [gp, root] = random_relabel(g);\n    check(gp, root);\n  }\n\n  a_plus_b();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - tree/prufer_recover.cpp
  - enumerate/enumerate_bit.cpp
  - enumerate/enumerate_twelvefold.cpp
  - enumerate/enumerate_label_tree.cpp
  - enumerate/enumerate_unlabel_rooted_tree.cpp
  - tree/tree.cpp
  isVerificationFile: true
  path: test/mytest_tree.test.cpp
  requiredBy: []
  timestamp: '2026-02-07 19:26:24+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest_tree.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_tree.test.cpp
- /verify/test/mytest_tree.test.cpp.html
title: test/mytest_tree.test.cpp
---
