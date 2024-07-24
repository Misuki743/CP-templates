#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../default/t.cpp"
#include "../ds/RMQ.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a) cin >> x;

  RMQ rmq(a);

  while(q--) {
    int l, r; cin >> l >> r;
    cout << rmq.query(l, r) << '\n';
  }

  return 0;
}
