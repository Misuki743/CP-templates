#define PROBLEM "https://yukicoder.me/problems/no/1097"

#include "../default/t.cpp"
#include "../ds/doubling.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vll a(n);
  for(ll &x : a) cin >> x;

  vi to(n);
  for(int i = 0; i < n; i++)
    to[i] = (i + a[i]) % n;

  auto add = [](ll a, ll b) { return a + b; };
  doubling db(40, to, a, 0ll, add);

  int q; cin >> q;
  while(q--) {
    ll k; cin >> k;
    cout << db.jump(0, k).second << '\n';
  }

  return 0;
}
