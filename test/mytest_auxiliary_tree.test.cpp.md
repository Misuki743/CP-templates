---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/RMQ.cpp
    title: ds/RMQ.cpp
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
    path: tree/LCA.cpp
    title: tree/LCA.cpp
  - icon: ':heavy_check_mark:'
    path: tree/auxiliary_tree.cpp
    title: tree/auxiliary_tree.cpp
  - icon: ':heavy_check_mark:'
    path: tree/prufer_recover.cpp
    title: tree/prufer_recover.cpp
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
  bundledCode: "#line 1 \"test/mytest_auxiliary_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"default/t.cpp\"\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <variant>\n#include <bit>\n#include <compare>\n\
    #include <concepts>\n#include <numbers>\n#include <ranges>\n#include <span>\n\n\
    #define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__)\
    \ - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define pb push_back\n#define\
    \ eb emplace_back\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ dfs);\n    f(g);\n  }\n}\n#line 1 \"ds/RMQ.cpp\"\ntemplate<class T>\nstruct\
    \ RMQ {\n  uint64_t size;\n  vector<T> base;\n  vector<vector<T>> table;\n  vector<uint32_t>\
    \ msk;\n\n  static const int lgw = 5;\n  static const int w = 1 << lgw;\n  RMQ(vector<T>\
    \ _base) : size(ssize(_base)), base(_base), msk(size) {\n    msk.back() = 1;\n\
    \    for(int i = size - 2; i >= 0; i--) {\n      msk[i] = msk[i + 1] << 1;\n \
    \     while(msk[i] != 0 and base[i + countr_zero(msk[i])] >= base[i])\n      \
    \  msk[i] ^= 1u << countr_zero(msk[i]);\n      msk[i] |= 1u;\n    }\n\n    table\
    \ = vector(bit_width(size >> lgw), vector<T>(size >> lgw));\n    if (!table.empty())\n\
    \      for(uint64_t i = 0; i + w <= size; i += w)\n        table[0][i >> lgw]\
    \ = base[i + bit_width(msk[i]) - 1];\n    for(int i = 1; i < ssize(table); i++)\n\
    \      for(uint64_t j = 0; j < (size >> lgw); j++)\n        if (j + (1 << (i -\
    \ 1)) < (size >> lgw))\n          table[i][j] = min(table[i - 1][j], table[i -\
    \ 1][j + (1 << (i - 1))]);\n        else\n          table[i][j] = table[i - 1][j];\n\
    \  }\n\n  T query(int l, int r) {\n    if (l >= r) {\n      return numeric_limits<T>::max();\n\
    \    } else if (r - l <= w) {\n      return base[l + bit_width(msk[l] & (~0u >>\
    \ (w - (r - l)))) - 1];\n    } else {\n      T ret = min(query(l, l + w), query(r\
    \ - w, r));\n      l = (l + w) >> lgw, r >>= lgw;\n      if (l == r) return ret;\n\
    \      int range = bit_width((unsigned)(r - l)) - 1;\n      return min({ret, table[range][l],\
    \ table[range][r - (1 << range)]});\n    }\n  }\n};\n#line 1 \"tree/LCA.cpp\"\n\
    //#include \"ds/RMQ.cpp\"\n\nstruct LCA {\n  vi dep, tin, tout, mp;\n  RMQ<int>\
    \ rmq;\n\n  vi precomp(vc<pii> &e, int root) {\n    const int n = ssize(e) + 1;\n\
    \n    dep = tin = tout = mp = vi(n);\n\n    vi sz(n, 1), p(n), ord;\n    {\n \
    \     vi adj(n), d(n);\n      for(auto &[u, v] : e)\n        adj[u] ^= v, adj[v]\
    \ ^= u, d[u]++, d[v]++;\n\n      d[root] = 0, p[root] = root;\n      ord.reserve(n\
    \ - 1);\n      for(int i = 0; i < n; i++) {\n        int v = i;\n        while(d[v]\
    \ == 1) {\n          ord.emplace_back(v);\n          p[v] = adj[v], sz[p[v]] +=\
    \ sz[v];\n          d[v] = 0, d[p[v]]--, adj[p[v]] ^= v;\n          v = p[v];\n\
    \        }\n      }\n    }\n\n    vi dfn(n);\n    {\n      vi nxt(n, 1);\n   \
    \   for(int v : ord | views::reverse) {\n        dfn[v] = nxt[p[v]], nxt[p[v]]\
    \ += sz[v];\n        nxt[v] = dfn[v] + 1;\n        dep[v] = dep[p[v]] + 1;\n \
    \     }\n      vi().swap(ord);\n      vi().swap(sz);\n    }\n\n    vi init(2 *\
    \ n - 1);\n    {\n      vi dfn_ord = invPerm(std::move(dfn));\n\n      int nxt\
    \ = 0, pre = root;\n      for(int v : dfn_ord) {\n        while(pre != p[v]) {\n\
    \          pre = p[pre], tout[pre] = nxt;\n          init[nxt++] = pre;\n    \
    \    }\n        tin[v] = tout[v] = nxt;\n        init[nxt++] = pre = v;\n    \
    \  }\n\n      while(pre != root) {\n        pre = p[pre], tout[pre] = nxt;\n \
    \       init[nxt++] = pre;\n      }\n    }\n\n    {\n      vi f(n);\n      for(int\
    \ x : dep) f[x]++;\n      pSum(f);\n\n      vi rank(n);\n      for(int v = 0;\
    \ v < n; v++) {\n        rank[v] = --f[dep[v]];\n        mp[rank[v]] = v;\n  \
    \    }\n      for(int &v : init) v = rank[v];\n    }\n\n    return init;\n  }\n\
    \n  LCA(vc<pii> e, int root = 0) : rmq(precomp(e, root)) {}\n\n  int lca(int u,\
    \ int v) {\n    if (tin[u] > tin[v]) swap(u, v);\n    return mp[rmq.query(tin[u],\
    \ tout[v] + 1)];\n  }\n\n  int dis(int u, int v) {\n    return dep[u] + dep[v]\
    \ - 2 * dep[lca(u, v)];\n  }\n\n  bool is_ancestor_of(int u, int v) {\n    return\
    \ tin[u] <= tin[v] and tout[v] <= tout[u];\n  }\n};\n#line 1 \"tree/auxiliary_tree.cpp\"\
    \n//#include \"ds/RMQ.cpp\"\n//#include \"tree/LCA.cpp\"\n\nstruct auxiliary_tree\
    \ {\n  LCA lca;\n\n  auxiliary_tree(vc<pii> e, int root = 0) : lca(e, root) {}\n\
    \n  auto induced_tree(vi vs) {\n    const int P = 10;\n\n    auto proj = [&](int\
    \ v) { return lca.tin[v]; };\n    if (ssize(vs) < (1 << P) / P) {\n      ranges::sort(vs,\
    \ {}, proj);\n    } else {\n      int mx = proj(ranges::max(vs, {}, proj));\n\
    \      for(int i = 0; mx > 0; i++, mx >>= P){\n        array<int, (1 << P) + 1>\
    \ f = {};\n        for(int v : vs)\n          f[(proj(v) >> (i * P) & ((1 << P)\
    \ - 1)) + 1]++;\n        pSum(f);\n        vi nxt(size(vs));\n        for(int\
    \ v : vs)\n          nxt[f[proj(v) >> (i * P) & ((1 << P) - 1)]++] = v;\n    \
    \    vs.swap(nxt);\n      }\n    }\n\n    vi s, old_id;\n    vc<bool> is_critical_node;\n\
    \    auto push_new_vertex = [&](int v, bool critical = true) {\n      s.emplace_back(ssize(old_id));\n\
    \      old_id.emplace_back(v);\n      is_critical_node.emplace_back(critical);\n\
    \    };\n    \n    if (int v = lca.lca(vs[0], vs.back()); v != vs[0])\n      push_new_vertex(v,\
    \ false);\n\n    vc<pii> e;\n    for(int v : vs) {\n      if (s.empty() or lca.is_ancestor_of(old_id[s.back()],\
    \ v)) {\n        push_new_vertex(v);\n      } else {\n        int last_pop = -1;\n\
    \        do {\n          int j = s.back(); s.pop_back();\n          if (last_pop\
    \ != -1)\n            e.emplace_back(j, last_pop);\n          last_pop = j;\n\
    \        } while(!lca.is_ancestor_of(old_id[s.back()], v));\n\n        if (int\
    \ x = lca.lca(old_id[last_pop], v); x != old_id[s.back()])\n          push_new_vertex(x,\
    \ false);\n        e.emplace_back(s.back(), last_pop);\n\n        push_new_vertex(v);\n\
    \      }\n    }\n\n    for(int i = 1; i < ssize(s); i++)\n      e.emplace_back(s[i\
    \ - 1], s[i]);\n\n    return tuple(e, old_id, is_critical_node);\n  }\n};\n#line\
    \ 12 \"test/mytest_auxiliary_tree.test.cpp\"\n\nauto auxiliary_tree_brute_force(vvi\
    \ g, vi vs, int root = 0) {\n\n  vc<bool> in_vs(size(g), false);\n  for(int v\
    \ : vs) in_vs[v] = true;\n\n  vi old_id;\n  vc<pii> e;\n  vc<bool> is_critical_node;\n\
    \  auto dfs = [&](int v, int p, auto &self) -> int {\n    vi head;\n    for(int\
    \ x : g[v]) {\n      if (x == p) continue;\n      int y = self(x, v, self);\n\
    \      if (y != -1) head.eb(y);\n    }\n\n    if (!in_vs[v] and ssize(head) <=\
    \ 1)\n      return head.empty() ? -1 : head[0];\n\n    int i = size(old_id);\n\
    \    old_id.emplace_back(v);\n    is_critical_node.emplace_back(in_vs[v]);\n \
    \   for(int j : head)\n      e.emplace_back(i, j);\n    return i;\n  };\n\n  dfs(root,\
    \ -1, dfs);\n\n  return tuple(e, old_id, is_critical_node);\n}\n\nvoid check(vector<vector<int>>\
    \ g, int root) {\n  vc<pii> e;\n  for(int u = 0; u < ssize(g); u++)\n    for(int\
    \ v : g[u])\n      if (u < v)\n        e.emplace_back(u, v);\n\n  auxiliary_tree\
    \ aux(e, root);\n  auto check2 = [&](vi vs) {\n    auto [ep, old_id, crit] = aux.induced_tree(vs);\n\
    \    auto [ep2, old_id2, crit2] = auxiliary_tree_brute_force(g, vs, root);\n\n\
    \    assert(ssize(old_id) == ssize(old_id2));\n    assert(set(old_id.begin(),\
    \ old_id.end()) ==\n           set(old_id2.begin(), old_id2.end()));\n\n    vi\
    \ val = old_id;\n    ranges::sort(val);\n    vi mp(size(g), -1);\n    for(int\
    \ i = 0; i < ssize(val); i++)\n      mp[val[i]] = i;\n\n    {\n      vi p(size(old_id));\n\
    \      for(int i = 0; i < ssize(p); i++)\n        p[i] = mp[old_id[i]];\n    \
    \  for(auto &[u, v] : ep)\n        u = p[u], v = p[v];\n      vi tmp(size(old_id));\n\
    \      for(int i = 0; i < ssize(p); i++)\n        tmp[p[i]] = old_id[i];\n   \
    \   old_id.swap(tmp);\n      vc<bool> tmp2(size(old_id));\n      for(int i = 0;\
    \ i < ssize(p); i++)\n        tmp2[p[i]] = crit[i];\n      crit.swap(tmp2);\n\
    \    }\n\n    {\n      vi p(size(old_id2));\n      for(int i = 0; i < ssize(p);\
    \ i++)\n        p[i] = mp[old_id2[i]];\n      for(auto &[u, v] : ep2)\n      \
    \  u = p[u], v = p[v];\n      vi tmp(size(old_id2));\n      for(int i = 0; i <\
    \ ssize(p); i++)\n        tmp[p[i]] = old_id2[i];\n      old_id2.swap(tmp);\n\
    \      vc<bool> tmp2(size(old_id2));\n      for(int i = 0; i < ssize(p); i++)\n\
    \        tmp2[p[i]] = crit2[i];\n      crit2.swap(tmp2);\n    }\n\n    ranges::sort(ep);\n\
    \    ranges::sort(ep2);\n\n    assert(old_id == old_id2);\n    assert(ep == ep2);\n\
    \    assert(crit == crit2);\n  };\n\n  mt19937 rng(clock);\n  const int n = ssize(g);\n\
    \  if (ssize(g) <= 15) {\n    for(int msk = 1; msk < (1 << n); msk++) {\n    \
    \  vi vs;\n      for(int i = 0; i < n; i++)\n        if (msk >> i & 1)\n     \
    \     vs.eb(i);\n      shuffle(vs.begin(), vs.end(), rng);\n      check2(vs);\n\
    \    }\n  } else {\n    for(int sz = 1; sz <= n; sz <<= 1) {\n      set<int> s;\n\
    \      while(ssize(s) != sz)\n        s.insert(rng() % n);\n      vi vs;\n   \
    \   for(int x : s) vs.eb(x);\n      shuffle(vs.begin(), vs.end(), rng);\n    \
    \  check2(vs);\n    }\n  }\n}\n\nauto random_relabel(vector<vector<int>> g) {\n\
    \  mt19937 rng(clock);\n  const int n = ssize(g);\n  vector<int> p(n);\n  iota(p.begin(),\
    \ p.end(), 0);\n  shuffle(p.begin(), p.end(), rng);\n  vector<vector<int>> g2(n);\n\
    \  for(int u = 0; u < n; u++)\n    for(int v : g[u])\n      g2[p[u]].eb(p[v]);\n\
    \  return g2;\n}\n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a\
    \ + b << '\\n';\n}\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  mt19937 rng(clock);\n\n  for(int n = 1; n <= 6; n++) {\n    enumerate_label_tree(n,\
    \ [&](vector<vector<int>> g) {\n      for(int r = 0; r < n; r++)\n        check(g,\
    \ r);\n    });\n  }\n\n  for(int n = 7; n <= 8; n++) {\n    enumerate_unlabel_rooted_tree(n,\
    \ [&](vector<vector<int>> g) {\n      for(int r = 0; r < n; r++)\n        check(g,\
    \ r);\n      g = random_relabel(g);\n      for(int r = 0; r < n; r++)\n      \
    \  check(g, r);\n    });\n  }\n\n  //path\n  for(int n = 1; n <= 100; n += 2)\
    \ {\n    vector<vector<int>> g(n);\n    for(int i = 1; i < n; i++)\n      g[i].emplace_back(i\
    \ - 1), g[i - 1].emplace_back(i);\n    check(g, 0);\n    check(random_relabel(g),\
    \ rng() % n);\n  }\n\n  //star\n  for(int n = 2; n <= 100; n += 2) {\n    for(int\
    \ root : {0, n / 2, n - 1}) {\n      vector<vector<int>> g(n);\n      for(int\
    \ i = 0; i < n; i++)\n        if (i != root)\n          g[root].emplace_back(i),\
    \ g[i].emplace_back(root);\n      check(g, root);\n      check(g, root == 0);\n\
    \    }\n  }\n\n  //almost path\n  for(int tc = 0; tc < 30; tc++) {\n    int n\
    \ = 500;\n    vector<vector<int>> g(n);\n    for(int v = 1; v < n; v++) {\n  \
    \    int x = rng() % min(v, 5);\n      g[v].emplace_back(x), g[x].emplace_back(v);\n\
    \    }\n    for(int r : {0, n / 2, n - 1})\n      check(g, r);\n    g = random_relabel(g);\n\
    \    for(int r : {0, n / 2, n - 1})\n      check(g, r);\n  }\n\n  a_plus_b();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../tree/prufer_recover.cpp\"\n#include \"../enumerate/enumerate_bit.cpp\"\
    \n#include \"../enumerate/enumerate_twelvefold.cpp\"\n#include \"../enumerate/enumerate_label_tree.cpp\"\
    \n#include \"../enumerate/enumerate_unlabel_rooted_tree.cpp\"\n#include \"../ds/RMQ.cpp\"\
    \n#include \"../tree/LCA.cpp\"\n#include \"../tree/auxiliary_tree.cpp\"\n\nauto\
    \ auxiliary_tree_brute_force(vvi g, vi vs, int root = 0) {\n\n  vc<bool> in_vs(size(g),\
    \ false);\n  for(int v : vs) in_vs[v] = true;\n\n  vi old_id;\n  vc<pii> e;\n\
    \  vc<bool> is_critical_node;\n  auto dfs = [&](int v, int p, auto &self) -> int\
    \ {\n    vi head;\n    for(int x : g[v]) {\n      if (x == p) continue;\n    \
    \  int y = self(x, v, self);\n      if (y != -1) head.eb(y);\n    }\n\n    if\
    \ (!in_vs[v] and ssize(head) <= 1)\n      return head.empty() ? -1 : head[0];\n\
    \n    int i = size(old_id);\n    old_id.emplace_back(v);\n    is_critical_node.emplace_back(in_vs[v]);\n\
    \    for(int j : head)\n      e.emplace_back(i, j);\n    return i;\n  };\n\n \
    \ dfs(root, -1, dfs);\n\n  return tuple(e, old_id, is_critical_node);\n}\n\nvoid\
    \ check(vector<vector<int>> g, int root) {\n  vc<pii> e;\n  for(int u = 0; u <\
    \ ssize(g); u++)\n    for(int v : g[u])\n      if (u < v)\n        e.emplace_back(u,\
    \ v);\n\n  auxiliary_tree aux(e, root);\n  auto check2 = [&](vi vs) {\n    auto\
    \ [ep, old_id, crit] = aux.induced_tree(vs);\n    auto [ep2, old_id2, crit2] =\
    \ auxiliary_tree_brute_force(g, vs, root);\n\n    assert(ssize(old_id) == ssize(old_id2));\n\
    \    assert(set(old_id.begin(), old_id.end()) ==\n           set(old_id2.begin(),\
    \ old_id2.end()));\n\n    vi val = old_id;\n    ranges::sort(val);\n    vi mp(size(g),\
    \ -1);\n    for(int i = 0; i < ssize(val); i++)\n      mp[val[i]] = i;\n\n   \
    \ {\n      vi p(size(old_id));\n      for(int i = 0; i < ssize(p); i++)\n    \
    \    p[i] = mp[old_id[i]];\n      for(auto &[u, v] : ep)\n        u = p[u], v\
    \ = p[v];\n      vi tmp(size(old_id));\n      for(int i = 0; i < ssize(p); i++)\n\
    \        tmp[p[i]] = old_id[i];\n      old_id.swap(tmp);\n      vc<bool> tmp2(size(old_id));\n\
    \      for(int i = 0; i < ssize(p); i++)\n        tmp2[p[i]] = crit[i];\n    \
    \  crit.swap(tmp2);\n    }\n\n    {\n      vi p(size(old_id2));\n      for(int\
    \ i = 0; i < ssize(p); i++)\n        p[i] = mp[old_id2[i]];\n      for(auto &[u,\
    \ v] : ep2)\n        u = p[u], v = p[v];\n      vi tmp(size(old_id2));\n     \
    \ for(int i = 0; i < ssize(p); i++)\n        tmp[p[i]] = old_id2[i];\n      old_id2.swap(tmp);\n\
    \      vc<bool> tmp2(size(old_id2));\n      for(int i = 0; i < ssize(p); i++)\n\
    \        tmp2[p[i]] = crit2[i];\n      crit2.swap(tmp2);\n    }\n\n    ranges::sort(ep);\n\
    \    ranges::sort(ep2);\n\n    assert(old_id == old_id2);\n    assert(ep == ep2);\n\
    \    assert(crit == crit2);\n  };\n\n  mt19937 rng(clock);\n  const int n = ssize(g);\n\
    \  if (ssize(g) <= 15) {\n    for(int msk = 1; msk < (1 << n); msk++) {\n    \
    \  vi vs;\n      for(int i = 0; i < n; i++)\n        if (msk >> i & 1)\n     \
    \     vs.eb(i);\n      shuffle(vs.begin(), vs.end(), rng);\n      check2(vs);\n\
    \    }\n  } else {\n    for(int sz = 1; sz <= n; sz <<= 1) {\n      set<int> s;\n\
    \      while(ssize(s) != sz)\n        s.insert(rng() % n);\n      vi vs;\n   \
    \   for(int x : s) vs.eb(x);\n      shuffle(vs.begin(), vs.end(), rng);\n    \
    \  check2(vs);\n    }\n  }\n}\n\nauto random_relabel(vector<vector<int>> g) {\n\
    \  mt19937 rng(clock);\n  const int n = ssize(g);\n  vector<int> p(n);\n  iota(p.begin(),\
    \ p.end(), 0);\n  shuffle(p.begin(), p.end(), rng);\n  vector<vector<int>> g2(n);\n\
    \  for(int u = 0; u < n; u++)\n    for(int v : g[u])\n      g2[p[u]].eb(p[v]);\n\
    \  return g2;\n}\n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a\
    \ + b << '\\n';\n}\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  mt19937 rng(clock);\n\n  for(int n = 1; n <= 6; n++) {\n    enumerate_label_tree(n,\
    \ [&](vector<vector<int>> g) {\n      for(int r = 0; r < n; r++)\n        check(g,\
    \ r);\n    });\n  }\n\n  for(int n = 7; n <= 8; n++) {\n    enumerate_unlabel_rooted_tree(n,\
    \ [&](vector<vector<int>> g) {\n      for(int r = 0; r < n; r++)\n        check(g,\
    \ r);\n      g = random_relabel(g);\n      for(int r = 0; r < n; r++)\n      \
    \  check(g, r);\n    });\n  }\n\n  //path\n  for(int n = 1; n <= 100; n += 2)\
    \ {\n    vector<vector<int>> g(n);\n    for(int i = 1; i < n; i++)\n      g[i].emplace_back(i\
    \ - 1), g[i - 1].emplace_back(i);\n    check(g, 0);\n    check(random_relabel(g),\
    \ rng() % n);\n  }\n\n  //star\n  for(int n = 2; n <= 100; n += 2) {\n    for(int\
    \ root : {0, n / 2, n - 1}) {\n      vector<vector<int>> g(n);\n      for(int\
    \ i = 0; i < n; i++)\n        if (i != root)\n          g[root].emplace_back(i),\
    \ g[i].emplace_back(root);\n      check(g, root);\n      check(g, root == 0);\n\
    \    }\n  }\n\n  //almost path\n  for(int tc = 0; tc < 30; tc++) {\n    int n\
    \ = 500;\n    vector<vector<int>> g(n);\n    for(int v = 1; v < n; v++) {\n  \
    \    int x = rng() % min(v, 5);\n      g[v].emplace_back(x), g[x].emplace_back(v);\n\
    \    }\n    for(int r : {0, n / 2, n - 1})\n      check(g, r);\n    g = random_relabel(g);\n\
    \    for(int r : {0, n / 2, n - 1})\n      check(g, r);\n  }\n\n  a_plus_b();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - tree/prufer_recover.cpp
  - enumerate/enumerate_bit.cpp
  - enumerate/enumerate_twelvefold.cpp
  - enumerate/enumerate_label_tree.cpp
  - enumerate/enumerate_unlabel_rooted_tree.cpp
  - ds/RMQ.cpp
  - tree/LCA.cpp
  - tree/auxiliary_tree.cpp
  isVerificationFile: true
  path: test/mytest_auxiliary_tree.test.cpp
  requiredBy: []
  timestamp: '2026-02-02 17:55:32+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest_auxiliary_tree.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_auxiliary_tree.test.cpp
- /verify/test/mytest_auxiliary_tree.test.cpp.html
title: test/mytest_auxiliary_tree.test.cpp
---
