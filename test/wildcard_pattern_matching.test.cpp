#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../misc/wildcardPatternMatcing.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  string s, t; cin >> s >> t;
  for(int x : wildcardPatternMatching<mint>(s, t))
    cout << x;
  cout << '\n';

  return 0;
}
