#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_frequency"

#include "../default/t.cpp"
#include "../ds/fenwickTree.cpp"
#include "../ds_problem/point_set_range_frequency.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a) cin >> x;

  point_set_range_frequency<int> ds(a);
  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int k, v; cin >> k >> v;
      ds.modify(k, v);
    } else {
      int l, r, x; cin >> l >> r >> x;
      ds.query(l, r, x);
    }
  }

  for(int x : ds.solve())
    cout << x << '\n';

  return 0;
}

