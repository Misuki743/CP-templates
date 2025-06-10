//#include<ds/fenwickTree.cpp>

template<class T>
struct point_set_range_frequency {
  vector<T> a;
  int n, now = 0;
  struct Query {
    T x;
    int t, l, r, id;
  };
  vector<Query> q;
  struct Modification {
    T x;
    int t, i;
    bool add;
  };
  vector<Modification> m;

  point_set_range_frequency(vector<T> &_a)
    : a(_a), n(ssize(a)), m(n) {
    for(int i = 0; i < n; i++)
      m[i] = {a[i], 0, i, true};
  };

  void modify(int i, T x) {
    m.push_back({a[i], now, i, false});
    m.push_back({a[i] = x, now, i, true});
  }

  void query(int l, int r, T x) {
    q.push_back({x, now++, l, r, (int)size(q)});
  }

  vector<int> solve() {
    for(int i = 0; i < n; i++)
      m.push_back({a[i], now, i, false});
    ranges::sort(q, {}, [&](auto &e) { return pair(e.x, e.t); });
    ranges::sort(m, {}, [&](auto &e) { return pair(e.x, e.t); });
    vector<int> ans(ssize(q));
    fenwickTree<int> ft(n);
    for(int i = 0; auto [x, t, l, r, id] : q) {
      while(i < ssize(m) and pair(m[i].x, m[i].t) <= pair(x, t))
        ft.add(m[i].i, m[i].add ? 1 : -1), i++;
      ans[id] = ft.query(l, r);
    }
    return ans;
  }
};
