#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../default/t.cpp"
#include "../numtheory/quotient_enumerate.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  ll n; cin >> n;
  auto tmp = quotient_floor_enumerate(n);
  cout << ssize(tmp) << '\n';
  for(auto [x, _, __] : tmp)
    cout << x << ' ';
  cout << '\n';

  return 0;
}
