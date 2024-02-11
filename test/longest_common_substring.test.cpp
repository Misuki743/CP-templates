#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include "../default/t.cpp"
#include "../string/suffixArray.cpp"
#include "../string/longestCommonSubstring.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  string s, t; cin >> s >> t;
  cout << longestCommonSubstring(s, t) << '\n';

  return 0;
}
