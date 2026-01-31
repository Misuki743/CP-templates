//#include "ds/DSU/rollback_DSU.cpp"

struct queue_DSU {
  int fa = 0, fb = 0;
  rollback_DSU dsu;
  string s;
  vector<int> ts;
  vector<pii> op;

  queue_DSU(int size) : dsu(size) {}

  bool merge(int u, int v) {
    op.emplace_back(u, v);
    s += 'B', fb++;
    ts.emplace_back(dsu.time());
    return dsu.merge(u, v);
  }
  
  void undo(bool fake = false) {
    if (s.back() == 'B') {
      int ga = 0, gb = 0;
      vi ta, tb;
      vc<pii> opa, opb;
      int i = ssize(s) - 1;
      while(i + 1 == ssize(s) or (gb > ga and ga != fa)) {
        if (s[i] == 'A')
          ga++, ta.emplace_back(ts[i]), opa.emplace_back(op[i--]);
        else
          gb++, tb.emplace_back(ts[i]), opb.emplace_back(op[i--]);
      }
      i++;
      if (ga == 0) {
        dsu.rollback(ts[0]);
        vector<int>().swap(ts);
        ranges::reverse(op);
        for(auto [u, v] : op) {
          ts.emplace_back(dsu.time());
          dsu.merge(u, v);
        }
        fill(s.begin(), s.end(), 'A');
        fa = ssize(s), fb = 0;
      } else {
        dsu.rollback(ts[i]);
        for(auto [u, v] : opb | views::reverse) {
          ts[i] = dsu.time();
          s[i] = 'B';
          op[i++] = pair(u, v);
          dsu.merge(u, v);
        }
        for(auto [u, v] : opa | views::reverse) {
          ts[i] = dsu.time();
          s[i] = 'A';
          op[i++] = pair(u, v);
          dsu.merge(u, v);
        }
      }
    }

    if (!fake)
      dsu.rollback(ts.back());
    s.pop_back(), fa--;
    ts.pop_back();
    op.pop_back();
  }

  int cc() { return (ssize(dsu.his) - dsu.nxt) / 2; }
};
