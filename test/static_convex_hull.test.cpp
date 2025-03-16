#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include "../default/t.cpp"
#include "../default/ttt.cpp"
#include "../geometry/point.cpp"
#include "../geometry/convex_hull.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<P> pt(n);
    for(auto &[x, y] : pt) cin >> x >> y;
    
    auto hull = convexHull(pt);
    cout << ssize(hull) << '\n';
    for(auto [x, y] : hull) cout << x << ' ' << y << '\n';
  }

  return 0;
}

