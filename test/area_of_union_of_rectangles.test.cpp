#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "../default/t.cpp"
#include "../segtree/lazySegmentTree.cpp"
#include "../segtree/ultraLazySegmentTree.cpp"
#include "../actedmonoid/actedMonoid_addMinCnt.cpp"
#include "../ds_problem/area_of_union_of_rectangles.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<array<int, 4>> rect(n);
  for(auto &[l, d, r, u] : rect)
    cin >> l >> d >> r >> u;

  cout << area_of_union_of_rectangles<int, ll>(rect) << '\n';

  return 0;
}

