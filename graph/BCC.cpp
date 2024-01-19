/**
 * template name: BCC
 * reference: https://judge.yosupo.jp/submission/96487
 */

/*
無向グラフに対して使う

二重連結成分分解とも呼ばれる。


O(V+E)
参考:
https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/
https://www.geeksforgeeks.org/biconnected-components/
*/

template<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}
template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}
template<typename T> constexpr int bitUP(T x,int a){return (x>>a)&1;}

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
struct BiConnectedComponents{

    int sz;
    LowLink L;
    vector<int> group_id;//どのグループに属すか
    Graph forest; //二重頂点連結成分分解後のグラフ
    vector<vector<int>> group; //[i]:=グループiに属する頂点の番号 昇順

    BiConnectedComponents(const Graph &g):sz(g.size()),L(g),group_id(g.size(),-1),group(sz*2){
        vector<bool> is_articulation(sz,false);
        for(int v:L.articulation){
            is_articulation[v]=true;
        }
        vector<int> st;
        vector<int> used(sz,false);
        int times=0;
        auto dfs=[&](int idx,int par,auto self)->void{
            used[idx]=true;
            group_id[idx]=times;
            int loop=0;
            for(int to:g[idx]){
                if(to==par) continue;
                if(used[to]){
                    if(L.ord[to]<L.ord[idx])st.push_back(to);
                    continue;
                }
                loop++;
                int now_id=st.size();
                st.push_back(idx);
                st.push_back(to);
                self(to,idx,self);
                bool is_pop=false;
                if(par==-1 and loop>=2) is_pop=true;
                if(par!=-1 && L.ord[idx]<=L.low[to]) is_pop=true;

                if(is_pop){
                    for(int i=now_id;i<int(st.size());i++){
                        group[times].push_back(st[i]);
                        group_id[st[i]]=times;
                    }
                    st.resize(now_id);
                    times++;
                }
            }
            return;
        };
        for(int i=0;i<sz;i++){
            if(used[i]==false){
                dfs(i,-1,dfs);
                if(g[i].size()==0 or st.size()){
                    st.push_back(i);
                    for(int v:st){
                        group[times].push_back(v);
                        group_id[v]=times;
                    }
                    times++;
                    st.clear();
                }
            }
        }
        for(auto &v:group){
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
        }
        group.resize(times);
        /*for(int v:L.articulation){
            group_id[v]=times++;
        }
        forest.resize(times);
        
        for(int v:L.articulation){
            for(int to:g[v]){
                int s=group_id[v];
                int t=group_id[to];
                forest[s].push_back(t);
                if(is_articulation[to]) continue;
                forest[t].push_back(s);
            }
        }
        group.resize(times);
        for(int i=0;i<sz;i++){
            group[group_id[i]].push_back(i);
        }*/
    }

};
