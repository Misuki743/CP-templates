#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../default/t.cpp"
#include "../segtree/lichaoSegmentTree.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<array<ll, 2>> ab(n);
  for(auto &[a, b] : ab)
    cin >> a >> b;
  vector<array<ll, 3>> query(q);
  for(auto &[t, a, b] : query) {
    cin >> t >> a;
    if (t == 0)
      cin >> b;
  }

  vector<ll> pt;
  for(auto [t, a, b] : query)
    if (t == 1)
      pt.emplace_back(a);

  ranges::sort(pt);
  pt.resize(unique(pt.begin(), pt.end()) - pt.begin());
  for(auto &[t, a, b] : query)
    if (t == 1)
      a = ranges::lower_bound(pt, a) - pt.begin();

  lichaoSegmentTree<ll> st(bit_ceil((unsigned)q), pt);
  for(auto [a, b] : ab)
    st.insert(1, a, b);
  for(auto [t, a, b] : query) {
    if (t == 0)
      st.insert(1, a, b);
    else
      cout << st.query(a) << '\n';
  }

  return 0;
}
