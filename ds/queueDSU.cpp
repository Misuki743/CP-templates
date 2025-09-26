struct queue_DSU {
  int size, fa = 0, fb = 0;
  DSU dsu;
  string s;
  vector<int> ts;
  vector<pii> op;

  queue_DSU(int _size) : size(_size), dsu(size) {}

  bool merge(int u, int v) {
    op.eb(u, v);
    s += 'B', fb++;
    ts.eb(dsu.time());
    return dsu.merge(u, v);
  }
  
  void undo(bool fake = false) {
    if (s.back() == 'B') {
      int ga = 0, gb = 0;
      vector<int> ta, tb;
      vector<pii> opa, opb;
      int i = ssize(s) - 1;
      while(i + 1 == ssize(s) or (gb > ga and ga != fa)) {
        if (s[i] == 'A')
          ga++, ta.eb(ts[i]), opa.eb(op[i--]);
        else
          gb++, tb.eb(ts[i]), opb.eb(op[i--]);
      }
      i++;
      if (ga == 0) {
        dsu.rollback(ts[0]);
        vector<int>().swap(ts);
        ranges::reverse(op);
        for(auto [u, v] : op) {
          ts.eb(dsu.time());
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

  int cc() { return dsu.cc(); }
};
