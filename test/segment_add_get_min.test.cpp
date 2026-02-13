#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../default/t.cpp"
#include "../segtree/lichaoSegmentTree.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<array<ll, 4>> c(n);
  for(auto &[l, r, a, b] : c)
    cin >> l >> r >> a >> b;
  vector<array<ll, 5>> query(q);
  for(auto &[t, x, y, z, w] : query) {
    cin >> t;
    if (t == 0)
      cin >> x >> y >> z >> w;
    else
      cin >> x;
  }

  vector<ll> xs;
  for(auto &[l, r, a, b] : c) {
    xs.emplace_back(l);
    xs.emplace_back(r);
  }
  for(auto &[t, x, y, z, w] : query) {
    if (t == 0) {
      xs.emplace_back(x);
      xs.emplace_back(y);
    } else {
      xs.emplace_back(x);
    }
  }
  ranges::sort(xs);
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  for(auto &[l, r, a, b] : c) {
    l = ranges::lower_bound(xs, l) - xs.begin();
    r = ranges::lower_bound(xs, r) - xs.begin();
  }
  for(auto &[t, x, y, z, w] : query) {
    if (t == 0) {
      x = ranges::lower_bound(xs, x) - xs.begin();
      y = ranges::lower_bound(xs, y) - xs.begin();
    } else {
      x = ranges::lower_bound(xs, x) - xs.begin();
    }
  }

  lichaoSegmentTree<ll> st(bit_ceil(xs.size()), xs);
  for(auto &[l, r, a, b] : c)
    st.insertRange(l, r, a, b);
  for(auto &[t, x, y, z, w] : query) {
    if (t == 0) {
      st.insertRange(x, y, z, w);
    } else {
      if (ll ans = st.query(x); ans == LLONG_MAX)
        cout << "INFINITY\n";
      else
        cout << ans << '\n';
    }
      
  }

  return 0;
}
