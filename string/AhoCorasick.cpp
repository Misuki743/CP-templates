struct AhoCorasick {
  struct node {
    static const int sigma = 26;
    int nxt[sigma];
    int p = -1, link = -1, ex = -1;
    char ch;
    bool leaf = false;

    node(int _p, char _ch) {
      fill(nxt, nxt + sigma, -1);
      ch = _ch, p = _p;
    }
  };

  vector<node> v;
  AhoCorasick(int sz) {
    v.reserve(sz);
    v.emplace_back(-1, ' ');
  }

  void insert(string s) {
    int now = 0;
    for(char X : s) {
      int id = X - 'a';
      if (v[now].nxt[id] == -1) {
        v[now].nxt[id] = v.size();
        v.emplace_back(now, X);
      }
      now = v[now].nxt[id];
    }
    v[now].leaf = true;
  }

  int go(int now, char ch) {
    int id = ch - 'a';
    if (v[now].nxt[id] != -1)
      return v[now].nxt[id];
    else if (now == 0)
      return 0;
    else
      return go(v[now].link, ch);
  }

  int calcLink(int now) {
    if (now == 0 or v[now].p == 0)
      return 0;
    else
      return go(v[v[now].p].link, v[now].ch);
  }

  int calcExit(int now) {
    if (now == 0)
      return -1;
    else if (v[v[now].link].leaf)
      return v[now].link;
    else
      return v[v[now].link].ex;
  }

  void build() {
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
      int now = q.front(); q.pop();
      v[now].link = calcLink(now);
      v[now].ex = calcExit(now);
      for(int i = 0; i < node::sigma; i++)
        if (v[now].nxt[i] != -1)
          q.push(v[now].nxt[i]);
    }
  }

  string nodeString(int now) {
    string res;
    while(now != 0)
      res += v[now].ch, now = v[now].p;
    reverse(res.begin(), res.end());
    return res;
  }
};
