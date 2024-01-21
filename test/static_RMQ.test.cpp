#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../default/t.cpp"
#include "../ds/sparseTable.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a)
    cin >> x;
  sparseTable<int> st(a, [](const int &x, const int &y) { return min(x, y); });
  while(q--) {
    int l, r; cin >> l >> r;
    cout << st.query(l, r) << '\n';
  }

  return 0;
}
