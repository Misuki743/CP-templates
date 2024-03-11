#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../default/t.cpp"
#include "../misc/compression.cpp"
#include "../segtree/persistentSegmentTree.cpp"

int id() { return 0; }
int op(const int &a, const int &b) { return a + b; }

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a)
    cin >> x;

  compression<int, true> xs(a);
  persistentSegmentTree<int, id, op> st(2 * n + n * (bit_width((unsigned)n) + 1));
  vector<int> root(n + 1);
  root[0] = st.build(0, n);
  for(int i = 1; i <= n; i++)
    root[i] = st.set(root[i - 1], 0, n, xs.ord[i - 1], 1);

  while(q--) {
    int l, r, k; cin >> l >> r >> k;
    int u = root[l], v = root[r];
    int ql = 0, qr = n;
    while(ql + 1 < qr) {
      int mid = (ql + qr) / 2;
      if (int cnt = st.data[st.lc[v]] - st.data[st.lc[u]]; cnt <= k)
        k -= cnt, u = st.rc[u], v = st.rc[v], ql = mid;
      else
        u = st.lc[u], v = st.lc[v], qr = mid;
    }
    cout << xs.val[ql] << '\n';
  }

  return 0;
}
