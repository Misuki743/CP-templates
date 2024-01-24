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
    - https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
    - https://judge.yosupo.jp/submission/96487
    - https://www.geeksforgeeks.org/biconnected-components/
    - https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/
  bundledCode: "#line 1 \"graph/BCC.cpp\"\n//source: https://judge.yosupo.jp/submission/96487\n\
    \n/*\n\u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u4F7F\u3046\n\n\u4E8C\
    \u91CD\u9023\u7D50\u6210\u5206\u5206\u89E3\u3068\u3082\u547C\u3070\u308C\u308B\
    \u3002\n\n\nO(V+E)\n\u53C2\u8003:\nhttps://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html\n\
    https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/\n\
    https://www.geeksforgeeks.org/biconnected-components/\n*/\n\ntemplate<class T,class\
    \ U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}\n\
    template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return\
    \ true;}\ntemplate<typename T> constexpr int bitUP(T x,int a){return (x>>a)&1;}\n\
    \nusing Graph=vector<vector<int>>;\n\nstruct LowLink{\n    const Graph &g;\n \
    \   int sz;\n    //low[u]:=u\u304B\u3089\u4EE5\u4E0B\u306E\u65B9\u6CD5\u3067\u305F\
    \u3069\u308A\u7740\u3051\u308B\u9802\u70B9\u306E\u3046\u3061,ord\u306E\u6700\u5C0F\
    \u5024\n    //1. DFS\u6728\u306E\u8FBA\u3092\u6839\u304B\u3089\u8449\u306E\u5411\
    \u304D\u3078\u9032\u3080(\u4F55\u5EA6\u3067\u3082)\n    //2. \u5F8C\u9000\u8FBA\
    \u3092\u9032\u3080(1\u56DE\u3060\u3051)\n    vector<int> ord,low;\n    vector<bool>\
    \ used;\n    vector<int> articulation; //\u95A2\u7BC0\u70B9\n    vector<pii> bridge;\
    \ //\u6A4B first<second\u306B\u306A\u3063\u3066\u3044\u308B\n    int k;\n\n  \
    \  void dfs(int idx,int par){\n        used[idx]=true;\n        ord[idx]=k++;\n\
    \        low[idx]=ord[idx];\n        bool is_articulation=false;\n        int\
    \ cnt=0;\n        int par_edge_cnt=0; //par\u306B\u5411\u304B\u3046\u8FBA\u306E\
    \u6570 2\u500B\u4EE5\u4E0A\u306A\u3089\u5F8C\u9000\u8FBA\u3068\u3057\u3066\u8003\
    \u616E\u3059\u308B\n        for(int to:g[idx]){\n            if(!used[to]){\n\
    \                cnt++;\n                dfs(to,idx); //\u3053\u306E\u8FBA\u306F\
    DFS\u6728\u306B\u8FFD\u52A0\u3059\u308B\n                chmin(low[idx],low[to]);\n\
    \                if(ord[idx]<low[to]) bridge.emplace_back(minmax(idx,to));//to\u306B\
    \u884C\u3063\u305F\u304D\u308A\u3001\u623B\u3063\u3066\u3053\u308C\u306A\u3044\
    \u306A\u3089\u8FFD\u52A0\n                is_articulation |=(par!=-1 && ord[idx]<=low[to]);\n\
    \            }else if(to!=par){\n                //\u3053\u306E\u8FBA\u306F\u5F8C\
    \u9000\u8FBA\n                chmin(low[idx],ord[to]);\n            }else{\n \
    \               //to==par\n                par_edge_cnt++;\n            }\n  \
    \      }\n        if(par_edge_cnt>=2) chmin(low[idx],ord[par]);\n        is_articulation\
    \ |= (par==-1 && cnt>=2);\n        if(is_articulation) articulation.push_back(idx);\n\
    \n    }\n\n    LowLink(const Graph &g):g(g){\n        sz=g.size();\n        used.assign(sz,false);\n\
    \        ord.assign(sz,0);\n        low.assign(sz,0);\n        k=0;\n        for(int\
    \ i=0;i<sz;i++){\n            if(!used[i]) dfs(i,-1);\n        }\n    }\n};\n\
    struct BiConnectedComponents{\n\n    int sz;\n    LowLink L;\n    vector<int>\
    \ group_id;//\u3069\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u304B\n  \
    \  Graph forest; //\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \u5F8C\u306E\u30B0\u30E9\u30D5\n    vector<vector<int>> group; //[i]:=\u30B0\u30EB\
    \u30FC\u30D7i\u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u756A\u53F7 \u6607\u9806\
    \n\n    BiConnectedComponents(const Graph &g):sz(g.size()),L(g),group_id(g.size(),-1),group(sz*2){\n\
    \        vector<bool> is_articulation(sz,false);\n        for(int v:L.articulation){\n\
    \            is_articulation[v]=true;\n        }\n        vector<int> st;\n  \
    \      vector<int> used(sz,false);\n        int times=0;\n        auto dfs=[&](int\
    \ idx,int par,auto self)->void{\n            used[idx]=true;\n            group_id[idx]=times;\n\
    \            int loop=0;\n            for(int to:g[idx]){\n                if(to==par)\
    \ continue;\n                if(used[to]){\n                    if(L.ord[to]<L.ord[idx])st.push_back(to);\n\
    \                    continue;\n                }\n                loop++;\n \
    \               int now_id=st.size();\n                st.push_back(idx);\n  \
    \              st.push_back(to);\n                self(to,idx,self);\n       \
    \         bool is_pop=false;\n                if(par==-1 and loop>=2) is_pop=true;\n\
    \                if(par!=-1 && L.ord[idx]<=L.low[to]) is_pop=true;\n\n       \
    \         if(is_pop){\n                    for(int i=now_id;i<int(st.size());i++){\n\
    \                        group[times].push_back(st[i]);\n                    \
    \    group_id[st[i]]=times;\n                    }\n                    st.resize(now_id);\n\
    \                    times++;\n                }\n            }\n            return;\n\
    \        };\n        for(int i=0;i<sz;i++){\n            if(used[i]==false){\n\
    \                dfs(i,-1,dfs);\n                if(g[i].size()==0 or st.size()){\n\
    \                    st.push_back(i);\n                    for(int v:st){\n  \
    \                      group[times].push_back(v);\n                        group_id[v]=times;\n\
    \                    }\n                    times++;\n                    st.clear();\n\
    \                }\n            }\n        }\n        for(auto &v:group){\n  \
    \          sort(v.begin(),v.end());\n            v.erase(unique(v.begin(),v.end()),v.end());\n\
    \        }\n        group.resize(times);\n        /*for(int v:L.articulation){\n\
    \            group_id[v]=times++;\n        }\n        forest.resize(times);\n\
    \        \n        for(int v:L.articulation){\n            for(int to:g[v]){\n\
    \                int s=group_id[v];\n                int t=group_id[to];\n   \
    \             forest[s].push_back(t);\n                if(is_articulation[to])\
    \ continue;\n                forest[t].push_back(s);\n            }\n        }\n\
    \        group.resize(times);\n        for(int i=0;i<sz;i++){\n            group[group_id[i]].push_back(i);\n\
    \        }*/\n    }\n\n};\n"
  code: "//source: https://judge.yosupo.jp/submission/96487\n\n/*\n\u7121\u5411\u30B0\
    \u30E9\u30D5\u306B\u5BFE\u3057\u3066\u4F7F\u3046\n\n\u4E8C\u91CD\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u3068\u3082\u547C\u3070\u308C\u308B\u3002\n\n\nO(V+E)\n\u53C2\
    \u8003:\nhttps://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html\n\
    https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/\n\
    https://www.geeksforgeeks.org/biconnected-components/\n*/\n\ntemplate<class T,class\
    \ U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}\n\
    template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return\
    \ true;}\ntemplate<typename T> constexpr int bitUP(T x,int a){return (x>>a)&1;}\n\
    \nusing Graph=vector<vector<int>>;\n\nstruct LowLink{\n    const Graph &g;\n \
    \   int sz;\n    //low[u]:=u\u304B\u3089\u4EE5\u4E0B\u306E\u65B9\u6CD5\u3067\u305F\
    \u3069\u308A\u7740\u3051\u308B\u9802\u70B9\u306E\u3046\u3061,ord\u306E\u6700\u5C0F\
    \u5024\n    //1. DFS\u6728\u306E\u8FBA\u3092\u6839\u304B\u3089\u8449\u306E\u5411\
    \u304D\u3078\u9032\u3080(\u4F55\u5EA6\u3067\u3082)\n    //2. \u5F8C\u9000\u8FBA\
    \u3092\u9032\u3080(1\u56DE\u3060\u3051)\n    vector<int> ord,low;\n    vector<bool>\
    \ used;\n    vector<int> articulation; //\u95A2\u7BC0\u70B9\n    vector<pii> bridge;\
    \ //\u6A4B first<second\u306B\u306A\u3063\u3066\u3044\u308B\n    int k;\n\n  \
    \  void dfs(int idx,int par){\n        used[idx]=true;\n        ord[idx]=k++;\n\
    \        low[idx]=ord[idx];\n        bool is_articulation=false;\n        int\
    \ cnt=0;\n        int par_edge_cnt=0; //par\u306B\u5411\u304B\u3046\u8FBA\u306E\
    \u6570 2\u500B\u4EE5\u4E0A\u306A\u3089\u5F8C\u9000\u8FBA\u3068\u3057\u3066\u8003\
    \u616E\u3059\u308B\n        for(int to:g[idx]){\n            if(!used[to]){\n\
    \                cnt++;\n                dfs(to,idx); //\u3053\u306E\u8FBA\u306F\
    DFS\u6728\u306B\u8FFD\u52A0\u3059\u308B\n                chmin(low[idx],low[to]);\n\
    \                if(ord[idx]<low[to]) bridge.emplace_back(minmax(idx,to));//to\u306B\
    \u884C\u3063\u305F\u304D\u308A\u3001\u623B\u3063\u3066\u3053\u308C\u306A\u3044\
    \u306A\u3089\u8FFD\u52A0\n                is_articulation |=(par!=-1 && ord[idx]<=low[to]);\n\
    \            }else if(to!=par){\n                //\u3053\u306E\u8FBA\u306F\u5F8C\
    \u9000\u8FBA\n                chmin(low[idx],ord[to]);\n            }else{\n \
    \               //to==par\n                par_edge_cnt++;\n            }\n  \
    \      }\n        if(par_edge_cnt>=2) chmin(low[idx],ord[par]);\n        is_articulation\
    \ |= (par==-1 && cnt>=2);\n        if(is_articulation) articulation.push_back(idx);\n\
    \n    }\n\n    LowLink(const Graph &g):g(g){\n        sz=g.size();\n        used.assign(sz,false);\n\
    \        ord.assign(sz,0);\n        low.assign(sz,0);\n        k=0;\n        for(int\
    \ i=0;i<sz;i++){\n            if(!used[i]) dfs(i,-1);\n        }\n    }\n};\n\
    struct BiConnectedComponents{\n\n    int sz;\n    LowLink L;\n    vector<int>\
    \ group_id;//\u3069\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u304B\n  \
    \  Graph forest; //\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \u5F8C\u306E\u30B0\u30E9\u30D5\n    vector<vector<int>> group; //[i]:=\u30B0\u30EB\
    \u30FC\u30D7i\u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u756A\u53F7 \u6607\u9806\
    \n\n    BiConnectedComponents(const Graph &g):sz(g.size()),L(g),group_id(g.size(),-1),group(sz*2){\n\
    \        vector<bool> is_articulation(sz,false);\n        for(int v:L.articulation){\n\
    \            is_articulation[v]=true;\n        }\n        vector<int> st;\n  \
    \      vector<int> used(sz,false);\n        int times=0;\n        auto dfs=[&](int\
    \ idx,int par,auto self)->void{\n            used[idx]=true;\n            group_id[idx]=times;\n\
    \            int loop=0;\n            for(int to:g[idx]){\n                if(to==par)\
    \ continue;\n                if(used[to]){\n                    if(L.ord[to]<L.ord[idx])st.push_back(to);\n\
    \                    continue;\n                }\n                loop++;\n \
    \               int now_id=st.size();\n                st.push_back(idx);\n  \
    \              st.push_back(to);\n                self(to,idx,self);\n       \
    \         bool is_pop=false;\n                if(par==-1 and loop>=2) is_pop=true;\n\
    \                if(par!=-1 && L.ord[idx]<=L.low[to]) is_pop=true;\n\n       \
    \         if(is_pop){\n                    for(int i=now_id;i<int(st.size());i++){\n\
    \                        group[times].push_back(st[i]);\n                    \
    \    group_id[st[i]]=times;\n                    }\n                    st.resize(now_id);\n\
    \                    times++;\n                }\n            }\n            return;\n\
    \        };\n        for(int i=0;i<sz;i++){\n            if(used[i]==false){\n\
    \                dfs(i,-1,dfs);\n                if(g[i].size()==0 or st.size()){\n\
    \                    st.push_back(i);\n                    for(int v:st){\n  \
    \                      group[times].push_back(v);\n                        group_id[v]=times;\n\
    \                    }\n                    times++;\n                    st.clear();\n\
    \                }\n            }\n        }\n        for(auto &v:group){\n  \
    \          sort(v.begin(),v.end());\n            v.erase(unique(v.begin(),v.end()),v.end());\n\
    \        }\n        group.resize(times);\n        /*for(int v:L.articulation){\n\
    \            group_id[v]=times++;\n        }\n        forest.resize(times);\n\
    \        \n        for(int v:L.articulation){\n            for(int to:g[v]){\n\
    \                int s=group_id[v];\n                int t=group_id[to];\n   \
    \             forest[s].push_back(t);\n                if(is_articulation[to])\
    \ continue;\n                forest[t].push_back(s);\n            }\n        }\n\
    \        group.resize(times);\n        for(int i=0;i<sz;i++){\n            group[group_id[i]].push_back(i);\n\
    \        }*/\n    }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/BCC.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/BCC.cpp
layout: document
redirect_from:
- /library/graph/BCC.cpp
- /library/graph/BCC.cpp.html
title: graph/BCC.cpp
---
