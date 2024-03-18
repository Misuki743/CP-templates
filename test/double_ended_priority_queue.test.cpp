#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../default/t.cpp"
#include "../ds/doubleEndedPQ.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a)
    cin >> x;

  doubleEndedPQ<int> pq;
  for(int x : a)
    pq.push(x);

  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int x; cin >> x;
      pq.push(x);
    } else if (op == 1) {
      cout << pq.min() << '\n';
      pq.popMin();
    } else {
      cout << pq.max() << '\n';
      pq.popMax();
    }
  }

  return 0;
}
