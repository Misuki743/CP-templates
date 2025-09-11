#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/deque_aggregation.cpp"

using M = array<mint, 2>;
M op(const M &m, const M &n) {
  return M{m[0] * n[0], m[1] * n[0] + n[1]};
}
M id() { return M{1, 0}; }

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int q; cin >> q;
  deque_aggregation<M, id, op> dq;
  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int a, b; cin >> a >> b;
      dq.push_front(M{a, b});
    } else if (op == 1) {
      int a, b; cin >> a >> b;
      dq.push_back(M{a, b});
    } else if (op == 2) {
      dq.pop_front();
    } else if (op == 3) {
      dq.pop_back();
    } else {
      int x; cin >> x;
      auto [a, b] = dq.query();
      cout << a * x + b << '\n';
    }
  }

  return 0;
}
