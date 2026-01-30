---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: graph/misc/2sat.cpp
    title: graph/misc/2sat.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"graph/misc/2sat.cpp\"\n//source: KACTL\n\n\
    /**\n * Author: Emil Lenngren, Simon Lindholm\n * Date: 2011-11-29\n * License:\
    \ CC0\n * Source: folklore\n * Description: Calculates a valid assignment to boolean\
    \ variables a, b, c,... to a 2-SAT problem, so that an expression of the type\
    \ $(a\\|\\|b)\\&\\&(!a\\|\\|c)\\&\\&(d\\|\\|!b)\\&\\&...$ becomes true, or reports\
    \ that it is unsatisfiable.\n * Negated variables are represented by bit-inversions\
    \ (\\texttt{\\tilde{}x}).\n * Usage:\n *  TwoSat ts(number of boolean variables);\n\
    \ *  ts.either(0, \\tilde3); // Var 0 is true or var 3 is false\n *  ts.setValue(2);\
    \ // Var 2 is true\n *  ts.atMostOne({0,\\tilde1,2}); // <= 1 of vars 0, \\tilde1\
    \ and 2 are true\n *  ts.solve(); // Returns true iff it is solvable\n *  ts.values[0..N-1]\
    \ holds the assigned values to the vars\n * Time: O(N+E), where N is the number\
    \ of boolean variables, and E is the number of clauses.\n * Status: stress-tested\n\
    \ */\n\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n#define sz(x) (int)(x).size()\n\
    using vi = vector<int>;\n\nstruct TwoSat {\n\tint N;\n\tvector<vi> gr;\n\tvi values;\
    \ // 0 = false, 1 = true\n\n\tTwoSat(int n = 0) : N(n), gr(2*n) {}\n\n\tint addVar()\
    \ { // (optional)\n\t\tgr.emplace_back();\n\t\tgr.emplace_back();\n\t\treturn\
    \ N++;\n\t}\n\n\tvoid either(int f, int j) {\n\t\tf = max(2*f, -1-2*f);\n\t\t\
    j = max(2*j, -1-2*j);\n\t\tgr[f].push_back(j^1);\n\t\tgr[j].push_back(f^1);\n\t\
    }\n\tvoid setValue(int x) { either(x, x); }\n\n\tvoid atMostOne(const vi& li)\
    \ { // (optional)\n\t\tif (sz(li) <= 1) return;\n\t\tint cur = ~li[0];\n\t\trep(i,2,sz(li))\
    \ {\n\t\t\tint next = addVar();\n\t\t\teither(cur, ~li[i]);\n\t\t\teither(cur,\
    \ next);\n\t\t\teither(~li[i], next);\n\t\t\tcur = ~next;\n\t\t}\n\t\teither(cur,\
    \ ~li[1]);\n\t}\n\n\tvi val, comp, z; int time = 0;\n\tint dfs(int i) {\n\t\t\
    int low = val[i] = ++time, x; z.push_back(i);\n\t\tfor(int e : gr[i]) if (!comp[e])\n\
    \t\t\tlow = min(low, val[e] ?: dfs(e));\n\t\tif (low == val[i]) do {\n\t\t\tx\
    \ = z.back(); z.pop_back();\n\t\t\tcomp[x] = low;\n\t\t\tif (values[x>>1] == -1)\n\
    \t\t\t\tvalues[x>>1] = x&1;\n\t\t} while (x != i);\n\t\treturn val[i] = low;\n\
    \t}\n\n\tbool solve() {\n\t\tvalues.assign(N, -1);\n\t\tval.assign(2*N, 0); comp\
    \ = val;\n\t\trep(i,0,2*N) if (!comp[i]) dfs(i);\n\t\trep(i,0,N) if (comp[2*i]\
    \ == comp[2*i+1]) return 0;\n\t\treturn 1;\n\t}\n};\n#line 5 \"test/two_sat.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n\n  string p, cnf;\
    \ cin >> p >> cnf;\n  int n, m; cin >> n >> m;\n\n  TwoSat ts(n);\n  while(m--)\
    \ {\n    int a, b, c; cin >> a >> b >> c;\n    a = (a > 0 ? a - 1 : ~(-(a + 1)));\n\
    \    b = (b > 0 ? b - 1 : ~(-(b + 1)));\n    ts.either(a, b);\n  }\n\n  if (ts.solve())\
    \ {\n    cout << \"s SATISFIABLE\\n\";\n    cout << \"v \";\n    for(int i = 0;\
    \ i < n; i++)\n      cout << (ts.values[i] ? i + 1 : -(i + 1)) << ' ';\n    cout\
    \ << 0 << '\\n';\n  } else {\n    cout << \"s UNSATISFIABLE\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../graph/misc/2sat.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(0);\n\n  string p, cnf; cin >> p >> cnf;\n  int n, m; cin >> n >> m;\n\
    \n  TwoSat ts(n);\n  while(m--) {\n    int a, b, c; cin >> a >> b >> c;\n    a\
    \ = (a > 0 ? a - 1 : ~(-(a + 1)));\n    b = (b > 0 ? b - 1 : ~(-(b + 1)));\n \
    \   ts.either(a, b);\n  }\n\n  if (ts.solve()) {\n    cout << \"s SATISFIABLE\\\
    n\";\n    cout << \"v \";\n    for(int i = 0; i < n; i++)\n      cout << (ts.values[i]\
    \ ? i + 1 : -(i + 1)) << ' ';\n    cout << 0 << '\\n';\n  } else {\n    cout <<\
    \ \"s UNSATISFIABLE\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/misc/2sat.cpp
  isVerificationFile: true
  path: test/two_sat.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:47:42+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/two_sat.test.cpp
- /verify/test/two_sat.test.cpp.html
title: test/two_sat.test.cpp
---
