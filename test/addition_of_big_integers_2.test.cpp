#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_big_integers"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../misc/bigint.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    string a, b; cin >> a >> b;
    bigint<false> A(a), B(b);
    cout << A + B << '\n';
  }

  return 0;
}

