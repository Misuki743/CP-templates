#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include "../default/t.cpp"
#include "../graph/hungarian.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector a(n, vector<ll>(n));
  for(auto &v : a)
    for(ll &x : v)
      cin >> x;

  auto [cost, tob] = hungarian<ll, LLONG_MAX>(a);
  cout << cost << '\n';
  cout << tob << '\n';

  return 0;
}
