#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../default/t.cpp"
#include "../misc/compression.cpp"
#include "../ds/waveletMatrix.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a)
    cin >> x;

  compression<int> xs(a);
  waveletMatrix<int, 17> wv(xs.ord);

  while(q--) {
    int l, r, k; cin >> l >> r >> k;
    cout << xs.val[wv.kth(l, r, k)] << '\n';
  }

  return 0;
}
