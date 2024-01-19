/**
 * template name: 2CC
 * reference: https://judge.yosupo.jp/submission/96489
 */

/*
無向グラフに対して使う

二辺連結成分分解とも. 二重辺連結成分とは, 1本の辺を取り除いても連結である部分グラフである. 
つまり, 橋を含まない部分グラフなので, 橋を列挙することで二重辺連結成分を列挙できる.

二重辺連結成分で縮約後の頂点と橋からなるグラフは森になっている.

O(V+E)

verify:
https://atcoder.jp/contests/arc039/submissions/33364987
参考:
https://ei1333.github.io/library/graph/connected-components/two-edge-connected-components.hpp
chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/http://hos.ac/slides/20110504_graph.pdf
*/

template<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}
template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}

using Graph=vector<vector<int>>;

struct LowLink{
    const Graph &g;
    int sz;
    //low[u]:=uから以下の方法でたどり着ける頂点のうち,ordの最小値
    //1. DFS木の辺を根から葉の向きへ進む(何度でも)
    //2. 後退辺を進む(1回だけ)
    vector<int> ord,low;
    vector<bool> used;
    vector<int> articulation; //関節点
    vector<pii> bridge; //橋 first<secondになっている
    int k;

    void dfs(int idx,int par){
        used[idx]=true;
        ord[idx]=k++;
        low[idx]=ord[idx];
        bool is_articulation=false;
        int cnt=0;
        int par_edge_cnt=0; //parに向かう辺の数 2個以上なら後退辺として考慮する
        for(int to:g[idx]){
            if(!used[to]){
                cnt++;
                dfs(to,idx); //この辺はDFS木に追加する
                chmin(low[idx],low[to]);
                if(ord[idx]<low[to]) bridge.emplace_back(minmax(idx,to));//toに行ったきり、戻ってこれないなら追加
                is_articulation |=(par!=-1 && ord[idx]<=low[to]);
            }else if(to!=par){
                //この辺は後退辺
                chmin(low[idx],ord[to]);
            }else{
                //to==par
                par_edge_cnt++;
            }
        }
        if(par_edge_cnt>=2) chmin(low[idx],ord[par]);
        is_articulation |= (par==-1 && cnt>=2);
        if(is_articulation) articulation.push_back(idx);

    }

    LowLink(const Graph &g):g(g){
        sz=g.size();
        used.assign(sz,false);
        ord.assign(sz,0);
        low.assign(sz,0);
        k=0;
        for(int i=0;i<sz;i++){
            if(!used[i]) dfs(i,-1);
        }
    }
};
struct TwoEdgeConnectedComponents{

    int sz;
    LowLink L;
    vector<int> group_id;//どのグループに属すか
    Graph forest; //二重連結成分分解後のグラフ
    vector<vector<int>> group; //[i]:=グループiに属する頂点の番号 昇順

    TwoEdgeConnectedComponents(const Graph &g):sz(g.size()),L(g),group_id(g.size(),-1){
        int id=0;
        auto dfs=[&](int idx,int par,auto self)->void{
            if(par>=0 and L.ord[par] >= L.low[idx]) group_id[idx]=group_id[par];
            else group_id[idx]=id++; //橋

            for(int to:g[idx]){
                if(group_id[to]==-1) self(to,idx,self);
            }
            return;
        };
        for(int i=0;i<sz;i++){
            if(group_id[i]==-1){
                dfs(i,-1,dfs);
            }
        }
      	forest.resize(id);
        for(auto e:L.bridge){
            int u=group_id[e.first];
            int v=group_id[e.second];

            forest[u].push_back(v);
            forest[v].push_back(u);
        }
        group.resize(id);
        for(int i=0;i<sz;i++){
            group[group_id[i]].push_back(i);
        }
    }

};
