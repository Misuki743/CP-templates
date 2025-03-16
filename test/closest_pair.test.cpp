#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"

#include "../default/t.cpp"
#include "../default/ttt.cpp"
#include "../geometry/point.cpp"
#include "../geometry/closest_pair.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<P> pt(n);
    for(auto &[x, y] : pt) cin >> x >> y;
    
    auto [p, q] = closest(pt);
    int i = ranges::find(pt, p) - pt.begin();
    int j = 0;
    while(j == i or q != pt[j]) j++;
    cout << i << ' ' << j << '\n';
  }

  return 0;
}

