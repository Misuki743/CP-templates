---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/2sat.cpp
    title: graph/2sat.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bit>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n\
    #include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n\
    #include <cmath>\n#include <compare>\n#include <complex>\n#include <concepts>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numbers>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ranges>\n#include <set>\n#include <span>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"graph/2sat.cpp\"\n//source:\
    \ KACTL\n\n/**\n * Author: Emil Lenngren, Simon Lindholm\n * Date: 2011-11-29\n\
    \ * License: CC0\n * Source: folklore\n * Description: Calculates a valid assignment\
    \ to boolean variables a, b, c,... to a 2-SAT problem, so that an expression of\
    \ the type $(a\\|\\|b)\\&\\&(!a\\|\\|c)\\&\\&(d\\|\\|!b)\\&\\&...$ becomes true,\
    \ or reports that it is unsatisfiable.\n * Negated variables are represented by\
    \ bit-inversions (\\texttt{\\tilde{}x}).\n * Usage:\n *  TwoSat ts(number of boolean\
    \ variables);\n *  ts.either(0, \\tilde3); // Var 0 is true or var 3 is false\n\
    \ *  ts.setValue(2); // Var 2 is true\n *  ts.atMostOne({0,\\tilde1,2}); // <=\
    \ 1 of vars 0, \\tilde1 and 2 are true\n *  ts.solve(); // Returns true iff it\
    \ is solvable\n *  ts.values[0..N-1] holds the assigned values to the vars\n *\
    \ Time: O(N+E), where N is the number of boolean variables, and E is the number\
    \ of clauses.\n * Status: stress-tested\n */\n\n#define rep(i, a, b) for(int i\
    \ = a; i < (b); ++i)\n#define sz(x) (int)(x).size()\nusing vi = vector<int>;\n\
    \nstruct TwoSat {\n\tint N;\n\tvector<vi> gr;\n\tvi values; // 0 = false, 1 =\
    \ true\n\n\tTwoSat(int n = 0) : N(n), gr(2*n) {}\n\n\tint addVar() { // (optional)\n\
    \t\tgr.emplace_back();\n\t\tgr.emplace_back();\n\t\treturn N++;\n\t}\n\n\tvoid\
    \ either(int f, int j) {\n\t\tf = max(2*f, -1-2*f);\n\t\tj = max(2*j, -1-2*j);\n\
    \t\tgr[f].push_back(j^1);\n\t\tgr[j].push_back(f^1);\n\t}\n\tvoid setValue(int\
    \ x) { either(x, x); }\n\n\tvoid atMostOne(const vi& li) { // (optional)\n\t\t\
    if (sz(li) <= 1) return;\n\t\tint cur = ~li[0];\n\t\trep(i,2,sz(li)) {\n\t\t\t\
    int next = addVar();\n\t\t\teither(cur, ~li[i]);\n\t\t\teither(cur, next);\n\t\
    \t\teither(~li[i], next);\n\t\t\tcur = ~next;\n\t\t}\n\t\teither(cur, ~li[1]);\n\
    \t}\n\n\tvi val, comp, z; int time = 0;\n\tint dfs(int i) {\n\t\tint low = val[i]\
    \ = ++time, x; z.push_back(i);\n\t\tfor(int e : gr[i]) if (!comp[e])\n\t\t\tlow\
    \ = min(low, val[e] ?: dfs(e));\n\t\tif (low == val[i]) do {\n\t\t\tx = z.back();\
    \ z.pop_back();\n\t\t\tcomp[x] = low;\n\t\t\tif (values[x>>1] == -1)\n\t\t\t\t\
    values[x>>1] = x&1;\n\t\t} while (x != i);\n\t\treturn val[i] = low;\n\t}\n\n\t\
    bool solve() {\n\t\tvalues.assign(N, -1);\n\t\tval.assign(2*N, 0); comp = val;\n\
    \t\trep(i,0,2*N) if (!comp[i]) dfs(i);\n\t\trep(i,0,N) if (comp[2*i] == comp[2*i+1])\
    \ return 0;\n\t\treturn 1;\n\t}\n};\n#line 5 \"test/two_sat.test.cpp\"\n\nint\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(0);\n\n  string p, cnf; cin\
    \ >> p >> cnf;\n  int n, m; cin >> n >> m;\n\n  TwoSat ts(n);\n  while(m--) {\n\
    \    int a, b, c; cin >> a >> b >> c;\n    a = (a > 0 ? a - 1 : ~(-(a + 1)));\n\
    \    b = (b > 0 ? b - 1 : ~(-(b + 1)));\n    ts.either(a, b);\n  }\n\n  if (ts.solve())\
    \ {\n    cout << \"s SATISFIABLE\\n\";\n    cout << \"v \";\n    for(int i = 0;\
    \ i < n; i++)\n      cout << (ts.values[i] ? i + 1 : -(i + 1)) << ' ';\n    cout\
    \ << 0 << '\\n';\n  } else {\n    cout << \"s UNSATISFIABLE\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../graph/2sat.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(0);\n\n  string p, cnf; cin >> p >> cnf;\n  int n, m; cin >> n >> m;\n\
    \n  TwoSat ts(n);\n  while(m--) {\n    int a, b, c; cin >> a >> b >> c;\n    a\
    \ = (a > 0 ? a - 1 : ~(-(a + 1)));\n    b = (b > 0 ? b - 1 : ~(-(b + 1)));\n \
    \   ts.either(a, b);\n  }\n\n  if (ts.solve()) {\n    cout << \"s SATISFIABLE\\\
    n\";\n    cout << \"v \";\n    for(int i = 0; i < n; i++)\n      cout << (ts.values[i]\
    \ ? i + 1 : -(i + 1)) << ' ';\n    cout << 0 << '\\n';\n  } else {\n    cout <<\
    \ \"s UNSATISFIABLE\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/2sat.cpp
  isVerificationFile: true
  path: test/two_sat.test.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/two_sat.test.cpp
- /verify/test/two_sat.test.cpp.html
title: test/two_sat.test.cpp
---
