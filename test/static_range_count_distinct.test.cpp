#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"

#include "../default/t.cpp"
#include "../ds/fenwickTree.cpp"
#include "../misc/compression.cpp"
#include "../misc/rangeCountDistinct.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a)
    cin >> x;
  vector<array<int, 2>> query(q);
  for(auto &[l, r] : query)
    cin >> l >> r;

  for(int x : rangeCountDistinct(a, query))
    cout << x << '\n';

  return 0;
}
