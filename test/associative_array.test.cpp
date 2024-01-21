#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include <ext/pb_ds/assoc_container.hpp>
#include "../default/t.cpp"
#include "../ds/hashTable.cpp"

gp_hash_table<ll, ll, custom_hash> m({}, {}, {}, {}, {1 << 20});

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int q; cin >> q;
  while(q--) {
    int t; cin >> t;
    ll k; cin >> k;
    if (t == 0) {
      ll v; cin >> v;
      m[k] = v;
    } else {
      cout << m[k] << '\n';
    }
  }

  return 0;
}
