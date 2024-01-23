#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../default/t.cpp"
#include "../string/Manacher.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  string s; cin >> s;
  cout << enumeratePalindrome(s) << '\n';

  return 0;
}
