---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: enumerate/enumerate_bit.cpp
    title: enumerate/enumerate_bit.cpp
  - icon: ':x:'
    path: enumerate/enumerate_twelvefold.cpp
    title: enumerate/enumerate_twelvefold.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest_enumerate_twelvefold.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"default/t.cpp\"\n#include\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"enumerate/enumerate_bit.cpp\"\n\ntemplate<typename\
    \ F, typename INT>\nrequires invocable<F, INT>\nvoid enumerate_subset(INT msk,\
    \ F f) {\n  for(INT x = msk; x > 0; x = (x - 1) & msk)\n    f(x);\n  f(0);\n}\n\
    #line 1 \"enumerate/enumerate_twelvefold.cpp\"\n//#include \"enumerate/bit.cpp\"\
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
    \ dfs);\n}\n#line 6 \"test/mytest_enumerate_twelvefold.test.cpp\"\n\nvoid a_plus_b()\
    \ {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n}\n\nint main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  { //[0..n-1]^k\n    for(int\
    \ n = 0; n <= 7; n++) {\n      int cnt = 1;\n      for(int k = 0; k <= 7; k++,\
    \ cnt *= n) {\n        vector<vector<int>> S;\n        enumerate_cartesian_power(n,\
    \ k, [&](vector<int> a) {\n          assert(ssize(a) == k);\n          assert(a.empty()\
    \ or ranges::min(a) >= 0);\n          assert(a.empty() or ranges::max(a) < n);\n\
    \          S.push_back(std::move(a));\n        });\n        assert(cnt == ssize(S));\n\
    \        Unique(S);\n        assert(cnt == ssize(S));\n      }\n    }\n  }\n\n\
    \  { //permutation\n    int cnt = 1;\n    for(int n = 0; n <= 9; cnt *= ++n) {\n\
    \      vector<vector<int>> S;\n      enumerate_permutation(n, [&](vector<int>\
    \ p) {\n        assert(ssize(p) == n);\n        S.push_back(p);\n        ranges::sort(p);\n\
    \        for(int i = 0; i < n; i++)\n          assert(p[i] == i);\n      });\n\
    \      assert(cnt == ssize(S));\n      Unique(S);\n      assert(cnt == ssize(S));\n\
    \    }\n  }\n\n  { //combination\n    int C[17][17] = {};\n    for(int i = 0;\
    \ i < 17; i++)\n      C[i][0] = C[i][i] = 1;\n    for(int i = 2; i < 17; i++)\n\
    \      for(int j = 1; j < i; j++)\n        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n\
    \n    for(int n = 0; n < 17; n++) {\n      for(int k = 0; k < 17; k++) {\n   \
    \     vector<vector<int>> S;\n        enumerate_combination(n, k, [&](vector<int>\
    \ a) {\n          assert(ssize(a) == k);\n          assert(a.empty() or ranges::min(a)\
    \ >= 0);\n          assert(a.empty() or ranges::max(a) < n);\n          S.push_back(a);\n\
    \          Unique(a);\n          assert(ssize(a) == k);\n        });\n       \
    \ assert(ssize(S) == C[n][k]);\n        Unique(S);\n        assert(ssize(S) ==\
    \ C[n][k]);\n      }\n    }\n  }\n\n  { //set partition\n    int bell[12] = {1,\
    \ 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570};\n    for(int n = 0;\
    \ n < 12; n++) {\n      vector<vector<int>> S;\n      enumerate_set_partition(n,\
    \ [&](vector<int> p) {\n        ranges::sort(p);\n        int msk = 0;\n     \
    \   for(int x : p) {\n          assert((x | ((1 << n) - 1)) == (1 << n) - 1);\n\
    \          assert(x > 0);\n          assert((msk & x) == 0);\n          msk |=\
    \ x;\n        }\n        assert(msk == (1 << n) - 1);\n        S.push_back(std::move(p));\n\
    \      });\n      assert(ssize(S) == bell[n]);\n      Unique(S);\n      assert(ssize(S)\
    \ == bell[n]);\n    }\n  }\n\n  { //f[0] + f[1] + ... + f[n - 1] = sum, f[i] >=\
    \ 0\n    int C[17][17] = {};\n    for(int i = 0; i < 17; i++)\n      C[i][0] =\
    \ C[i][i] = 1;\n    for(int i = 2; i < 17; i++)\n      for(int j = 1; j < i; j++)\n\
    \        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n\n    for(int n = 0; n < 17;\
    \ n++) {\n      for(int sum = 0; n - 1 + sum < 17; sum++) {\n        vector<vector<int>>\
    \ S;\n        enumerate_multisubset(n, sum, [&](vector<int> f) {\n          assert(ssize(f)\
    \ == n);\n          assert(f.empty() or ranges::min(f) >= 0);\n          assert(accumulate(f.begin(),\
    \ f.end(), 0) == sum);\n          S.emplace_back(f);\n        });\n        if\
    \ (n == 0)\n          assert(ssize(S) == (sum == 0));\n        else\n        \
    \  assert(ssize(S) == C[n - 1 + sum][sum]);\n        Unique(S);\n        if (n\
    \ == 0)\n          assert(ssize(S) == (sum == 0));\n        else\n          assert(ssize(S)\
    \ == C[n - 1 + sum][sum]);\n      }\n    }\n  }\n\n  { //integer partition\n \
    \   int part[50] = {1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176,\
    \ 231, 297, 385, 490, 627, 792, 1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565,\
    \ 5604, 6842, 8349, 10143, 12310, 14883, 17977, 21637, 26015, 31185, 37338, 44583,\
    \ 53174, 63261, 75175, 89134, 105558, 124754, 147273, 173525};\n    for(int n\
    \ = 0; n < 50; n++) {\n      vector<vector<int>> S;\n      enumerate_integer_partition(n,\
    \ [&](vector<int> p) {\n        assert(p.empty() or ranges::min(p) > 0);\n   \
    \     assert(ranges::is_sorted(p | views::reverse));\n        assert(accumulate(p.begin(),\
    \ p.end(), 0) == n);\n        S.emplace_back(std::move(p));\n      });\n     \
    \ assert(ssize(S) == part[n]);\n      Unique(S);\n      assert(ssize(S) == part[n]);\n\
    \    }\n  }\n\n  a_plus_b();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../enumerate/enumerate_bit.cpp\"\n#include \"../enumerate/enumerate_twelvefold.cpp\"\
    \n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n\
    }\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  { //[0..n-1]^k\n\
    \    for(int n = 0; n <= 7; n++) {\n      int cnt = 1;\n      for(int k = 0; k\
    \ <= 7; k++, cnt *= n) {\n        vector<vector<int>> S;\n        enumerate_cartesian_power(n,\
    \ k, [&](vector<int> a) {\n          assert(ssize(a) == k);\n          assert(a.empty()\
    \ or ranges::min(a) >= 0);\n          assert(a.empty() or ranges::max(a) < n);\n\
    \          S.push_back(std::move(a));\n        });\n        assert(cnt == ssize(S));\n\
    \        Unique(S);\n        assert(cnt == ssize(S));\n      }\n    }\n  }\n\n\
    \  { //permutation\n    int cnt = 1;\n    for(int n = 0; n <= 9; cnt *= ++n) {\n\
    \      vector<vector<int>> S;\n      enumerate_permutation(n, [&](vector<int>\
    \ p) {\n        assert(ssize(p) == n);\n        S.push_back(p);\n        ranges::sort(p);\n\
    \        for(int i = 0; i < n; i++)\n          assert(p[i] == i);\n      });\n\
    \      assert(cnt == ssize(S));\n      Unique(S);\n      assert(cnt == ssize(S));\n\
    \    }\n  }\n\n  { //combination\n    int C[17][17] = {};\n    for(int i = 0;\
    \ i < 17; i++)\n      C[i][0] = C[i][i] = 1;\n    for(int i = 2; i < 17; i++)\n\
    \      for(int j = 1; j < i; j++)\n        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n\
    \n    for(int n = 0; n < 17; n++) {\n      for(int k = 0; k < 17; k++) {\n   \
    \     vector<vector<int>> S;\n        enumerate_combination(n, k, [&](vector<int>\
    \ a) {\n          assert(ssize(a) == k);\n          assert(a.empty() or ranges::min(a)\
    \ >= 0);\n          assert(a.empty() or ranges::max(a) < n);\n          S.push_back(a);\n\
    \          Unique(a);\n          assert(ssize(a) == k);\n        });\n       \
    \ assert(ssize(S) == C[n][k]);\n        Unique(S);\n        assert(ssize(S) ==\
    \ C[n][k]);\n      }\n    }\n  }\n\n  { //set partition\n    int bell[12] = {1,\
    \ 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570};\n    for(int n = 0;\
    \ n < 12; n++) {\n      vector<vector<int>> S;\n      enumerate_set_partition(n,\
    \ [&](vector<int> p) {\n        ranges::sort(p);\n        int msk = 0;\n     \
    \   for(int x : p) {\n          assert((x | ((1 << n) - 1)) == (1 << n) - 1);\n\
    \          assert(x > 0);\n          assert((msk & x) == 0);\n          msk |=\
    \ x;\n        }\n        assert(msk == (1 << n) - 1);\n        S.push_back(std::move(p));\n\
    \      });\n      assert(ssize(S) == bell[n]);\n      Unique(S);\n      assert(ssize(S)\
    \ == bell[n]);\n    }\n  }\n\n  { //f[0] + f[1] + ... + f[n - 1] = sum, f[i] >=\
    \ 0\n    int C[17][17] = {};\n    for(int i = 0; i < 17; i++)\n      C[i][0] =\
    \ C[i][i] = 1;\n    for(int i = 2; i < 17; i++)\n      for(int j = 1; j < i; j++)\n\
    \        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n\n    for(int n = 0; n < 17;\
    \ n++) {\n      for(int sum = 0; n - 1 + sum < 17; sum++) {\n        vector<vector<int>>\
    \ S;\n        enumerate_multisubset(n, sum, [&](vector<int> f) {\n          assert(ssize(f)\
    \ == n);\n          assert(f.empty() or ranges::min(f) >= 0);\n          assert(accumulate(f.begin(),\
    \ f.end(), 0) == sum);\n          S.emplace_back(f);\n        });\n        if\
    \ (n == 0)\n          assert(ssize(S) == (sum == 0));\n        else\n        \
    \  assert(ssize(S) == C[n - 1 + sum][sum]);\n        Unique(S);\n        if (n\
    \ == 0)\n          assert(ssize(S) == (sum == 0));\n        else\n          assert(ssize(S)\
    \ == C[n - 1 + sum][sum]);\n      }\n    }\n  }\n\n  { //integer partition\n \
    \   int part[50] = {1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176,\
    \ 231, 297, 385, 490, 627, 792, 1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565,\
    \ 5604, 6842, 8349, 10143, 12310, 14883, 17977, 21637, 26015, 31185, 37338, 44583,\
    \ 53174, 63261, 75175, 89134, 105558, 124754, 147273, 173525};\n    for(int n\
    \ = 0; n < 50; n++) {\n      vector<vector<int>> S;\n      enumerate_integer_partition(n,\
    \ [&](vector<int> p) {\n        assert(p.empty() or ranges::min(p) > 0);\n   \
    \     assert(ranges::is_sorted(p | views::reverse));\n        assert(accumulate(p.begin(),\
    \ p.end(), 0) == n);\n        S.emplace_back(std::move(p));\n      });\n     \
    \ assert(ssize(S) == part[n]);\n      Unique(S);\n      assert(ssize(S) == part[n]);\n\
    \    }\n  }\n\n  a_plus_b();\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - enumerate/enumerate_bit.cpp
  - enumerate/enumerate_twelvefold.cpp
  isVerificationFile: true
  path: test/mytest_enumerate_twelvefold.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:10:37+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest_enumerate_twelvefold.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_enumerate_twelvefold.test.cpp
- /verify/test/mytest_enumerate_twelvefold.test.cpp.html
title: test/mytest_enumerate_twelvefold.test.cpp
---
