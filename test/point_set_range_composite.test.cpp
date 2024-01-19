#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../segtree/segmentTree.cpp"

using line = array<mint, 2>;
line unit() { return line{1, 0}; }
line ope(const line &l, const line &r) {
  return {l[0] * r[0], l[1] * r[0] + r[1]};
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<line> a(n);
  for(auto &[c, d] : a)
    cin >> c >> d;

  segmentTree<line, unit, ope> st(a);
  while(q--) {
    int t, x, y, z; cin >> t >> x >> y >> z;
    if (t == 0) {
      st.set(x, line{y, z});
    } else {
      line l = st.query(x, y);
      cout << l[0] * z + l[1] << '\n';
    }
  }

  return 0;
}
