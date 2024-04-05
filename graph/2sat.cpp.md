---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/two_sat.test.cpp
    title: test/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/2sat.cpp\"\n//source: KACTL\n\n/**\n * Author: Emil\
    \ Lenngren, Simon Lindholm\n * Date: 2011-11-29\n * License: CC0\n * Source: folklore\n\
    \ * Description: Calculates a valid assignment to boolean variables a, b, c,...\
    \ to a 2-SAT problem, so that an expression of the type $(a\\|\\|b)\\&\\&(!a\\\
    |\\|c)\\&\\&(d\\|\\|!b)\\&\\&...$ becomes true, or reports that it is unsatisfiable.\n\
    \ * Negated variables are represented by bit-inversions (\\texttt{\\tilde{}x}).\n\
    \ * Usage:\n *  TwoSat ts(number of boolean variables);\n *  ts.either(0, \\tilde3);\
    \ // Var 0 is true or var 3 is false\n *  ts.setValue(2); // Var 2 is true\n *\
    \  ts.atMostOne({0,\\tilde1,2}); // <= 1 of vars 0, \\tilde1 and 2 are true\n\
    \ *  ts.solve(); // Returns true iff it is solvable\n *  ts.values[0..N-1] holds\
    \ the assigned values to the vars\n * Time: O(N+E), where N is the number of boolean\
    \ variables, and E is the number of clauses.\n * Status: stress-tested\n */\n\n\
    #define rep(i, a, b) for(int i = a; i < (b); ++i)\n#define sz(x) (int)(x).size()\n\
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
    \ == comp[2*i+1]) return 0;\n\t\treturn 1;\n\t}\n};\n"
  code: "//source: KACTL\n\n/**\n * Author: Emil Lenngren, Simon Lindholm\n * Date:\
    \ 2011-11-29\n * License: CC0\n * Source: folklore\n * Description: Calculates\
    \ a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, so that\
    \ an expression of the type $(a\\|\\|b)\\&\\&(!a\\|\\|c)\\&\\&(d\\|\\|!b)\\&\\\
    &...$ becomes true, or reports that it is unsatisfiable.\n * Negated variables\
    \ are represented by bit-inversions (\\texttt{\\tilde{}x}).\n * Usage:\n *  TwoSat\
    \ ts(number of boolean variables);\n *  ts.either(0, \\tilde3); // Var 0 is true\
    \ or var 3 is false\n *  ts.setValue(2); // Var 2 is true\n *  ts.atMostOne({0,\\\
    tilde1,2}); // <= 1 of vars 0, \\tilde1 and 2 are true\n *  ts.solve(); // Returns\
    \ true iff it is solvable\n *  ts.values[0..N-1] holds the assigned values to\
    \ the vars\n * Time: O(N+E), where N is the number of boolean variables, and E\
    \ is the number of clauses.\n * Status: stress-tested\n */\n\n#define rep(i, a,\
    \ b) for(int i = a; i < (b); ++i)\n#define sz(x) (int)(x).size()\nusing vi = vector<int>;\n\
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
    \ return 0;\n\t\treturn 1;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/2sat.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/two_sat.test.cpp
documentation_of: graph/2sat.cpp
layout: document
redirect_from:
- /library/graph/2sat.cpp
- /library/graph/2sat.cpp.html
title: graph/2sat.cpp
---
