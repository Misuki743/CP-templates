#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../numtheory/mu.cpp"
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

int mu[1 << 15];

template<int32_t sz = 64>
void check_small() {
  if (sz == 0) return;
  check_small<max(sz - 1, 0)>();
  auto ls = linear_sieve<sz>();
  auto mu2 = mu_table<int>(ls);
  for(int i = 0; i < sz; i++)
    assert(mu[i] == mu2[i]);
}

template<int32_t sz = (1 << 15)>
void check_power() {
  if (sz == 0) return;
  check_power<max(sz >> 1, 0)>();
  auto ls = linear_sieve<sz>();
  auto mu2 = mu_table<int>(ls);
  for(int i = 0; i < sz; i++)
    assert(mu[i] == mu2[i]);
}

void a_plus_b() {
  int x, y; cin >> x >> y;
  cout << x + y << '\n';
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  for(int x = 1; x < (1 << 15); x++) {
    mu[x] = 1;
    for(auto [p, f] : factorize(x)) {
      if (f == 1) mu[x] = -mu[x];
      else mu[x] = 0;
    }
  }

  check_small();
  check_power();
  a_plus_b();

  return 0;
}
