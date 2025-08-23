struct AhoCorasick {
  struct node {
    static const int size = 26;
    int nxt[size], p, link = -1, ex = -1, leaf = 0;
    char ch;

    node(int _p = -1, char _ch = ' ') : p(_p), ch(_ch) {
      fill(nxt, nxt + size, -1);
    }
  };

  vector<node> v;
  AhoCorasick(int sz) : v(1) {
    v.reserve(sz);
  }

  int insert(string s) {
    int now = 0;
    for(char x : s) {
      int id = x - 'a';
      if (v[now].nxt[id] == -1) {
        v[now].nxt[id] = v.size();
        v.emplace_back(now, x);
      }
      now = v[now].nxt[id];
    }
    v[now].leaf = 1;
    return now;
  }

  int go(int now, char ch) {
    int id = ch - 'a';
    if (v[now].nxt[id] != -1) return v[now].nxt[id];
    else if (now == 0) return 0;
    else return go(v[now].link, ch);
  }

  int calcLink(int now) {
    if (now == 0 or v[now].p == 0) return 0;
    else return go(v[v[now].p].link, v[now].ch);
  }

  int calcExit(int now) {
    if (now == 0) return -1;
    else if (v[v[now].link].leaf) return v[now].link;
    else return v[v[now].link].ex;
  }

  vector<int> build() {
    vector<int> q(1, 0);
    for(int i = 0; i < ssize(q); i++) {
      int now = q[i];
      v[now].link = calcLink(now);
      v[now].ex = calcExit(now);
      for(int j = 0; j < node::size; j++)
        if (v[now].nxt[j] != -1)
          q.emplace_back(v[now].nxt[j]);
    }
    return q;
  }
};
