#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../numtheory/phi_table.cpp"
#include "../numtheory/linear_sieve.cpp"

vc<pii> factorize(int x) {
  vc<pii> v;
  int x0 = x;
  for(int d = 2; d <= x0; d++) {
    if (x % d == 0) {
      int f = 0;
      while(x % d == 0)
        x /= d, f++;
      v.emplace_back(d, f);
    }
  }
  return v;
}

int phi[1 << 10];

template<int32_t sz = 64>
void check_small() {
  if (sz == 0) return;
  check_small<max(sz - 1, 0)>();
  auto ls = linear_sieve<sz>();
  auto phi2 = phi_table<int>(ls);
  for(int i = 0; i < sz; i++)
    assert(phi[i] == phi2[i]);
}

template<int32_t sz = (1 << 10)>
void check_power() {
  if (sz == 0) return;
  check_power<max(sz >> 1, 0)>();
  auto ls = linear_sieve<sz>();
  auto phi2 = phi_table<int>(ls);
  for(int i = 0; i < sz; i++)
    assert(phi[i] == phi2[i]);
}

void a_plus_b() {
  int x, y; cin >> x >> y;
  cout << x + y << '\n';
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  for(int x = 1; x < (1 << 10); x++)
    for(int y = 1; y <= x; y++)
      if (gcd(x, y) == 1)
        phi[x]++;

  check_small();
  check_power();
  a_plus_b();

  return 0;
}
