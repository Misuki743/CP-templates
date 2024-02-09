#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "../default/t.cpp"
#include "../segtree/lazySegmentTree.cpp"
#include "../segtree/ultraLazySegmentTree.cpp"
#include "../misc/compression.cpp"
#include "../misc/areaOfUnionOfRectangles.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<array<int, 4>> rect(n);
  for(auto &[l, r, d, u] : rect)
    cin >> l >> d >> r >> u;

  cout << areaOfUnionOfRectangles<int, ll>(rect) << '\n';

  return 0;
}

