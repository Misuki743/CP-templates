#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../default/t.cpp"
#include "../numtheory/floorCeilSum.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  ll n; cin >> n;
  auto tmp = calc_floor(n);
  cout << ssize(tmp) << '\n';
  for(auto [x, _, __] : tmp)
    cout << x << ' ';
  cout << '\n';

  return 0;
}
