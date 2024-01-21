#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../default/t.cpp"
#include "../string/zFunc.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  string s; cin >> s;
  cout << zFunc(s) << '\n';

  return 0;
}
