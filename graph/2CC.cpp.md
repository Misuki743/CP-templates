---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://hos.ac/slides/20110504_graph.pdf
    - https://atcoder.jp/contests/arc039/submissions/33364987
    - https://ei1333.github.io/library/graph/connected-components/two-edge-connected-components.hpp
    - https://judge.yosupo.jp/submission/96489
  bundledCode: "#line 1 \"graph/2CC.cpp\"\n/**\n * template name: 2CC\n * reference:\
    \ https://judge.yosupo.jp/submission/96489\n */\n\n/*\n\u7121\u5411\u30B0\u30E9\
    \u30D5\u306B\u5BFE\u3057\u3066\u4F7F\u3046\n\n\u4E8C\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\u3068\u3082. \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u3068\u306F\
    , 1\u672C\u306E\u8FBA\u3092\u53D6\u308A\u9664\u3044\u3066\u3082\u9023\u7D50\u3067\
    \u3042\u308B\u90E8\u5206\u30B0\u30E9\u30D5\u3067\u3042\u308B. \n\u3064\u307E\u308A\
    , \u6A4B\u3092\u542B\u307E\u306A\u3044\u90E8\u5206\u30B0\u30E9\u30D5\u306A\u306E\
    \u3067, \u6A4B\u3092\u5217\u6319\u3059\u308B\u3053\u3068\u3067\u4E8C\u91CD\u8FBA\
    \u9023\u7D50\u6210\u5206\u3092\u5217\u6319\u3067\u304D\u308B.\n\n\u4E8C\u91CD\u8FBA\
    \u9023\u7D50\u6210\u5206\u3067\u7E2E\u7D04\u5F8C\u306E\u9802\u70B9\u3068\u6A4B\
    \u304B\u3089\u306A\u308B\u30B0\u30E9\u30D5\u306F\u68EE\u306B\u306A\u3063\u3066\
    \u3044\u308B.\n\nO(V+E)\n\nverify:\nhttps://atcoder.jp/contests/arc039/submissions/33364987\n\
    \u53C2\u8003:\nhttps://ei1333.github.io/library/graph/connected-components/two-edge-connected-components.hpp\n\
    chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/http://hos.ac/slides/20110504_graph.pdf\n\
    */\n\ntemplate<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return\
    \ false;a=b;return true;}\ntemplate<class T,class U>constexpr bool chmax(T&a,const\
    \ U b){if(a>=b)return false;a=b;return true;}\n\nusing Graph=vector<vector<int>>;\n\
    \nstruct LowLink{\n    const Graph &g;\n    int sz;\n    //low[u]:=u\u304B\u3089\
    \u4EE5\u4E0B\u306E\u65B9\u6CD5\u3067\u305F\u3069\u308A\u7740\u3051\u308B\u9802\
    \u70B9\u306E\u3046\u3061,ord\u306E\u6700\u5C0F\u5024\n    //1. DFS\u6728\u306E\
    \u8FBA\u3092\u6839\u304B\u3089\u8449\u306E\u5411\u304D\u3078\u9032\u3080(\u4F55\
    \u5EA6\u3067\u3082)\n    //2. \u5F8C\u9000\u8FBA\u3092\u9032\u3080(1\u56DE\u3060\
    \u3051)\n    vector<int> ord,low;\n    vector<bool> used;\n    vector<int> articulation;\
    \ //\u95A2\u7BC0\u70B9\n    vector<pii> bridge; //\u6A4B first<second\u306B\u306A\
    \u3063\u3066\u3044\u308B\n    int k;\n\n    void dfs(int idx,int par){\n     \
    \   used[idx]=true;\n        ord[idx]=k++;\n        low[idx]=ord[idx];\n     \
    \   bool is_articulation=false;\n        int cnt=0;\n        int par_edge_cnt=0;\
    \ //par\u306B\u5411\u304B\u3046\u8FBA\u306E\u6570 2\u500B\u4EE5\u4E0A\u306A\u3089\
    \u5F8C\u9000\u8FBA\u3068\u3057\u3066\u8003\u616E\u3059\u308B\n        for(int\
    \ to:g[idx]){\n            if(!used[to]){\n                cnt++;\n          \
    \      dfs(to,idx); //\u3053\u306E\u8FBA\u306FDFS\u6728\u306B\u8FFD\u52A0\u3059\
    \u308B\n                chmin(low[idx],low[to]);\n                if(ord[idx]<low[to])\
    \ bridge.emplace_back(minmax(idx,to));//to\u306B\u884C\u3063\u305F\u304D\u308A\
    \u3001\u623B\u3063\u3066\u3053\u308C\u306A\u3044\u306A\u3089\u8FFD\u52A0\n   \
    \             is_articulation |=(par!=-1 && ord[idx]<=low[to]);\n            }else\
    \ if(to!=par){\n                //\u3053\u306E\u8FBA\u306F\u5F8C\u9000\u8FBA\n\
    \                chmin(low[idx],ord[to]);\n            }else{\n              \
    \  //to==par\n                par_edge_cnt++;\n            }\n        }\n    \
    \    if(par_edge_cnt>=2) chmin(low[idx],ord[par]);\n        is_articulation |=\
    \ (par==-1 && cnt>=2);\n        if(is_articulation) articulation.push_back(idx);\n\
    \n    }\n\n    LowLink(const Graph &g):g(g){\n        sz=g.size();\n        used.assign(sz,false);\n\
    \        ord.assign(sz,0);\n        low.assign(sz,0);\n        k=0;\n        for(int\
    \ i=0;i<sz;i++){\n            if(!used[i]) dfs(i,-1);\n        }\n    }\n};\n\
    struct TwoEdgeConnectedComponents{\n\n    int sz;\n    LowLink L;\n    vector<int>\
    \ group_id;//\u3069\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u304B\n  \
    \  Graph forest; //\u4E8C\u91CD\u9023\u7D50\u6210\u5206\u5206\u89E3\u5F8C\u306E\
    \u30B0\u30E9\u30D5\n    vector<vector<int>> group; //[i]:=\u30B0\u30EB\u30FC\u30D7\
    i\u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u756A\u53F7 \u6607\u9806\n\n    TwoEdgeConnectedComponents(const\
    \ Graph &g):sz(g.size()),L(g),group_id(g.size(),-1){\n        int id=0;\n    \
    \    auto dfs=[&](int idx,int par,auto self)->void{\n            if(par>=0 and\
    \ L.ord[par] >= L.low[idx]) group_id[idx]=group_id[par];\n            else group_id[idx]=id++;\
    \ //\u6A4B\n\n            for(int to:g[idx]){\n                if(group_id[to]==-1)\
    \ self(to,idx,self);\n            }\n            return;\n        };\n       \
    \ for(int i=0;i<sz;i++){\n            if(group_id[i]==-1){\n                dfs(i,-1,dfs);\n\
    \            }\n        }\n      \tforest.resize(id);\n        for(auto e:L.bridge){\n\
    \            int u=group_id[e.first];\n            int v=group_id[e.second];\n\
    \n            forest[u].push_back(v);\n            forest[v].push_back(u);\n \
    \       }\n        group.resize(id);\n        for(int i=0;i<sz;i++){\n       \
    \     group[group_id[i]].push_back(i);\n        }\n    }\n\n};\n"
  code: "/**\n * template name: 2CC\n * reference: https://judge.yosupo.jp/submission/96489\n\
    \ */\n\n/*\n\u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u4F7F\u3046\
    \n\n\u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u3068\u3082. \u4E8C\u91CD\
    \u8FBA\u9023\u7D50\u6210\u5206\u3068\u306F, 1\u672C\u306E\u8FBA\u3092\u53D6\u308A\
    \u9664\u3044\u3066\u3082\u9023\u7D50\u3067\u3042\u308B\u90E8\u5206\u30B0\u30E9\
    \u30D5\u3067\u3042\u308B. \n\u3064\u307E\u308A, \u6A4B\u3092\u542B\u307E\u306A\
    \u3044\u90E8\u5206\u30B0\u30E9\u30D5\u306A\u306E\u3067, \u6A4B\u3092\u5217\u6319\
    \u3059\u308B\u3053\u3068\u3067\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u3092\
    \u5217\u6319\u3067\u304D\u308B.\n\n\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u3067\
    \u7E2E\u7D04\u5F8C\u306E\u9802\u70B9\u3068\u6A4B\u304B\u3089\u306A\u308B\u30B0\
    \u30E9\u30D5\u306F\u68EE\u306B\u306A\u3063\u3066\u3044\u308B.\n\nO(V+E)\n\nverify:\n\
    https://atcoder.jp/contests/arc039/submissions/33364987\n\u53C2\u8003:\nhttps://ei1333.github.io/library/graph/connected-components/two-edge-connected-components.hpp\n\
    chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/http://hos.ac/slides/20110504_graph.pdf\n\
    */\n\ntemplate<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return\
    \ false;a=b;return true;}\ntemplate<class T,class U>constexpr bool chmax(T&a,const\
    \ U b){if(a>=b)return false;a=b;return true;}\n\nusing Graph=vector<vector<int>>;\n\
    \nstruct LowLink{\n    const Graph &g;\n    int sz;\n    //low[u]:=u\u304B\u3089\
    \u4EE5\u4E0B\u306E\u65B9\u6CD5\u3067\u305F\u3069\u308A\u7740\u3051\u308B\u9802\
    \u70B9\u306E\u3046\u3061,ord\u306E\u6700\u5C0F\u5024\n    //1. DFS\u6728\u306E\
    \u8FBA\u3092\u6839\u304B\u3089\u8449\u306E\u5411\u304D\u3078\u9032\u3080(\u4F55\
    \u5EA6\u3067\u3082)\n    //2. \u5F8C\u9000\u8FBA\u3092\u9032\u3080(1\u56DE\u3060\
    \u3051)\n    vector<int> ord,low;\n    vector<bool> used;\n    vector<int> articulation;\
    \ //\u95A2\u7BC0\u70B9\n    vector<pii> bridge; //\u6A4B first<second\u306B\u306A\
    \u3063\u3066\u3044\u308B\n    int k;\n\n    void dfs(int idx,int par){\n     \
    \   used[idx]=true;\n        ord[idx]=k++;\n        low[idx]=ord[idx];\n     \
    \   bool is_articulation=false;\n        int cnt=0;\n        int par_edge_cnt=0;\
    \ //par\u306B\u5411\u304B\u3046\u8FBA\u306E\u6570 2\u500B\u4EE5\u4E0A\u306A\u3089\
    \u5F8C\u9000\u8FBA\u3068\u3057\u3066\u8003\u616E\u3059\u308B\n        for(int\
    \ to:g[idx]){\n            if(!used[to]){\n                cnt++;\n          \
    \      dfs(to,idx); //\u3053\u306E\u8FBA\u306FDFS\u6728\u306B\u8FFD\u52A0\u3059\
    \u308B\n                chmin(low[idx],low[to]);\n                if(ord[idx]<low[to])\
    \ bridge.emplace_back(minmax(idx,to));//to\u306B\u884C\u3063\u305F\u304D\u308A\
    \u3001\u623B\u3063\u3066\u3053\u308C\u306A\u3044\u306A\u3089\u8FFD\u52A0\n   \
    \             is_articulation |=(par!=-1 && ord[idx]<=low[to]);\n            }else\
    \ if(to!=par){\n                //\u3053\u306E\u8FBA\u306F\u5F8C\u9000\u8FBA\n\
    \                chmin(low[idx],ord[to]);\n            }else{\n              \
    \  //to==par\n                par_edge_cnt++;\n            }\n        }\n    \
    \    if(par_edge_cnt>=2) chmin(low[idx],ord[par]);\n        is_articulation |=\
    \ (par==-1 && cnt>=2);\n        if(is_articulation) articulation.push_back(idx);\n\
    \n    }\n\n    LowLink(const Graph &g):g(g){\n        sz=g.size();\n        used.assign(sz,false);\n\
    \        ord.assign(sz,0);\n        low.assign(sz,0);\n        k=0;\n        for(int\
    \ i=0;i<sz;i++){\n            if(!used[i]) dfs(i,-1);\n        }\n    }\n};\n\
    struct TwoEdgeConnectedComponents{\n\n    int sz;\n    LowLink L;\n    vector<int>\
    \ group_id;//\u3069\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u304B\n  \
    \  Graph forest; //\u4E8C\u91CD\u9023\u7D50\u6210\u5206\u5206\u89E3\u5F8C\u306E\
    \u30B0\u30E9\u30D5\n    vector<vector<int>> group; //[i]:=\u30B0\u30EB\u30FC\u30D7\
    i\u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u756A\u53F7 \u6607\u9806\n\n    TwoEdgeConnectedComponents(const\
    \ Graph &g):sz(g.size()),L(g),group_id(g.size(),-1){\n        int id=0;\n    \
    \    auto dfs=[&](int idx,int par,auto self)->void{\n            if(par>=0 and\
    \ L.ord[par] >= L.low[idx]) group_id[idx]=group_id[par];\n            else group_id[idx]=id++;\
    \ //\u6A4B\n\n            for(int to:g[idx]){\n                if(group_id[to]==-1)\
    \ self(to,idx,self);\n            }\n            return;\n        };\n       \
    \ for(int i=0;i<sz;i++){\n            if(group_id[i]==-1){\n                dfs(i,-1,dfs);\n\
    \            }\n        }\n      \tforest.resize(id);\n        for(auto e:L.bridge){\n\
    \            int u=group_id[e.first];\n            int v=group_id[e.second];\n\
    \n            forest[u].push_back(v);\n            forest[v].push_back(u);\n \
    \       }\n        group.resize(id);\n        for(int i=0;i<sz;i++){\n       \
    \     group[group_id[i]].push_back(i);\n        }\n    }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/2CC.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/2CC.cpp
layout: document
redirect_from:
- /library/graph/2CC.cpp
- /library/graph/2CC.cpp.html
title: graph/2CC.cpp
---
