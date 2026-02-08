#define PROBLEM "https://yukicoder.me/problems/no/2895"

#include "../default/t.cpp"
#include "../linalg/xor_basis_bitset.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vll a(n);
  for(ll &x : a)
    cin >> x;

  vi id;
  xor_basis<60> B;
  for(int j = -1; ll x : a) {
    j++;
    bool pre = B.query(x).first;
    auto [ok, sol] = B.insert(x);
    if (ok) id.eb(x), assert(!pre);
    else {
      auto [ok2, sol2] = B.query(x);
      assert(ok2 and sol == sol2);
      vi tmp;
      for(int i = 0; i < 60; i++)
        if (sol[i])
          tmp.eb(i + 1);
      tmp.eb(j + 1);
      cout << ssize(tmp) << '\n';
      cout << tmp << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';

  return 0;
}
