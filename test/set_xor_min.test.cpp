#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../default/t.cpp"
#include "../ds/binaryTrie.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  binaryTrie<29> tr(500000 * 30);

  int q; cin >> q;
  while(q--) {
    int t, x; cin >> t >> x;
    if (t == 0)
      tr.insert(x);
    else if (t == 1)
      tr.erase(x);
    else if (t == 2)
      cout << tr.queryMin(x) << '\n';
  }

  return 0;
}
