#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include "../default/t.cpp"
#include "../numtheory/fastFactorize.cpp"
#include "../numtheory/primitiveRoot.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int q; cin >> q;
  while(q--) {
    ull x; cin >> x;
    cout << primitiveRoot(x) << '\n';
  }

  return 0;
}
